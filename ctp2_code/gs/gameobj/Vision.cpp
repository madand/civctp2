









#include "c3.h"
#include "Vision.h"
#include "XY_Coordinates.h"
#include "World.h"
#include "TiledMap.h"
#include "DynArr.h"
#include "SelItem.h"
#include "CivArchive.h"
#include "UnseenCellQuadTree.h"
#include "Army.h"
#include "Cell.h"
#include "CellUnitList.h"
#include "Player.h"
#include "network.h"
#include "net_info.h"

extern World *g_theWorld;
extern TiledMap *g_tiledMap;
extern SelectedItem *g_selected_item;
extern Player **g_player;



















Vision::Vision(sint32 owner, BOOL amOnScreen)
{
	sint32 x;
	MapPoint *size;
	m_owner = owner;
	m_amOnScreen = amOnScreen;

	size = g_theWorld->GetSize();
	m_array = new uint16*[size->x];
	m_width = size->x;
	m_height = size->y;
	m_xyConversion = (m_height - (2 * m_width)) / 2;
	m_isYwrap = g_theWorld->IsYwrap();
	
	for(x = 0; x < size->x; x++) {
		m_array[x] = new uint16[size->y];
		memset(m_array[x], 0, sizeof(uint16) * size->y);
	}
	m_unseenCells = new UnseenCellQuadTree(m_width, m_height, g_theWorld->IsYwrap());
}

Vision::~Vision()
{
	DeleteUnseenCells();
	if(m_unseenCells)
		delete m_unseenCells;

	if(m_array) {
		for(sint32 x = 0; x < m_width; x++) {
			if(m_array[x])
				delete [] m_array[x];
		}
		delete [] m_array;
	}
}


void Vision::Clear()
{
	for(sint32 x = 0; x < m_width; x++) {
		for(sint32 y = 0; y < m_height; y++) {
			m_array[x][y] = 0;
		}
	}
	

	if(m_unseenCells)
		delete m_unseenCells;
	m_unseenCells = new UnseenCellQuadTree(m_width, m_height, g_theWorld->IsYwrap());
}


void Vision::AddExplored(MapPoint pos, double radius)
{
	Convert(pos);
	FillCircle(pos.x, pos.y, radius, CIRCLE_OP_ADD);
}



void Vision::SetTheWholeWorldExplored()
{
    sint32 x, y;
    for (x=0; x<m_width; x++) { 
        for (y=0; y<m_height; y++) { 
            m_array[x][y] |= k_EXPLORED_BIT; 
        } 
    } 
}

void Vision::SetTheWholeWorldUnexplored()
{
	sint32 x, y;
	for(x = 0; x < m_width; x++) {
		for(y = 0; y < m_height; y++) {
			
			if(!(m_array[x][y] & k_VISIBLE_REFERENCE_MASK)) {
				m_array[x][y] = 0;
			}
		}
	}
}

void Vision::SetTheWholeWorldUnseen()
{
	
	sint32 x, y;
	for(x = 0; x < m_width; x++) {
		for(y = 0; y < m_height; y++) {
			m_array[x][y] &= k_EXPLORED_BIT;
		}
	}
}

sint32 g_fog_toggle; 


extern sint32 g_god;

BOOL Vision::IsExplored(MapPoint pos) const 
{
	  
    if (g_fog_toggle) { 
        return TRUE; 
    } 

	
	if (g_god) return TRUE;

	if(g_player[m_owner] && g_player[m_owner]->m_hasGlobalRadar)
		return TRUE;

	Convert(pos);
	return (m_array[pos.x][pos.y] & k_EXPLORED_BIT) ? TRUE : FALSE;
}

void Vision::AddVisible(MapPoint pos, double radius, BOOL &revealed_unexplored,
						DynamicArray<MapPoint> *removeadd)
{
	Convert(pos);
	m_revealedUnexplored = FALSE;
	FillCircle(pos.x, pos.y, radius, CIRCLE_OP_ADD, removeadd);
	if(m_revealedUnexplored)
		revealed_unexplored = TRUE;

	if(removeadd) {
		for(sint32 i = 0; i < removeadd->Num(); i++) {
			
			
			
			if(m_amOnScreen && g_tiledMap) {
				
				if (g_tiledMap->TileIsVisible(removeadd->Access(i).x, removeadd->Access(i).y))
					g_tiledMap->RedrawTile(&removeadd->Access(i));
			}
		}
	}
}

