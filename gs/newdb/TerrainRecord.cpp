
/*
 * DO NOT EDIT THIS FILE!
 * It is generated automatically by ctpdb
 */
#include "c3.h"
#include "c3errors.h"
#include "TerrainRecord.h"
#include "DBLexer.h"
#include "DBTokens.h"
#include "CTPDatabase.h"
#include "StrDB.h"
#include "BitArray.h"

#include "IconRecord.h"
#include "AdvanceRecord.h"
#include "AdvanceRecord.h"
#include "ResourceRecord.h"

CTPDatabase<TerrainRecord> *g_theTerrainDB = NULL;

TerrainRecord::Init()
{
    m_flags0 = 0;
    m_Icon = 0x7fffffff;
    m_AddAdvance = 0x7fffffff;
    m_RemoveAdvance = 0x7fffffff;
    memset(&m_TransformAddValue, 0, sizeof(m_TransformAddValue));
    memset(&m_TransformRemoveValue, 0, sizeof(m_TransformRemoveValue));
    memset((uint8*)&m_EnvBase, 0, sizeof(m_EnvBase));
    memset(&m_EnvCityValue, 0, sizeof(m_EnvCityValue));
    memset(&m_EnvRiverValue, 0, sizeof(m_EnvRiverValue));
    memset(m_Resources, 0, sizeof(m_Resources));
    m_numResources = 0;
    m_MovementType = 0;
    m_InternalType = 0;
    m_TilesetIndex = 0;
}

TerrainRecord::~TerrainRecord()
{
	int index = 0;
}

void TerrainRecord::operator=(const TerrainRecord & rval)
{
	int index = 0;
	m_index = rval.m_index;
	m_Icon = rval.m_Icon; 

	m_AddAdvance = rval.m_AddAdvance; 

	m_RemoveAdvance = rval.m_RemoveAdvance; 

	m_flags0 = rval.m_flags0; 
	m_flags0 = rval.m_flags0; 
	m_flags0 = rval.m_flags0; 
		m_TransformAddValue = rval.m_TransformAddValue; 

	m_flags0 = rval.m_flags0; 
		m_TransformRemoveValue = rval.m_TransformRemoveValue; 

	m_EnvBase = rval.m_EnvBase; 

	m_flags0 = rval.m_flags0; 
		m_EnvCityValue = rval.m_EnvCityValue; 

	m_flags0 = rval.m_flags0; 
		m_EnvRiverValue = rval.m_EnvRiverValue; 

	// copy fixed sized array Resources[] 
 		memcpy(m_Resources, rval.m_Resources, sizeof(sint32)*rval.m_numResources); 

	m_flags0 = rval.m_flags0; 
	m_MovementType = rval.m_MovementType; 

	m_InternalType = rval.m_InternalType; 

	m_TilesetIndex = rval.m_TilesetIndex; 

}

char *g_Terrain_Tokens[] =
{
    "Icon",
    "AddAdvance",
    "RemoveAdvance",
    "CanDie",
    "GLHidden",
    "TransformAdd",
    "TransformAddValue",
    "TransformRemove",
    "TransformRemoveValue",
    "EnvBase",
    "EnvCity",
    "EnvCityValue",
    "EnvRiver",
    "EnvRiverValue",
    "Resources",
    "NoIndex",
    "MovementType",
    "InternalType",
    "TilesetIndex",
};

TerrainRecordAccessorInfo g_TerrainRecord_Accessors[] = 
{
    {TerrainRecord::GetIconIndex, NULL, NULL, NULL, NULL },
    {TerrainRecord::GetAddAdvanceIndex, NULL, NULL, NULL, NULL },
    {TerrainRecord::GetRemoveAdvanceIndex, NULL, NULL, NULL, NULL },
    { NULL, TerrainRecord::GetCanDie, NULL, NULL, NULL },
    { NULL, TerrainRecord::GetGLHidden, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL, NULL}, /* TransformAdd */
    { NULL, NULL, NULL, NULL, NULL}, /* TransformAdd */
    { NULL, NULL, NULL, NULL, NULL}, /* TransformRemove */
    { NULL, NULL, NULL, NULL, NULL}, /* TransformRemove */
    { NULL, NULL, NULL, NULL, NULL}, /* EnvBase */
    { NULL, NULL, NULL, NULL, NULL}, /* EnvCity */
    { NULL, NULL, NULL, NULL, NULL}, /* EnvCity */
    { NULL, NULL, NULL, NULL, NULL}, /* EnvRiver */
    { NULL, NULL, NULL, NULL, NULL}, /* EnvRiver */
    { NULL, NULL, NULL, NULL, NULL}, /* Resources (array) */
    { NULL, TerrainRecord::GetNoIndex, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL, NULL}, /* MovementType */
    { NULL, NULL, NULL, NULL, NULL}, /* InternalType */
    { TerrainRecord::GetTilesetIndex, NULL, NULL, NULL, NULL },
};

