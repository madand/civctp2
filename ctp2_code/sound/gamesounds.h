

#pragma once

#ifndef __GAMESOUNDS_H__
#define __GAMESOUNDS_H__

struct GameSoundData {
	sint32		id;
	MBCHAR		*name;
};


enum GAMESOUNDS {
	GAMESOUNDS_SPACE_LAUNCH,

	GAMESOUNDS_BUILDING_STARTED,
	GAMESOUNDS_BUILDING_COMPLETE,
	
	GAMESOUNDS_GOODY_BOGUS,
	GAMESOUNDS_GOODY_CITY,
	GAMESOUNDS_GOODY_GOLD,
	GAMESOUNDS_GOODY_ADVANCE,
	GAMESOUNDS_GOODY_UNIT,
	
	GAMESOUNDS_SETTLE_CITY,

	GAMESOUNDS_NET_YOUR_TURN,

	GAMESOUNDS_EXPLOSION,

    GAMESOUNDS_DEFAULT_FAIL, 
    GAMESOUNDS_DEFAULT_CLICK, 
	GAMESOUNDS_BUTTON_PRESS,

	GAMESOUNDS_CHEER_CASTLE,
	GAMESOUNDS_CHEER_ENTERTAINMENT,
	GAMESOUNDS_CHEER_FOUNTAIN,
	GAMESOUNDS_CHEER_STATUE,
	GAMESOUNDS_CHEER_RELIGIOUS,

	GAMESOUNDS_BUTTONCLICK,
	GAMESOUNDS_MINWINDOW,
	GAMESOUNDS_MAXWINDOW,
	GAMESOUNDS_SLIDERUP,
	GAMESOUNDS_SLIDERDOWN,
	GAMESOUNDS_BOUNCEMSG,
	GAMESOUNDS_ALERT,
	GAMESOUNDS_GENERALFAIL,
	GAMESOUNDS_GENERALSUCCEED,

	GAMESOUNDS_CLOAK,
	GAMESOUNDS_UNCLOAK,

	GAMESOUNDS_RAILLAUNCH,

	GAMESOUNDS_CITYCONQUERED,
	GAMESOUNDS_TOOEXPENSIVE,

	GAMESOUNDS_DISBANDED,
	GAMESOUNDS_CHAT_MESSAGE,

	
	GAMESOUNDS_ADVANCE,
	GAMESOUNDS_BOO,
	GAMESOUNDS_CHANGE_GOV,
	GAMESOUNDS_DIP_AGREE,
	GAMESOUNDS_DIP_ALERT,
	GAMESOUNDS_DIP_PEACE,
	GAMESOUNDS_DIP_WAR,
	GAMESOUNDS_DISABLED,
	GAMESOUNDS_DRAGDROP_FAIL,
	GAMESOUNDS_DRAGDROP_PASS,
	GAMESOUNDS_EDIT_TEXT,
	GAMESOUNDS_ENDTURN,
	GAMESOUNDS_ILLEGAL_MOVE,
	GAMESOUNDS_ILLEGAL_SPECIAL,
	GAMESOUNDS_LAUNCH,
	GAMESOUNDS_LOADING,
	GAMESOUNDS_LOSE_PLAYER_BATTLE,
	GAMESOUNDS_LOSE_PLAYER_CITY,
	GAMESOUNDS_MP_ALERT_TURN,
	GAMESOUNDS_MP_HURRY1,
	GAMESOUNDS_MP_HURRY2,
	GAMESOUNDS_POLLUTION_ALERT,
	GAMESOUNDS_POPUP,
	GAMESOUNDS_SCIFI_SCREEN,
	GAMESOUNDS_SUCCESS_FANFARE,
	GAMESOUNDS_SWITCH_OFF,
	GAMESOUNDS_SWITCH_ON,
	GAMESOUNDS_SYS_BUSY,
	GAMESOUNDS_TUTORIAL,
	GAMESOUNDS_VICTORY_FANFARE,
	GAMESOUNDS_VOLUME_DOWN,
	GAMESOUNDS_VOLUME_UP,
	GAMESOUNDS_POTTY,
	GAMESOUNDS_BACK_TO_WORK,
	GAMESOUNDS_HACKNEYED,
	GAMESOUNDS_ARCHER_A,
	GAMESOUNDS_ARCHER_B,
	GAMESOUNDS_ARCHER_C, 
	GAMESOUNDS_ARCHER_D, 

	

	GAMESOUNDS_MAX
};


sint32 gamesounds_GetGameSoundID(sint32 gamesound);

void gamesounds_WindowOpened(void);
void gamesounds_WindowClosed(void);

#define ERROR_SOUND  { if (g_soundManager) { \
			g_soundManager->AddSound(SOUNDTYPE_SFX, (uint32)0, \
				gamesounds_GetGameSoundID(GAMESOUNDS_DEFAULT_FAIL),\
				0, 0);\
} } \

#endif