void Vision::RemoveVisible(MapPoint pos, double radius,
						   DynamicArray<MapPoint> *removeadd)
{
	Convert(pos);
	FillCircle(pos.x, pos.y, radius, CIRCLE_OP_SUBTRACT, removeadd);
}


void Vision::AddRadar(MapPoint pos, double radius)
{
	Convert(pos);
	FillCircle(pos.x, pos.y, radius, CIRCLE_OP_ADD_RADAR);
}

BOOL Vision::IsVisible(MapPoint pos) const 
{
    if (g_fog_toggle) { 
        return TRUE; 
    } 
	
	if (g_god) 
		return TRUE;

	
	if(g_player[m_owner] && g_player[m_owner]->m_hasGlobalRadar)
		return TRUE;

	Assert(pos.x >= 0 && pos.x < m_width &&
		   pos.y >= 0 && pos.y < m_height);
	Convert(pos);
	return ((m_array[pos.x][pos.y] & k_VISIBLE_REFERENCE_MASK) > 0);
}

BOOL Vision::GetLastSeen(const MapPoint &pos, UnseenCellCarton &ucell)
{
	
	if(g_god) return FALSE;

	
	if(g_player[m_owner] && g_player[m_owner]->m_hasGlobalRadar)
		return FALSE;

	
	
	
	return m_unseenCells->GetAt(pos, ucell);
}












void Vision::MergeMap(Vision *src)
{
	Cell *cell;
	sint32 i, n;
	

	Assert(m_width == src->m_width && m_height == src->m_height);
	Assert(m_owner != src->m_owner);

	sint32 x, y;
	UnseenCellCarton ucell;

	for(x = 0; x < m_width; x++) {
		for(y = 0; y < m_height; y++) {
			uint16 *myVersion = &m_array[x][y];
			uint16 *hisVersion = &src->m_array[x][y];
			MapPoint point(x, y);

			if(!(*hisVersion & k_EXPLORED_BIT))
				continue;

			if(*myVersion & k_EXPLORED_BIT) {
				
				if((*myVersion & k_VISIBLE_REFERENCE_MASK) > 0) {
					
					continue;
				}

				if((*hisVersion & k_VISIBLE_REFERENCE_MASK) > 0) {
					
					
					
					Unconvert(point);
					if(m_unseenCells->RemoveAt(point, ucell)) {
						delete ucell.m_unseenCell;
					}
					cell = g_theWorld->GetCell(point);
					n = cell->GetNumUnits();
					for(i = 0; i < n; i++) {
						if(cell->AccessUnit(i).GetVisibility() & (1 << src->m_owner)) {
							if(cell->AccessUnit(i).GetVisibilityClass() & 1) {
								cell->AccessUnit(i).ForceVisibleDuration(m_owner, 1);
							}
						}
					}
					if(cell->GetCity().m_id != (0) ||
					   cell->GetNumImprovements() > 0) {
						if(cell->GetCity().m_id != 0)
							cell->GetCity().SetVisible(m_owner);

						
						ucell.m_unseenCell = new UnseenCell(point);
						m_unseenCells->Insert(ucell);
					}
				}
				
			} else {
				

				*myVersion |= k_EXPLORED_BIT;
				Unconvert(point);

				
				cell = g_theWorld->GetCell(point);
				n = cell->GetNumUnits();
				for(i = 0; i < n; i++) {
					if(cell->AccessUnit(i).GetVisibility() & (1 << src->m_owner)) {
						if(cell->AccessUnit(i).GetVisibilityClass() & 1) {
							cell->AccessUnit(i).ForceVisibleDuration(m_owner, 1);
						}
					}
				}

				if(cell->GetCity().m_id != (0) && 
				   cell->GetCity().GetVisibility() & (1 << src->m_owner)) {
					cell->GetCity().SetVisible(m_owner);
				}
				
				if((*hisVersion & k_VISIBLE_REFERENCE_MASK) == 0) {
					
					if(src->m_unseenCells->GetAt(point, ucell)) {
						UnseenCellCarton newUnseen(
							new UnseenCell(ucell.m_unseenCell));
						
						m_unseenCells->Insert(newUnseen);
					} 
				} 
			}
		}
	}
}