#define k_Token_Terrain_Icon                     ((k_Token_Custom_Base) + 0)
#define k_Token_Terrain_AddAdvance               ((k_Token_Custom_Base) + 1)
#define k_Token_Terrain_RemoveAdvance            ((k_Token_Custom_Base) + 2)
#define k_Token_Terrain_CanDie                   ((k_Token_Custom_Base) + 3)
#define k_Token_Terrain_GLHidden                 ((k_Token_Custom_Base) + 4)
#define k_Token_Terrain_TransformAdd             ((k_Token_Custom_Base) + 5)
#define k_Token_Terrain_TransformAdd_Value       ((k_Token_Custom_Base) + 6)
#define k_Token_Terrain_TransformRemove          ((k_Token_Custom_Base) + 7)
#define k_Token_Terrain_TransformRemove_Value    ((k_Token_Custom_Base) + 8)
#define k_Token_Terrain_EnvBase                  ((k_Token_Custom_Base) + 9)
#define k_Token_Terrain_EnvCity                  ((k_Token_Custom_Base) + 10)
#define k_Token_Terrain_EnvCity_Value            ((k_Token_Custom_Base) + 11)
#define k_Token_Terrain_EnvRiver                 ((k_Token_Custom_Base) + 12)
#define k_Token_Terrain_EnvRiver_Value           ((k_Token_Custom_Base) + 13)
#define k_Token_Terrain_Resources                ((k_Token_Custom_Base) + 14)
#define k_Token_Terrain_NoIndex                  ((k_Token_Custom_Base) + 15)
#define k_Token_Terrain_MovementType             ((k_Token_Custom_Base) + 16)
#define k_Token_Terrain_InternalType             ((k_Token_Custom_Base) + 17)
#define k_Token_Terrain_TilesetIndex             ((k_Token_Custom_Base) + 18)
#define k_Token_Terrain_Max                      ((k_Token_Custom_Base) + 19)


static BitArray s_ParsedTokens(19);
void TerrainRecord::CheckRequiredFields(DBLexer *lex)
{
    // Ick.
    if(!s_ParsedTokens.Bit(k_Token_Terrain_EnvBase - k_Token_Custom_Base)) {
        DBERROR(("Warning: required field EnvBase missing"));
    }
    if(!s_ParsedTokens.Bit(k_Token_Terrain_TilesetIndex - k_Token_Custom_Base)) {
        DBERROR(("Warning: required field TilesetIndex missing"));
    }
}
    
