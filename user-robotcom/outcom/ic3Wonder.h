













#pragma once

#ifndef __IC3Wonder_H__
#define __IC3Wonder_H__ 1


#include <OBJBASE.H>  


enum WONDER_EFFECT { 
	WONDER_EFFECT_EMBASSY,
	WONDER_EFFECT_CLOSE_EMBASSY,
	WONDER_EFFECT_REFORM_CITIES,
	WONDER_EFFECT_FREE_SLAVES,
	WONDER_EFFECT_GLOBAL_RADAR,
	WONDER_EFFECT_SPIES_EVERYWHERE,
	WONDER_EFFECT_FREE_SPACE_TRANS,
	WONDER_EFFECT_STOP_BIOWAR,
	WONDER_EFFECT_POP_MONITOR,
	WONDER_EFFECT_ENABLE_PARKRANGER,
	WONDER_EFFECT_ALL_POP_CONTENT,
	WONDER_EFFECT_DISABLE_NUKES,

	WONDER_EFFECT_REDUCE_READINESS_COST,
	WONDER_EFFECT_INCREASE_GOLD,
	WONDER_EFFECT_DECREASE_CRIME,
	WONDER_EFFECT_INCREASE_KNOWLEDGE,
	WONDER_EFFECT_DECREASE_EMPIRE_SIZE,
	WONDER_EFFECT_INCREASE_HAPPY_EMPIRE,
	WONDER_EFFECT_INCREASE_CONVERTED_CITY_FEE,
	WONDER_EFFECT_TAX_WATER_ROUTES,
	WONDER_EFFECT_TAX_TELEVISION,
	WONDER_EFFECT_INCREASE_HAPPY,
	WONDER_EFFECT_MAKE_GENETICS_CHEAP,
	WONDER_EFFECT_TAX_INTERNATIONAL_ROUTE,
	WONDER_EFFECT_POLLUTERS_TO_PARKS,
	WONDER_EFFECT_REDUCE_WORLD_POLLUTION,
    WONDER_EFFECT_POLLUTION_BONUS,
	WONDER_EFFECT_POLLUTION_CLEANER, 
    WONDER_EFFECT_MAX 
};

DEFINE_GUID(CLSID_IC3Wonder, 0x5cdc3321, 0x69e, 0x11d2, 0x83, 0x55, 0x0, 0xc0, 0x4f, 0xba, 0x43, 0xc0) ;

#undef INTERFACE
#define INTERFACE IC3Wonder

DECLARE_INTERFACE_(IC3Wonder, IUnknown)
	{
 	

	STDMETHOD_ (sint32, GetNumWonders)(THIS_) PURE ;
	STDMETHOD_ (BOOL, HasBeenBuilt)(THIS_ sint32 wonder_type) PURE ;
	STDMETHOD_ (sint32, EnablingDiscovery)(THIS_ sint32 wonder_type) PURE ;
	STDMETHOD_ (sint32, GetOwner)(THIS_ sint32 wonder_type) PURE ;
	STDMETHOD_ (sint32, ObsoleteDiscovery)(THIS_ sint32 wonder_type) PURE ;
    STDMETHOD_ (BOOL, WondersAvailable) (THIS_ sint32 player_idx) PURE;

    STDMETHOD_ (sint32, GetProductionCost) (THIS_ sint32 wonder_type) PURE; 
    STDMETHOD_ (void, GetAllEffects) (THIS_ sint32 wonder_type, double *effects) PURE;
    STDMETHOD_ (char *, Wonder_Int_To_String) (THIS_ sint32 wonder_type) PURE; 
    STDMETHOD_ (sint32, Wonder_String_To_Int) (THIS_ char *wonder_name) PURE; 
    STDMETHOD_ (double, MaxPecentageThisWonderDone) (THIS_ sint32 wonder_type) PURE; 
    STDMETHOD_ (BOOL, CanBuild) (THIS_ sint32 wonder_type) PURE; 
	STDMETHOD_ (BOOL, IsObsolete) (THIS_ sint32 wonder_type) PURE; 
    STDMETHOD_ (BOOL, IsWormholeDetectorBuilt)(THIS_) PURE; 


	} ;

#endif __IC3Wonder_H__