BOOL Vision::MergePoint(sint32 x, sint32 y)
{
	uint16 *myVersion = &m_array[x][y];
	uint16 *hisVersion = &m_mergeFrom->m_array[x][y];
	MapPoint point(x, y);
	UnseenCellCarton ucell;
	
	if(!(*hisVersion & k_EXPLORED_BIT))
		return FALSE;
	
	if(*myVersion & k_EXPLORED_BIT) {
		
		if((*myVersion & k_VISIBLE_REFERENCE_MASK) > 0) {
			
			return FALSE;
		}
		
		if((*hisVersion & k_VISIBLE_REFERENCE_MASK) > 0) {
			
			
			
			Unconvert(point);
			if(m_unseenCells->RemoveAt(point, ucell)) {
				delete ucell.m_unseenCell;
			}
			return TRUE;
		}
		
	} else {
		
		
		*myVersion |= k_EXPLORED_BIT;
		
		if((*hisVersion & k_VISIBLE_REFERENCE_MASK) == 0) {
			
			Unconvert(point);
			if(m_mergeFrom->m_unseenCells->GetAt(point, ucell)) {
				UnseenCellCarton newUnseen(
					new UnseenCell(ucell.m_unseenCell));
				
				m_unseenCells->Insert(newUnseen);
				return TRUE;
			} 
		} 
		return TRUE;
	}
	return FALSE;
}

#define NEWFILLCIRCLE
#ifdef NEWFILLCIRCLE
void Vision::FillCircle(sint32 xc, sint32 yc,
						double r,
						CIRCLE_OP op,
						DynamicArray<MapPoint> *removeadd)
{
	
	
	r += 0.5;
	sint32 rsq = sint32(r * r);
	sint32 x, y;
	BOOL incircle;
	sint32 dx, dy;
	MapPoint center(xc, yc);

	
	for(x = center.x + sint32(r); x >= center.x; x--) {
		incircle = FALSE;
		
		for(y = center.y + sint32(r); y >= center.y; y--) {
			dx = x - center.x;
			dy = y - center.y;
			if(incircle || ((dx*dx) + (dy*dy) <= rsq)) { 
				incircle = TRUE;
				
				
				MapPoint cpos;
				cpos.Set(x,y);
				
				
				
				if(CheckWrap(cpos, center)) {
					DoFillCircleOp(cpos, op, removeadd);
				}

				if(dx != 0) {
					cpos.Set(center.x - dx, y);
					if(CheckWrap(cpos, center)) {
						DoFillCircleOp(cpos, op, removeadd);
					}
				}

				if(dy != 0) {
					cpos.Set(x, center.y - dy);
					if(CheckWrap(cpos, center)) {
						DoFillCircleOp(cpos, op, removeadd);
					}

					if(dx != 0) {
						cpos.Set(center.x - dx, center.y - dy);
						if(CheckWrap(cpos, center)) {
							DoFillCircleOp(cpos, op, removeadd);
						}
					}
				}
			}
		}
	}
}

BOOL Vision::CheckWrap(MapPoint &pos, const MapPoint &center)
{
	
	Assert(center.x >= 0);
	Assert(center.x < m_width);
	Assert(center.y >= 0);
	Assert(center.y < m_height);

	if(center.x < 0 || center.x >= m_width || center.y < 0 || center.y >= m_height)
		return FALSE;

	
	
	
	
	MapPoint isocenter(center);
	Unconvert(isocenter);
	MapPoint delta;
	delta.x = pos.x - center.x;
	delta.y = pos.y - center.y;
	delta.y -= delta.x;

	if((isocenter.y + delta.y) < 0) {
		
		if(!m_isYwrap)
			return FALSE;
		
		
		pos.x -= m_xyConversion;
		pos.y -= m_xyConversion;
	} else if(isocenter.y + delta.y >= m_height) {
		
		if(!m_isYwrap)
			return FALSE;
		pos.x += m_xyConversion;
		pos.y += m_xyConversion;
	}
		
	
	if(!g_theWorld->IsXwrap()) {
		sint16 centerLeftEdge = (m_width - (isocenter.y / 2)) % m_width;
		MapPoint checkpos(isocenter.x + delta.x, isocenter.y + delta.y);
		sint16 posLeftEdge = (m_width - (checkpos.y/2)) % m_width;

		if((isocenter.x >= centerLeftEdge) &&
		   ((checkpos.x) < posLeftEdge))
			return FALSE;

		sint16 centerRightEdge = (centerLeftEdge + m_width) % m_width;
		sint16 posRightEdge = (posLeftEdge + m_width) % m_width;
		if(isocenter.x < centerRightEdge &&
		   checkpos.x >= posRightEdge)
			return FALSE;
	}

	if(pos.x < 0) {
		
		pos.x += m_width;
		pos.y = (pos.y + m_width) % m_height;
	} else if(pos.x >= m_width) {
		
		pos.x -= m_width;
		pos.y = pos.y - m_width;
		if(pos.y < 0)
			pos.y += m_height;
	}

	if(pos.y >= m_height) {
		
		pos.y -= m_height;
	}
	if(pos.y < 0) {
		
		pos.y += m_height;
	}

	Assert(pos.x >= 0);
	Assert(pos.x < m_width);
	Assert(pos.y >= 0);
	Assert(pos.y < m_height);
	if(pos.x < 0 || pos.x >= m_width || pos.y < 0 || pos.y >= m_height)
		return FALSE;
	return TRUE;
}