sint32 TerrainRecord::Parse(DBLexer *lex)
{
    bool done = false;
    sint32 result = 0;
    sint32 tok;
    DBPARSE_ERROR err = DBPARSE_OK;
    s_ParsedTokens.Clear();
    lex->SetTokens(g_Terrain_Tokens, k_Token_Terrain_Max);
    tok = lex->GetToken();
    if(tok != k_Token_Name) {
        DBERROR(("Record does not start with name"));
        return 0;
    }
    if(!g_theStringDB->GetStringID(lex->GetTokenText(), m_name)) {
        g_theStringDB->InsertStr(lex->GetTokenText(), lex->GetTokenText());
        if(!g_theStringDB->GetStringID(lex->GetTokenText(), m_name))
            SetTextName(lex->GetTokenText());
    }

    tok = lex->GetToken();
    if(tok != k_Token_OpenBrace) {
        DBERROR(("Missing open brace"));
        return 0;
    }

    while(!done) {
        tok = lex->GetToken();
        if(tok >= k_Token_Custom_Base && tok < k_Token_Terrain_Max) { 
            s_ParsedTokens.SetBit(tok - k_Token_Custom_Base);
        }
        switch(tok) {
            case k_Token_Terrain_Icon:
                if(!g_theIconDB->GetRecordFromLexer(lex, m_Icon, err)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_AddAdvance:
                if(!g_theAdvanceDB->GetRecordFromLexer(lex, m_AddAdvance, err)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_RemoveAdvance:
                if(!g_theAdvanceDB->GetRecordFromLexer(lex, m_RemoveAdvance, err)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_CanDie:
                m_flags0 |= k_Terrain_CanDie_Bit;
                break;
            case k_Token_Terrain_GLHidden:
                m_flags0 |= k_Terrain_GLHidden_Bit;
                break;
            case k_Token_Terrain_TransformAdd:
                m_flags0 |= k_Terrain_TransformAdd_Bit;
                if(!m_TransformAddValue.Parse(lex)) {
                    DBERROR(("Expected struct"));
                    done = true; break;
                }
                break;
            case k_Token_Terrain_TransformRemove:
                m_flags0 |= k_Terrain_TransformRemove_Bit;
                if(!m_TransformRemoveValue.Parse(lex)) {
                    DBERROR(("Expected struct"));
                    done = true; break;
                }
                break;
            case k_Token_Terrain_EnvBase:
                if(!m_EnvBase.Parse(lex)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_EnvCity:
                m_flags0 |= k_Terrain_EnvCity_Bit;
                if(!m_EnvCityValue.Parse(lex)) {
                    DBERROR(("Expected struct"));
                    done = true; break;
                }
                break;
            case k_Token_Terrain_EnvRiver:
                m_flags0 |= k_Terrain_EnvRiver_Bit;
                if(!m_EnvRiverValue.Parse(lex)) {
                    DBERROR(("Expected struct"));
                    done = true; break;
                }
                break;
            case k_Token_Terrain_Resources:
                if(!g_theResourceDB->ParseRecordInArray(lex, (sint32 *)m_Resources, &m_numResources, k_MAX_Resources, err)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_NoIndex:
                m_flags0 |= k_Terrain_NoIndex_Bit;
                break;
            case k_Token_Terrain_MovementType:
                if(!ParseMovementTypeBit(lex)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_InternalType:
                if(!ParseInternalTypeBit(lex)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_TilesetIndex:
                if(!lex->GetIntAssignment(m_TilesetIndex)) {
                    DBERROR(("Expected integer"));
                    done = true; break;
                }
                break;
            case k_Token_CloseBrace:
                done = true;
                result = 1;
                break;
            default:
                DBERROR(("Unknown token"));
                done = true;
                break;
        }
    }
    CheckRequiredFields(lex);
    lex->RestoreTokens();
    return result;
}

void TerrainRecord::ResolveDBReferences()
{
    if(m_Icon & 0x80000000) {
        sint32 id = m_Icon & 0x7fffffff;
        if(!g_theIconDB->GetNamedItem(id, m_Icon)) {
            c3errors_ErrorDialog("DB", "%s not found in Icon database", g_theStringDB->GetNameStr(id));
        }
    } else if(m_Icon == 0x7fffffff) {
        m_Icon = -1;
    }
    if(m_AddAdvance & 0x80000000) {
        sint32 id = m_AddAdvance & 0x7fffffff;
        if(!g_theAdvanceDB->GetNamedItem(id, m_AddAdvance)) {
            c3errors_ErrorDialog("DB", "%s not found in Advance database", g_theStringDB->GetNameStr(id));
        }
    } else if(m_AddAdvance == 0x7fffffff) {
        m_AddAdvance = -1;
    }
    if(m_RemoveAdvance & 0x80000000) {
        sint32 id = m_RemoveAdvance & 0x7fffffff;
        if(!g_theAdvanceDB->GetNamedItem(id, m_RemoveAdvance)) {
            c3errors_ErrorDialog("DB", "%s not found in Advance database", g_theStringDB->GetNameStr(id));
        }
    } else if(m_RemoveAdvance == 0x7fffffff) {
        m_RemoveAdvance = -1;
    }
    m_TransformAddValue.ResolveDBReferences();
    m_TransformRemoveValue.ResolveDBReferences();
    m_EnvBase.ResolveDBReferences();
    m_EnvCityValue.ResolveDBReferences();
    m_EnvRiverValue.ResolveDBReferences();
    {
        sint32 i;
        for(i = 0; i < m_numResources; i++) {
            if(m_Resources[i] & 0x80000000) {
                sint32 id = m_Resources[i] & 0x7fffffff;
                if(!g_theResourceDB->GetNamedItem(id, m_Resources[i])) {
                    c3errors_ErrorDialog("DB", "%s not found in Resource database", g_theStringDB->GetNameStr(id));
                }
            } else if(m_Resources[i] == 0x7fffffff){
                m_Resources[i] = -1;
            }
        }
    }
}
/*
 * Member class Parsers
 * (DO NOT EDIT!  Automatically generated file)
 */
TerrainRecord::TransformData::TransformData()
{
    m_Time = 0;
    m_Materials = 0;
}
TerrainRecord::TransformData::~TransformData()
{
}
void TerrainRecord::TransformData::operator=(const TransformData & rval)
{
	m_Time = rval.m_Time; 

	m_Materials = rval.m_Materials; 

}
static char *s_Terrain_TransformData_Tokens[] = {
    "Time",
    "Materials",
};
#define k_Token_Terrain_TransformData_Time       ((k_Token_Custom_Base) + 0)
#define k_Token_Terrain_TransformData_Materials  ((k_Token_Custom_Base) + 1)
#define k_Token_Terrain_TransformData_Max ((k_Token_Custom_Base) + 2)
sint32 TerrainRecord::TransformData::ParseSequential(DBLexer *lex)
{
    DBPARSE_ERROR err = DBPARSE_OK;
    if(!lex->GetIntAssignment(m_Time)) {
        DBERROR(("Expected integer"));
        return 0;
    }
    if(!lex->GetIntAssignment(m_Materials)) {
        DBERROR(("Expected integer"));
        return 0;
    }
    return 1;
}
sint32 TerrainRecord::TransformData::Parse(DBLexer *lex)
{
    bool done = false;
    sint32 tok;
    sint32 result = 0;
    DBPARSE_ERROR err = DBPARSE_OK;
    tok = lex->PeekAhead();
    if(tok != k_Token_OpenBrace) {
        if(ParseSequential(lex)) {
            return 1;
        }
        DBERROR(("Expected open brace for TransformData"));
        return 0;
    }
    tok = lex->GetToken();
    lex->SetTokens(s_Terrain_TransformData_Tokens, k_Token_Terrain_TransformData_Max);
    while(!done) {
        tok = lex->GetToken();
        switch(tok) {
            case k_Token_Terrain_TransformData_Time:
                if(!lex->GetIntAssignment(m_Time)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_TransformData_Materials:
                if(!lex->GetIntAssignment(m_Materials)) {
                    done = true; break;
                }
                break;
            case k_Token_CloseBrace:
                done = true;
                result = 1;
                break;
            default:
                Assert(FALSE);
                done = true;
                break;
        }
    }
    lex->RestoreTokens();
    return result;
}

sint32 TerrainRecord::TransformData::ParseInArray(DBLexer *lex, TransformData **array, sint32 *numElements)
{
    if(*numElements > 0) {
        TransformData *oldArray = *array;
        *array = new TransformData[(*numElements) + 1];
        for (int i=0; i < (*numElements); i++) 
             (*array)[i] = oldArray[i];
        delete [] oldArray;
    } else {
        *array = new TransformData[1];
    }
    (*array)[*numElements].Parse(lex);
    *numElements += 1;
    return 1;
}
sint32 TerrainRecord::TransformData::ParseInArray(DBLexer *lex, TransformData *array, sint32 *numElements, sint32 maxSize)
{
    if(*numElements >= maxSize) {
        return 0;
    }
    array[*numElements].Parse(lex);
    *numElements += 1;
    return 1;
}
void TerrainRecord::TransformData::ResolveDBReferences()
{
}
TerrainRecord::Modifiers::Modifiers()
{
    m_flags0 = 0;
    m_Score = 0;
    m_Gold = 0;
    m_DeadGold = 0;
    m_Food = 0;
    m_Shield = 0;
    m_MovementValue = 0;
    m_Freight = 0;
    m_Materials = 0;
    m_Time = 0;
    m_Defense = 0.000000;
    m_DeadFood = 0;
    m_DeadShield = 0;
}
TerrainRecord::Modifiers::~Modifiers()
{
}
void TerrainRecord::Modifiers::operator=(const Modifiers & rval)
{
	m_Score = rval.m_Score; 

	m_Gold = rval.m_Gold; 

	m_DeadGold = rval.m_DeadGold; 

	m_Food = rval.m_Food; 

	m_Shield = rval.m_Shield; 

	m_flags0 = rval.m_flags0; 
		m_MovementValue = rval.m_MovementValue; 

	m_Freight = rval.m_Freight; 

	m_Materials = rval.m_Materials; 

	m_Time = rval.m_Time; 

	m_Defense = rval.m_Defense; 

	m_DeadFood = rval.m_DeadFood; 

	m_DeadShield = rval.m_DeadShield; 

}
static char *s_Terrain_Modifiers_Tokens[] = {
    "Score",
    "Gold",
    "DeadGold",
    "Food",
    "Shield",
    "Movement",
    "Freight",
    "Materials",
    "Time",
    "Defense",
    "DeadFood",
    "DeadShield",
};
#define k_Token_Terrain_Modifiers_Score          ((k_Token_Custom_Base) + 0)
#define k_Token_Terrain_Modifiers_Gold           ((k_Token_Custom_Base) + 1)
#define k_Token_Terrain_Modifiers_DeadGold       ((k_Token_Custom_Base) + 2)
#define k_Token_Terrain_Modifiers_Food           ((k_Token_Custom_Base) + 3)
#define k_Token_Terrain_Modifiers_Shield         ((k_Token_Custom_Base) + 4)
#define k_Token_Terrain_Modifiers_Movement       ((k_Token_Custom_Base) + 5)
#define k_Token_Terrain_Modifiers_Freight        ((k_Token_Custom_Base) + 6)
#define k_Token_Terrain_Modifiers_Materials      ((k_Token_Custom_Base) + 7)
#define k_Token_Terrain_Modifiers_Time           ((k_Token_Custom_Base) + 8)
#define k_Token_Terrain_Modifiers_Defense        ((k_Token_Custom_Base) + 9)
#define k_Token_Terrain_Modifiers_DeadFood       ((k_Token_Custom_Base) + 10)
#define k_Token_Terrain_Modifiers_DeadShield     ((k_Token_Custom_Base) + 11)
#define k_Token_Terrain_Modifiers_Max ((k_Token_Custom_Base) + 12)
sint32 TerrainRecord::Modifiers::Parse(DBLexer *lex)
{
    bool done = false;
    sint32 tok;
    sint32 result = 0;
    DBPARSE_ERROR err = DBPARSE_OK;
    tok = lex->PeekAhead();
    if(tok != k_Token_OpenBrace) {
        DBERROR(("Expected open brace for Modifiers"));
        return 0;
    }
    tok = lex->GetToken();
    lex->SetTokens(s_Terrain_Modifiers_Tokens, k_Token_Terrain_Modifiers_Max);
    while(!done) {
        tok = lex->GetToken();
        switch(tok) {
            case k_Token_Terrain_Modifiers_Score:
                if(!lex->GetIntAssignment(m_Score)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_Modifiers_Gold:
                if(!lex->GetIntAssignment(m_Gold)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_Modifiers_DeadGold:
                if(!lex->GetIntAssignment(m_DeadGold)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_Modifiers_Food:
                if(!lex->GetIntAssignment(m_Food)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_Modifiers_Shield:
                if(!lex->GetIntAssignment(m_Shield)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_Modifiers_Movement:
                m_flags0 |= k_Modifiers_Movement_Bit;
                if(!lex->GetIntAssignment(m_MovementValue)) {
                    DBERROR(("Expected integer"));
                    done = true; break;
                }
                break;
            case k_Token_Terrain_Modifiers_Freight:
                if(!lex->GetIntAssignment(m_Freight)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_Modifiers_Materials:
                if(!lex->GetIntAssignment(m_Materials)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_Modifiers_Time:
                if(!lex->GetIntAssignment(m_Time)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_Modifiers_Defense:
                if(!lex->GetFloatAssignment(m_Defense)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_Modifiers_DeadFood:
                if(!lex->GetIntAssignment(m_DeadFood)) {
                    done = true; break;
                }
                break;
            case k_Token_Terrain_Modifiers_DeadShield:
                if(!lex->GetIntAssignment(m_DeadShield)) {
                    done = true; break;
                }
                break;
            case k_Token_CloseBrace:
                done = true;
                result = 1;
                break;
            default:
                Assert(FALSE);
                done = true;
                break;
        }
    }
    lex->RestoreTokens();
    return result;
}

sint32 TerrainRecord::Modifiers::ParseInArray(DBLexer *lex, Modifiers **array, sint32 *numElements)
{
    if(*numElements > 0) {
        Modifiers *oldArray = *array;
        *array = new Modifiers[(*numElements) + 1];
        for (int i=0; i < (*numElements); i++) 
             (*array)[i] = oldArray[i];
        delete [] oldArray;
    } else {
        *array = new Modifiers[1];
    }
    (*array)[*numElements].Parse(lex);
    *numElements += 1;
    return 1;
}
sint32 TerrainRecord::Modifiers::ParseInArray(DBLexer *lex, Modifiers *array, sint32 *numElements, sint32 maxSize)
{
    if(*numElements >= maxSize) {
        return 0;
    }
    array[*numElements].Parse(lex);
    *numElements += 1;
    return 1;
}
void TerrainRecord::Modifiers::ResolveDBReferences()
{
}
/*
 * Data Parsers
 * (DO NOT EDIT!  Automatically generated file)
 */
static char *s_Terrain_MovementType_BitNames[] = {
    "Land",
    "Sea",
    "Air",
    "Mountain",
    "Trade",
    "ShallowWater",
    "Space",
};
#define k_Terrain_MovementType_Num_BitNames 7

sint32 TerrainRecord::ParseMovementTypeBit(DBLexer *lex)
{
    sint32 bitindex;
    if(!lex->GetBitIndex((const char **)s_Terrain_MovementType_BitNames, k_Terrain_MovementType_Num_BitNames, bitindex)) {
        DBERROR(("%s is not a member of MovementType", lex->GetTokenText()));
        return 0;
    }
    m_MovementType |= (1 << bitindex);
    return 1;
}

static char *s_Terrain_InternalType_BitNames[] = {
    "Forest",
    "Plains",
    "Tundra",
    "Glacier",
    "Grassland",
    "Desert",
    "Swamp",
    "Jungle",
    "Mountain",
    "Hill",
    "WaterShallow",
    "WaterDeep",
    "WaterVolcano",
    "WaterBeach",
    "WaterShelf",
    "WaterTrench",
    "WaterRift",
    "Dead",
    "BrownHill",
    "BrownMountain",
    "WhiteHill",
    "WhiteMountain",
    "WaterKelp",
    "WaterReef",
    "Special",
};
#define k_Terrain_InternalType_Num_BitNames 25

sint32 TerrainRecord::ParseInternalTypeBit(DBLexer *lex)
{
    sint32 bitindex;
    if(!lex->GetBitIndex((const char **)s_Terrain_InternalType_BitNames, k_Terrain_InternalType_Num_BitNames, bitindex)) {
        DBERROR(("%s is not a member of InternalType", lex->GetTokenText()));
        return 0;
    }
    m_InternalType |= (1 << bitindex);
    return 1;
}

void TerrainRecord::Merge(const TerrainRecord & rval){
	int index = 0, obj_index = 0;
	// only replace values that have been set
	if((rval.m_flags0 & k_Terrain_TransformAdd_Bit) != 0) 
		m_TransformAddValue = rval.m_TransformAddValue; 

	// only replace values that have been set
	if((rval.m_flags0 & k_Terrain_TransformRemove_Bit) != 0) 
		m_TransformRemoveValue = rval.m_TransformRemoveValue; 

	// only replace values that have been set
	if((rval.m_flags0 & k_Terrain_EnvCity_Bit) != 0) 
		m_EnvCityValue = rval.m_EnvCityValue; 

	// only replace values that have been set
	if((rval.m_flags0 & k_Terrain_EnvRiver_Bit) != 0) 
		m_EnvRiverValue = rval.m_EnvRiverValue; 

	// copy values of rval.m_Resources to m_Resources
	for (index = 0; index < m_numResources; index++) 
	{ 
 		if (index < rval.m_numResources)
 			m_Resources[index] = rval.m_Resources[index];
	} 
 	// only replace values that have been set
	if(rval.m_MovementType != 0x0) 
		m_MovementType = rval.m_MovementType; 

	// only replace values that have been set
	if(rval.m_InternalType != 0x0) 
		m_InternalType = rval.m_InternalType; 

} 

/*
 * Data accessors
 * (DO NOT EDIT!  Automatically generated file)
 */
const IconRecord *TerrainRecord::GetIcon() const
{
    return g_theIconDB->Get(m_Icon);
}

const AdvanceRecord *TerrainRecord::GetAddAdvance() const
{
    return g_theAdvanceDB->Get(m_AddAdvance);
}

const AdvanceRecord *TerrainRecord::GetRemoveAdvance() const
{
    return g_theAdvanceDB->Get(m_RemoveAdvance);
}

sint32 TerrainRecord::GetResourcesIndex(sint32 index) const
{
    Assert(index >= 0);
    Assert(index < m_numResources);
    if((index < 0) || (index >= m_numResources)) {
        return 0;
    }
    return m_Resources[index];
}

const ResourceRecord *TerrainRecord::GetResources(sint32 index) const
{
    Assert(index >= 0);
    Assert(index < m_numResources);
    if((index < 0) || (index >= m_numResources)) {
        return 0;
    }
    return g_theResourceDB->Get(m_Resources[index]);
}