sint32 shut_up_you_bastard;

void Vision::DoFillCircleOp(const MapPoint &pos, CIRCLE_OP op, 
							DynamicArray<MapPoint> *removeadd)
{
	MapPoint iso;
	BOOL redraw = FALSE;
	uint16 *entry = &m_array[pos.x][pos.y];
	switch(op) {
		case CIRCLE_OP_ADD:
			if(!((*entry) & k_EXPLORED_BIT)) {
				iso = pos;
				Unconvert(iso);
				redraw = TRUE;
				m_revealedUnexplored = TRUE;
			} else if (((*entry) & k_VISIBLE_REFERENCE_MASK) == 0) {
				iso = pos;
				Unconvert(iso);
				redraw = TRUE;
				UnseenCellCarton ucell;
				if(m_unseenCells->RemoveAt(iso, ucell)) {
					delete ucell.m_unseenCell;
				}
			}
			*entry = (*entry + 1) | k_EXPLORED_BIT;
			if(redraw && removeadd) {
				if(removeadd->Del(iso)) {
					
					redraw = FALSE;
				} else {
					removeadd->Insert(iso);
					redraw = FALSE;
				}
			}
			break;
		case CIRCLE_OP_SUBTRACT:

			if(g_player[m_owner] && g_player[m_owner]->GetPlayerType() == PLAYER_TYPE_HUMAN) {

                
				    Assert(((*entry) & k_VISIBLE_REFERENCE_MASK) != 0);
				
			}
			*entry = *entry - 1;
			if(((*entry) & k_VISIBLE_REFERENCE_MASK) == 0) {
				iso = pos;
				Unconvert(iso);

				
				
				Cell *cell = g_theWorld->GetCell(iso);
				if(cell->GetNumImprovements() > 0 || 
				   (cell->GetCity().IsValid() && cell->GetCity().GetOwner() != m_owner)) {
					AddUnseen(iso);
				}

				if(removeadd) {
					
					removeadd->Insert(iso);
					redraw = FALSE;
				} else {
					redraw = TRUE;
				}
			}
			break;
		case CIRCLE_OP_ADD_RADAR:
		{
			static CellUnitList army;
			army.Clear();
			iso = pos;
			Unconvert(iso);
			g_theWorld->GetArmy(iso, army);
			sint32 i, n = army.Num();
			for(i = 0; i < n; i++) {
				army[i].SetRadar(m_owner);
			}
			break;
		}
		case CIRCLE_OP_MERGE:
			if(MergePoint(pos.x, pos.y)) {
				if(g_selected_item->GetVisiblePlayer() == m_owner) {
					g_tiledMap->GetLocalVision()->ModifyPoint(this, pos.x, pos.y);
				}
				iso = pos;
				Unconvert(iso);
				redraw = TRUE;
			}
			break;
		default:
			Assert(FALSE);
			break;
	}
	if(g_tiledMap && redraw && m_amOnScreen) {
		g_tiledMap->RedrawTile(&iso);
	}
}
#endif
						

void Vision::AddUnseen(const MapPoint &point)
{
	if(!IsExplored(point)) {
		return;
	}

	if(g_player[m_owner] && g_player[m_owner]->m_hasGlobalRadar) {
		return;
	}

	if(!IsVisible(point)) {
		UnseenCellCarton alreadyUnseen;
		if(m_unseenCells->GetAt(point, alreadyUnseen)) {
			return;
		}
		if(g_network.IsHost()) {
			g_network.Enqueue(new NetInfo(NET_INFO_CODE_ADD_UNSEEN,
										  m_owner, g_network.PackedPos(point)));
		}

		UnseenCellCarton unseen(new UnseenCell(point));
		m_unseenCells->Insert(unseen);
	}
}
void Vision::Copy(const Vision *copy)
{
	Assert(m_width == copy->m_width && m_height == copy->m_height);
	if(m_width != copy->m_width || m_height != copy->m_height) {
		return;
	}
	m_owner = copy->m_owner;
	for(sint32 x = 0; x < m_width; x++) {
		memcpy(m_array[x], copy->m_array[x], m_height * sizeof(uint16));
	}
	
	
	

	m_unseenCells->Clear();
	DynamicArray<UnseenCellCarton> array;
	copy->m_unseenCells->BuildList(array);
	sint32 i, n = array.Num();
	for(i = 0; i < n; i++) {
		UnseenCellCarton newUnseen(new UnseenCell(array[i].m_unseenCell));
		m_unseenCells->Insert(newUnseen);
	}
}
void Vision::Serialize(CivArchive &archive)
{
    CHECKSERIALIZE

	if(archive.IsStoring()) {
		archive.StoreChunk((uint8 *)&m_width, ((uint8 *)&m_amOnScreen)+sizeof(m_amOnScreen));

		for(sint32 x = 0; x < m_width; x++) {
			archive.Store((uint8 *)m_array[x], sizeof(m_array[0][0]) * m_height) ;



		}
		DynamicArray<UnseenCellCarton> array;
		m_unseenCells->BuildList(array);
		sint32 i, n = array.Num();
		archive << n;
		for(i = 0; i < n; i++) {
			array[i].m_unseenCell->Serialize(archive);
		}
	} else {
		archive.LoadChunk((uint8 *)&m_width, ((uint8 *)&m_amOnScreen)+sizeof(m_amOnScreen));


		if(m_array) {
			for(sint32 x = 0; x < m_width; x++) {
				if(m_array[x])
					delete [] m_array[x];
			}
			delete [] m_array;
		}

		m_array = new uint16*[m_width];
		for(sint32 x = 0; x < m_width; x++) {
			m_array[x] = new uint16[m_height];
			archive.Load((uint8 *)m_array[x], sizeof(m_array[0][0]) * m_height) ;



		}
		sint32 i, n;
		archive >> n;
		for(i = 0; i < n; i++) {
			UnseenCell *ucell = new UnseenCell(archive);
			UnseenCellCarton uc(ucell);
			m_unseenCells->Insert(uc);
		}
	}
}


void Vision::CopyCircle(Vision *src, const MapPoint &center, sint32 radius)
{
	m_mergeFrom = src;
	MapPoint pos = center;
	Convert(pos);
	FillCircle(pos.x, pos.y, (double)radius,
			   CIRCLE_OP_MERGE);
}






void Vision::ModifyPoint(Vision *src, sint32 x, sint32 y)
{
	UnseenCellCarton ucell, ucell2;
	MapPoint pnt(x,y);

	if(m_array[x][y] & k_EXPLORED_BIT) {
		if(m_array[x][y] & k_VISIBLE_REFERENCE_MASK) {
			
			return;
		} else {
			if(m_unseenCells->RemoveAt(pnt, ucell2)) {
				delete ucell2.m_unseenCell;
			}
			if(src->m_array[x][y] & k_VISIBLE_REFERENCE_MASK) {
				
			} else {
				
				if(src->m_unseenCells->GetAt(pnt, ucell)) {
					ucell2.m_unseenCell = new UnseenCell(ucell.m_unseenCell);
					m_unseenCells->Insert(ucell2);
				}
			}
		}
	} else {
		
		if(src->m_array[x][y] & k_EXPLORED_BIT) {
			
			m_array[x][y] |= k_EXPLORED_BIT;
			if(src->m_unseenCells->GetAt(pnt, ucell)) {
				
				ucell2.m_unseenCell = new UnseenCell(ucell.m_unseenCell);
				m_unseenCells->Insert(ucell2);
			}
		}
	}
}

void Vision::DeleteUnseenCells()
{
	static DynamicArray<UnseenCellCarton> array;
	array.Clear();
	m_unseenCells->BuildList(array, 0xffffffff);

	sint32 i;
	for(i = 0; i < array.Num(); i++) {
		delete array[i].m_unseenCell;
	}
}

void Vision::AddUnseen(UnseenCell *ucell)
{
	UnseenCellCarton unseen(ucell);
	m_unseenCells->Insert(unseen);
}

void Vision::GetUnseenCellList(DynamicArray<UnseenCellCarton> &array)
{
	array.Clear();
	m_unseenCells->BuildList(array);
}

void Vision::ClearUnseen()
{
	m_unseenCells->Clear();
}
