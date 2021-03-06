#pragma once
#ifndef _D2STRUCTS_H
#define _D2STRUCTS_H

#include <windows.h>

#pragma warning ( push )
#pragma warning ( disable: 4201 )
#pragma optimize ( "", off )

struct UnitAny;
struct Room1;
struct Room2;
struct Level;
struct Act;
struct ActMisc;
struct RosterUnit;
struct OverheadMsg;

struct InventoryInfo {
	int nLocation;
	int nMaxXCells;
	int nMaxYCells;
};

struct GameStructInfo {
	BYTE _1[0x1B];					//0x00
	char szGameName[0x18];			//0x1B
	char szGameServerIp[0x56];		//0x33
	char szAccountName[0x30];		//0x89
	char szCharName[0x18];			//0xB9
	char szRealmName[0x18];			//0xD1
	BYTE _2[0x158];					//0xE9
	char szGamePassword[0x18];		//0x241
};

struct AutomapCell {
	DWORD fSaved;					//0x00
	WORD nCellNo;					//0x04
	WORD xPixel;					//0x06
	WORD yPixel;					//0x08
	WORD wWeight;					//0x0A
	AutomapCell *pLess;				//0x0C
	AutomapCell *pMore;				//0x10
};

struct GfxCell {
	DWORD flags;					//0x00
	DWORD width;					//0x04
	DWORD height;					//0x08
	DWORD xoffs;					//0x0C
	DWORD yoffs;					//0x10
	DWORD _2;						//0x14
	DWORD lpParent;					//0x18
	DWORD length;					//0x1C
	BYTE cols;						//0x20
};

struct InteractStruct {
	DWORD dwMoveType;			//0x00
	UnitAny* lpPlayerUnit;		//0x04
	UnitAny* lpTargetUnit;		//0x08
	DWORD dwTargetX;			//0x0C
	DWORD dwTargetY;			//0x10
	DWORD _1;					//0x14
	DWORD _2;					//0x18
};

struct CellFile {
	DWORD dwVersion;				//0x00
	struct {
		WORD dwFlags;
		BYTE mylastcol;
		BYTE mytabno:1;
	};								//0x04
	DWORD eFormat;					//0x08
	DWORD termination;				//0x0C
	DWORD numdirs;					//0x10
	DWORD numcells;					//0x14
	GfxCell *cells[1];				//0x18
};

struct CellContext {
	DWORD nCellNo;					//0x00
	DWORD _1[12];					//0x04
	CellFile* pCellFile;			//0x34
};

struct AutomapLayer {
	DWORD nLayerNo;					//0x00
	DWORD fSaved;					//0x04
	AutomapCell *pFloors;			//0x08
	AutomapCell *pWalls;			//0x0C
	AutomapCell *pObjects;			//0x10
	AutomapCell *pExtras;			//0x14
	AutomapLayer *pNextLayer;		//0x18
};

struct AutomapLayer2 {
	DWORD _1[2];					//0x00
	DWORD nLayerNo;					//0x08
};

struct LevelText {
	DWORD dwLevelNo;				//0x00
	DWORD _1[60];					//0x04
	BYTE _2;						//0xF4
	char szName[40];				//0xF5
	char szEntranceText[40];		//0x11D
	char szLevelDesc[41];			//0x145
	wchar_t wName[40];				//0x16E
	wchar_t wEntranceText[40];		//0x1BE
	BYTE nObjGroup[8];				//0x196
	BYTE nObjPrb[8];				//0x19E
};

struct ControlPreferences
{
	DWORD dwType;//0x00
	// ..
};

struct ControlText {
	wchar_t* wText; //0x00
	wchar_t* wText2;//0x04
	DWORD _1[3];	//0x08
	DWORD dwColor;	//0x14
	DWORD _2;		//0x18
	ControlText* pNext;//0x1C
};

struct Control {
   DWORD dwType;					//0x00
   CellFile *pCellFile;				//0x04
   DWORD dwDisabled;				//0x08
   DWORD dwPosX;					//0x0C
   DWORD dwPosY;					//0x10
   DWORD dwSizeX;					//0x14
   DWORD dwSizeY;					//0x18
   VOID (__fastcall *Initialize)(Control* pControl);//0x1c
   DWORD _3;						//0x20
   DWORD *_4;						//0x24
   DWORD *_5;						//0x28
   DWORD _6;						//0x2C
   DWORD *_7;						//0x30
   DWORD *_8;						//0x34
   DWORD _9;						//0x38
   Control* pNext;					//0x3C
   DWORD _10;						//0x40
   DWORD dwMaxLength;				//0x44
   union {
	   ControlText* pFirstText;		//0x48
	   DWORD dwScrollEntries;		//0x48
   };
   union {
       ControlText* pLastText;		//0x4C
	   DWORD dwScrollPosition;		//0x4C
   };
   ControlText* pSelectedText;		//0x50
   DWORD dwSelectEnd;				//0x54
   DWORD dwSelectStart;				//0x58
   wchar_t wText[0x1A];				//0x5C
   Control* pChildControl;			//0x90
};

struct MonStatsTxt // size 0x1A8
{
	WORD	wId;						//0x00
	WORD	wBaseId;					//0x02
	WORD	wNextInClass;				//0x04
	WORD	wNameStr;					//0x06
	WORD	wDescStr;					//0x08
	WORD	_1a;						//0x0A
	struct {
		BYTE	bisSpawn : 1;						//1
		BYTE	bisMelee : 1;						//2
		BYTE	bnoRatio : 1;						//3
		BYTE	bOpenDoors : 1;					//4
		BYTE	bSetBoss : 1;						//5
		BYTE	bBossXfer : 1;					//6
		BYTE	bBossXfer2 : 1;					//7
		BYTE	bPrimeEvil : 1;					//8
		BYTE	bNPC : 1;							//9
		BYTE	bInteract : 1;					//10
		BYTE	binTown : 1;						//11
		BYTE	blUndead : 1;						//12
		BYTE	bhUndead : 1;						//13
		BYTE	bDemon : 1;						//14
		BYTE	bFlying : 1;						//15
		BYTE	bKillable : 1;					//16
		BYTE	bSwitchAI : 1;					//17
		BYTE	bNoMultiShot : 1;					//18
		BYTE	bNeverCount : 1;					//19
		BYTE	bPetIgnore : 1;					//20
		BYTE	bDeathDmg : 1;					//21
		BYTE	bGenericSpawn : 1;				//22
		BYTE	bZoo : 1;							//23
		BYTE	bPlaceSpawn : 1;					//24
		BYTE	bInventory : 1;					//25
		BYTE	bEnabled : 1;						//26
		BYTE	bNoShldBlock : 1;					//27
		BYTE	bNoAura : 1;						//28
		BYTE	bRangedType : 1;					//29
	} dwFlags;							//0x0C
	DWORD	dwCode;						//0x10
	WORD	wMonSound;					//0x14
	WORD	wUMonSound;					//0x16
	WORD	wMonStatsEx;				//0x18
	WORD	wMonProp;					//0x1A
	WORD	wMonType;					//0x1C
	WORD	wAI;						//0x1E
	WORD	wSpawn;						//0x20
	BYTE	bSpawnX;					//0x22
	BYTE	bSpawnY;					//0x23
	WORD	bSpawnMode;					//0x24
	WORD	wMinion1;					//0x26
	WORD	wMinion2;					//0x28
	WORD	_1;							//0x2A
	BYTE	bPartyMin;					//0x2C
	BYTE	bPartyMax;					//0x2D
	BYTE	bRarity;					//0x2E
	BYTE	bMinGrp;					//0x2F
	BYTE	bMaxGrp;					//0x30
	BYTE	bSparsePopulate;			//0x31
	WORD	wVelocity;					//0x32
	WORD	wRun;						//0x34
	WORD	_2;							//0x36
	WORD	_2b;						//0x38
	WORD	wMissA1;					//0x3A
	WORD	wMissA2;					//0x3C
	WORD	wMissS1;					//0x3E
	WORD	wMissS2;					//0x40
	WORD	wMissS3;					//0x42
	WORD	wMissS4;					//0x44
	WORD	wMissC;						//0x46
	WORD	wMissSQ;					//0x48
	WORD	_3;							//0x4A
	BYTE	bAlign;						//0x4C
	BYTE	bTransLvl;					//0x4D
	BYTE	bThreat;					//0x4E
	BYTE	bAIdel;						//0x4F
	BYTE	bAIdel_N;					//0x50
	BYTE	bAIdel_H;					//0x51
	BYTE	bAiDist;					//0x52
	BYTE	bAiDist_N;					//0x53
	WORD	bAiDist_H;					//0x54
	WORD	wAiP1;						//0x56
	WORD	wAiP1_N;					//0x58
	WORD	wAiP1_H;					//0x5A
	WORD	wAiP2;						//0x5C
	WORD	wAiP2_N;					//0x5E
	WORD	wAiP2_H;					//0x60
	WORD	wAiP3;						//0x62
	WORD	wAiP3_N;					//0x64
	WORD	wAiP3_H;					//0x66
	WORD	wAiP4;						//0x68
	WORD	wAiP4_N;					//0x6A
	WORD	wAiP4_H;					//0x6C
	WORD	wAiP5;						//0x6E
	WORD	wAiP5_N;					//0x70
	WORD	wAiP5_H;					//0x72
	WORD	wAiP6;						//0x74
	WORD	wAiP6_N;					//0x76
	WORD	wAiP6_H;					//0x78
	WORD	wAiP7;						//0x7A
	WORD	wAiP7_N;					//0x7C
	WORD	wAiP7_H;					//0x7E
	WORD	wAiP8;						//0x80
	WORD	wAiP8_N;					//0x82
	WORD	wAiP8_H;					//0x84
	WORD	wTreasureClass1;			//0x86
	WORD	wTreasureClass2;			//0x88
	WORD	wTreasureClass3;			//0x8A
	WORD	wTreasureClass4;			//0x8C
	WORD	wTreasureClass1_N;			//0x8E
	WORD	wTreasureClass2_N;			//0x90
	WORD	wTreasureClass3_N;			//0x92
	WORD	wTreasureClass4_N;			//0x94
	WORD	wTreasureClass1_H;			//0x96
	WORD	wTreasureClass2_H;			//0x98
	WORD	wTreasureClass3_H;			//0x9A
	WORD	wTreasureClass4_H;			//0x9C
	BYTE	bTCQuestId;					//0x9E
	BYTE	bTCQuestCP;					//0x9F
	BYTE	bDrain;						//0xA0
	BYTE	bDrain_N;					//0xA1
	BYTE	bDrain_H;					//0xA2
	BYTE	bToBlock;					//0xA3
	BYTE	bToBlock_N;					//0xA4
	BYTE	bToBlock_H;					//0xA5
	WORD	bCrit;						//0xA6
	WORD	wSkillDamage;				//0xA8
	WORD	wLevel;						//0xAA
	WORD	wLevel_N;					//0xAC
	WORD	wLevel_H;					//0xAE
	WORD	wMinHP;						//0xB0
	WORD	wMinHP_N;					//0xB2
	WORD	wMinHP_H;					//0xB4
	WORD	wMaxHP;						//0xB6
	WORD	wMaxHP_N;					//0xB8
	WORD	wMaxHP_H;					//0xBA
	WORD	wAC;						//0xBC
	WORD	wAC_N;						//0xBE
	WORD	wAC_H;						//0xC0
	WORD	wA1TH;						//0xC2
	WORD	wA1TH_N;					//0xC4
	WORD	wA1TH_H;					//0xC6
	WORD	wA2TH;						//0xC8
	WORD	wA2TH_N;					//0xCA
	WORD	wA2TH_H;					//0xCC
	WORD	wS1TH;						//0xCE
	WORD	wS1TH_N;					//0xD0
	WORD	wS1TH_H;					//0xD2
	WORD	wExp;						//0xD4
	WORD	wExp_N;						//0xD6
	WORD	wExp_H;						//0xD8
	WORD	wA1MinD;					//0xDA
	WORD	wA1MinD_N;					//0xDC
	WORD	wA1MinD_H;					//0xDE
	WORD	wA1MaxD;					//0xE0
	WORD	wA1MaxD_N;					//0xE2
	WORD	wA1MaxD_H;					//0xE4
	WORD	wA2MinD;					//0xE6
	WORD	wA2MinD_N;					//0xE8
	WORD	wA2MinD_H;					//0xEA
	WORD	wA2MaxD;					//0xEC
	WORD	wA2MaxD_N;					//0xEE
	WORD	wA2MaxD_H;					//0xF0
	WORD	wS1MinD;					//0xF2
	WORD	wS1MinD_N;					//0xF4
	WORD	wS1MinD_H;					//0xF6
	WORD	wS1MaxD;					//0xF8
	WORD	wS1MaxD_N;					//0xFA
	WORD	wS1MaxD_H;					//0xFC
	BYTE	bEl1Mode;					//0xFE
	BYTE	bEl2Mode;					//0xFF
	BYTE	bEl3Mode;					//0x100
	BYTE	bEl1Type;					//0x101
	BYTE	bEl2Type;					//0x102
	BYTE	bEl3Type;					//0x103
	BYTE	bEl1Pct;					//0x104
	BYTE	bEl1Pct_N;					//0x105
	BYTE	bEl1Pct_H;					//0x106
	BYTE	bEl2Pct;					//0x107
	BYTE	bEl2Pct_N;					//0x108
	BYTE	bEl2Pct_H;					//0x109
	BYTE	bEl3Pct;					//0x10A
	BYTE	bEl3Pct_N;					//0x10B
	BYTE	bEl3Pct_H;					//0x10C
	BYTE	_4;							//0x10D
	WORD	wEl1MinD;					//0x10E
	WORD	wEl1MinD_N;					//0x110
	WORD	wEl1MinD_H;					//0x112
	WORD	wEl2MinD;					//0x114
	WORD	wEl2MinD_N;					//0x116
	WORD	wEl2MinD_H;					//0x118
	WORD	wEl3MinD;					//0x11A
	WORD	wEl3MinD_N;					//0x11C
	WORD	wEl3MinD_H;					//0x11E
	WORD	wEl1MaxD;					//0x120
	WORD	wEl1MaxD_N;					//0x122
	WORD	wEl1MaxD_H;					//0x124
	WORD	wEl2MaxD;					//0x126
	WORD	wEl2MaxD_N;					//0x128
	WORD	wEl2MaxD_H;					//0x12A
	WORD	wEl3MaxD;					//0x12C
	WORD	wEl3MaxD_N;					//0x12E
	WORD	wEl3MaxD_H;					//0x130
	WORD	wEl1Dur;					//0x132
	WORD	wEl1Dur_N;					//0x134
	WORD	wEl1Dur_H;					//0x136
	WORD	wEl2Dur;					//0x138
	WORD	wEl2Dur_N;					//0x13A
	WORD	wEl2Dur_H;					//0x13C
	WORD	wEl3Dur;					//0x13E
	WORD	wEl3Dur_N;					//0x140
	WORD	wEl3Dur_H;					//0x142
	WORD	wResDmg;					//0x144
	WORD	wResDmg_N;					//0x146
	WORD	wResDmg_H;					//0x148
	WORD	wResMagic;					//0x14A
	WORD	wResMagic_N;				//0x14C
	WORD	wResMagic_H;				//0x14E
	WORD	wResFire;					//0x150
	WORD	wResFire_N;					//0x152
	WORD	wResFire_H;					//0x154
	WORD	wResLight;					//0x156
	WORD	wResLight_N;				//0x158
	WORD	wResLight_H;				//0x15A
	WORD	wResCold;					//0x15C
	WORD	wResCold_N;					//0x15E
	WORD	wResCold_H;					//0x160
	WORD	wResPoison;					//0x162
	WORD	wResPoison_N;				//0x164
	WORD	wResPoiosn_H;				//0x166
	BYTE	bColdEffect;				//0x168
	BYTE	bColdEffect_N;				//0x169
	WORD	bColdEffect_H;				//0x16A
	DWORD	dwSendSkills;				//0x16C
	WORD	wSkill1;					//0x170
	WORD	wSkill2;					//0x172
	WORD	wSkill3;					//0x174
	WORD	wSkill4;					//0x176
	WORD	wSkill5;					//0x178
	WORD	wSkill6;					//0x17A
	WORD	wSkill7;					//0x17C
	WORD	wSkill8;					//0x17E
	DWORD   _5[6];						//0x180
	BYTE	bSk1lvl;					//0x198
	BYTE	bSk2lvl;					//0x199
	BYTE	bSk3lvl;					//0x19A
	BYTE	bSk4lvl;					//0x19B
	BYTE	bSk5lvl;					//0x19C
	BYTE	bSk6lvl;					//0x19D
	BYTE	bSk7lvl;					//0x19E
	BYTE	bSk8lvl;					//0x19F
	DWORD	dwDamageRegen;				//0x1A0
	BYTE	bSplEndDeath;				//0x1A4
	BYTE	bSplGetModeChart;			//0x1A5
	BYTE	bSplEndGeneric;				//0x1A6
	BYTE	bSplClientEnd;				//0x1A7
};

#pragma pack(push)
#pragma pack(1)

struct RoomTile {
	Room2* pRoom2;				//0x00
	RoomTile* pNext; 			//0x04
	DWORD _2[2];				//0x08
	DWORD *nNum; 				//0x10
};

struct RosterUnit {
	char szName[16];				//0x00
	DWORD dwUnitId;					//0x10
	DWORD dwPartyLife;				//0x14
	DWORD _1;						//0x18
	DWORD dwClassId;                //0x1C
	WORD wLevel;					//0x20
	WORD wPartyId;  				//0x22
	DWORD dwLevelId;                //0x24
	DWORD Xpos;						//0x28
	DWORD Ypos;						//0x2C
	DWORD dwPartyFlags;				//0x30
	BYTE * _5;						//0x34
	DWORD _6[11];					//0x38
	WORD _7;						//0x64
	char szName2[16];				//0x66
	WORD _8;						//0x76
	DWORD _9[2];					//0x78
	RosterUnit * pNext;				//0x80
};

struct QuestInfo {
	void *pBuffer;					//0x00
	DWORD _1;						//0x04
};

struct Waypoint {
	BYTE flags;						//0x00
};

struct PlayerData {
	char szName[0x10];				//0x00
	QuestInfo *pNormalQuest;		//0x10
	QuestInfo *pNightmareQuest;		//0x14
	QuestInfo *pHellQuest;			//0x18
	Waypoint *pNormalWaypoint;		//0x1c
	Waypoint *pNightmareWaypoint;	//0x20
	Waypoint *pHellWaypoint;		//0x24
};

struct CollMap {
	DWORD dwPosGameX;				//0x00
	DWORD dwPosGameY;				//0x04
	DWORD dwSizeGameX;				//0x08
	DWORD dwSizeGameY;				//0x0C
	DWORD dwPosRoomX;				//0x10
	DWORD dwPosRoomY;				//0x14
	DWORD dwSizeRoomX;				//0x18
	DWORD dwSizeRoomY;				//0x1C
	WORD *pMapStart;				//0x20
	WORD *pMapEnd;					//0x22
};

struct PresetUnit {
	DWORD _1;						//0x00
	DWORD dwTxtFileNo;				//0x04
	DWORD dwPosX;					//0x08
	PresetUnit* pPresetNext;		//0x0C
	DWORD _3;						//0x10
	DWORD dwType;					//0x14
	DWORD dwPosY;					//0x18
};

struct Level {
	DWORD _1[4];			//0x00
	Room2* pRoom2First;		//0x10
	DWORD _2[2];			//0x14
	DWORD dwPosX;			//0x1C
	DWORD dwPosY;			//0x20
	DWORD dwSizeX;			//0x24
	DWORD dwSizeY;			//0x28
	DWORD _3[96];			//0x2C
	Level* pNextLevel;		//0x1AC
	DWORD _4;				//0x1B0
	ActMisc* pMisc;			//0x1B4
	DWORD _5[6];			//0x1BC
	DWORD dwLevelNo;		//0x1D0
};

struct Room2 {
	DWORD _1[2];			//0x00
	Room2** pRoom2Near;		//0x08
	DWORD _2[5];			//0x0C
	struct {
		DWORD dwRoomNumber; //0x00
		DWORD _1;			//0x04
		DWORD* pdwSubNumber;//0x08
	} *pType2Info;			//0x20
	Room2* pRoom2Next;		//0x24
	DWORD dwRoomFlags;		//0x28
	DWORD dwRoomsNear;		//0x2C
	Room1* pRoom1;			//0x30
	DWORD dwPosX;			//0x34
	DWORD dwPosY;			//0x38
	DWORD dwSizeX;			//0x3C
	DWORD dwSizeY;			//0x40
	DWORD _3;				//0x44
	DWORD dwPresetType;		//0x48
	RoomTile* pRoomTiles;	//0x4C
	DWORD _4[2];			//0x50
	Level* pLevel;			//0x58
	PresetUnit* pPreset;	//0x5C
};

#pragma pack(pop)

struct Room1 {
	Room1** pRoomsNear; 	//0x00
	DWORD _1[3];			//0x04
	Room2* pRoom2;			//0x10
	DWORD _2[3];			//0x14
	CollMap* Coll;			//0x20
	DWORD dwRoomsNear;		//0x24
	DWORD _3[9];			//0x28
	DWORD dwXStart;			//0x4C
	DWORD dwYStart;			//0x50
	DWORD dwXSize;			//0x54
	DWORD dwYSize;			//0x58
	DWORD _4[6];			//0x5C
	UnitAny* pUnitFirst;	//0x74
	DWORD _5;				//0x78
	Room1* pRoomNext;		//0x7C
};

struct ActMisc {
	DWORD _1[37];			//0x00
	DWORD dwStaffTombLevel; //0x94
	DWORD _2[245];			//0x98
	Act* pAct;				//0x46C
	DWORD _3[3];			//0x470
	Level* pLevelFirst;		//0x47C
};

struct Act {
	DWORD _1[3];			//0x00
	DWORD dwMapSeed;		//0x0C
	Room1* pRoom1;			//0x10
	DWORD dwAct;			//0x14
	DWORD _2[12];			//0x18
	ActMisc* pMisc;			//0x48
};

struct Path {
	WORD xOffset;					//0x00
	WORD xPos;						//0x02
	WORD yOffset;					//0x04
	WORD yPos;						//0x06
	DWORD _1[2];					//0x08
	WORD xTarget;					//0x10
	WORD yTarget;					//0x12
	DWORD _2[2];					//0x14
	Room1 *pRoom1;					//0x1C
	Room1 *pRoomUnk;				//0x20
	DWORD _3[3];					//0x24
	UnitAny *pUnit;					//0x30
	DWORD dwFlags;					//0x34
	DWORD _4;						//0x38
	DWORD dwPathType;				//0x3C
	DWORD dwPrevPathType;			//0x40
	DWORD dwUnitSize;				//0x44
	DWORD _5[4];					//0x48
	UnitAny *pTargetUnit;			//0x58
	DWORD dwTargetType;				//0x5C
	DWORD dwTargetId;				//0x60
	BYTE bDirection;				//0x64
};

struct ItemPath {
	DWORD _1[3];					//0x00
	DWORD dwPosX;					//0x0C
	DWORD dwPosY;					//0x10
	//Use Path for the rest
};

struct Stat {
	WORD wSubIndex;					//0x00
	WORD wStatIndex;				//0x02
	DWORD dwStatValue;				//0x04
};

// Credits to SVR, http://phrozenkeep.hugelaser.com/forum/viewtopic.php?f=8&t=31458&p=224066
struct StatList {
	DWORD _1;						//0x00
	UnitAny* pUnit;					//0x04
	DWORD dwUnitType;				//0x08
	DWORD dwUnitId;					//0x0C
	DWORD dwFlags;					//0x10
	DWORD _2[4];					//0x14
	Stat *pStat;					//0x24
	WORD wStatCount1;				//0x28
	WORD wnSize;					//0x2A
	StatList *pPrevLink;			//0x2C
	DWORD _3;						//0x30
	StatList *pPrev;				//0x34
	DWORD _4;						//0x38
	StatList *pNext;				//0x3C
	StatList *pSetList;				//0x40
	DWORD _5;						//0x44
	Stat *pSetStat;					//0x48
	WORD wSetStatCount;				//0x4C
};

struct InventoryStore
{
	DWORD pFirstItem;				//0x00
	DWORD pLastItem;				//0x04
	BYTE Width;						//0x08
	BYTE Height;					//0x09
	BYTE unk[2];					//0x0A
	DWORD pArray;					//0x0C UnitAny* [height][width]
};

struct Inventory {
	DWORD dwSignature;				//0x00
	BYTE *bGame1C;					//0x04
	UnitAny *pOwner;				//0x08
	UnitAny *pFirstItem;			//0x0C
	UnitAny *pLastItem;				//0x10
	InventoryStore *pStores;		//0x14 InventoryStore* [count]
	DWORD dwStoresCount;			//0x18
	DWORD dwLeftItemUid;			//0x1C
	UnitAny *pCursorItem;			//0x20
	DWORD dwOwnerId;				//0x24
	DWORD dwItemCount;				//0x28
};

struct Light {
	DWORD _1[3];					//0x00
	DWORD dwType;					//0x0C
	DWORD _2[7];					//0x10
	DWORD dwStaticValid;			//0x2C
	int *pnStaticMap;				//0x30
};

struct SkillInfo {
	WORD wSkillId;					//0x00
};

struct Skill {
	SkillInfo *pSkillInfo;			//0x00
	Skill *pNextSkill;				//0x04
	DWORD _1[8];					//0x08
	DWORD dwSkillLevel;				//0x28
	DWORD _2[2];					//0x2C
	DWORD dwFlags;					//0x30
};

struct Info {
	BYTE *pGame1C;					//0x00
	Skill *pFirstSkill;				//0x04
	Skill *pLeftSkill;				//0x08
	Skill *pRightSkill;				//0x0C
};

struct ItemData {
	DWORD dwQuality;				//0x00
	DWORD _1[2];					//0x04
	DWORD dwItemFlags;				//0x0C 1 = Owned by player, 0xFFFFFFFF = Not owned
	DWORD _2[2];					//0x10
	DWORD dwFlags;					//0x18
	DWORD _3[3];					//0x1C
	DWORD dwQuality2;				//0x28
	DWORD dwItemLevel;				//0x2C
	WORD wVersion;					//0x30
	WORD wRarePrefix;				//0x32
	WORD wRareSuffix;				//0x34
	WORD _14;						//0x36
	WORD wPrefix[3];				//0x38
	WORD wSuffix[3];				//0x3E
	BYTE BodyLocation;				//0x44
	BYTE ItemLocation;				//0x45 Non-body/belt location (Body/Belt == 0xFF)
	BYTE EarLevel;					//0x46
	BYTE VarGfx;					//0x47
	CHAR personalizedName[16];		//0x4A
	WORD _10;						//0x5A
	Inventory *pOwnerInventory;		//0x5C
	UnitAny *pPrevInvItem;			//0x60
	UnitAny *pNextInvItem;			//0x64
	BYTE _11;						//0x68
	BYTE NodePage;					//0x69 Actual location, this is the most reliable by far
	WORD _12;						//0x6A
	DWORD _13[6];					//0x6C
	UnitAny *pOwner;				//0x84
};

struct ItemText {
	wchar_t szName2[0x40];			//0x00
	union {
		DWORD dwCode;
		char szCode[4];
	};								//0x40
	BYTE _uncharted1[0x54];			//0x44
	DWORD speed;					//0x98
	BYTE _uncharted2[0x18];			//0x9C
	WORD nLocaleTxtNo;				//0xB4
	BYTE _uncharted3[0x0E];			//0xB6
	WORD rangeadder;				//0xC4
	BYTE _uncharted4[0x09];			//0xC6
	BYTE xSize;						//0xCF
	BYTE ySize;						//0xD0
	BYTE _uncharted5[0x0d];			//0xD1
	BYTE nType;						//0xDE
	BYTE _uncharted6[0x0d];			//0xDF
	BYTE fQuest;					//0xEC
	BYTE _uncharted7[0x12];			//0xED
	BYTE reqlvl;					//0xFF 
	BYTE magiclvl;					//0x100
};

struct MonsterText {
	BYTE _1[0x6];					//0x00
	WORD nLocaleTxtNo;				//0x06
	WORD flag;						//0x08
	WORD _1a;						//0x0A
	union {
		DWORD flag1;				//0x0C
		struct {
			BYTE flag1a;			//0x0C
			BYTE flag1b;			//0x0D
			BYTE flag1c[2];			//0x0E
		};
	};
	BYTE _2[0x22];					//0x10
	WORD velocity;					//0x32
	BYTE _2a[0x52];					//0x34
	WORD tcs[3][4];					//0x86
	BYTE _2b[0x52];					//0x9E
	wchar_t szDescriptor[0x3c];		//0xF0
	BYTE _3[0x1a0];					//0x12C
};

struct MonsterData {
	MonStatsTxt* pMonStatsTxt;				//0x00
	BYTE Components[16];					//0x04
	WORD NameSeed;							//0x14
	struct
	{
		BYTE fUnk : 1;
		BYTE fNormal : 1;
		BYTE fChamp : 1;
		BYTE fBoss : 1;
		BYTE fMinion : 1;
	};				//0x16
	BYTE dwLastMode;				//0x17
	DWORD dwDuriel;					//0x18
	BYTE anEnchants[9];				//0x1C
	WORD wUniqueNo;					//0x26
	DWORD _5;						//0x28
	struct {
		wchar_t wName[28];
	};								//0x2C
};

struct ObjectTxt {
	char szName[0x40];				//0x00
	wchar_t wszName[0x40];			//0x40
	BYTE _1[4];						//0xC0
	BYTE nSelectable0;				//0xC4
	BYTE _2[0x87];					//0xC5
	BYTE nOrientation;				//0x14C
	BYTE _2b[0x19];					//0x14D
	BYTE nSubClass;					//0x166
	BYTE _3[0x11];					//0x167
	BYTE nParm0;					//0x178
	BYTE _4[0x39];					//0x179
	BYTE nPopulateFn;				//0x1B2
	BYTE nOperateFn;				//0x1B3
	BYTE _5[8];						//0x1B4
	DWORD nAutoMap;					//0x1BB
};

struct ObjectData {
	ObjectTxt *pTxt;				//0x00
	union {
		BYTE Type;					//0x04 (0x0F would be a Exp Shrine)
		struct {
			BYTE _1:7;
			BYTE ChestLocked:1;
		};
	};
	DWORD _2[8];					//0x08
	char szOwner[0x10];				//0x28
};

struct ObjectPath {
	Room1 *pRoom1;					//0x00
	DWORD _1[2];					//0x04
	DWORD dwPosX;					//0x0C
	DWORD dwPosY;					//0x10
	//Leaving rest undefined, use Path
};

struct UnitAny {
	DWORD dwType;					//0x00
	DWORD dwTxtFileNo;				//0x04
	DWORD _1;						//0x08
	DWORD dwUnitId;					//0x0C
	DWORD dwMode;					//0x10
	union
	{
		PlayerData *pPlayerData;
		ItemData *pItemData;
		MonsterData *pMonsterData;
		ObjectData *pObjectData;
		//TileData *pTileData doesn't appear to exist anymore
	};								//0x14
	DWORD dwAct;					//0x18
	Act *pAct;						//0x1C
	DWORD dwSeed[2];				//0x20
	DWORD _2;						//0x28
	union
	{
		Path *pPath;
		ItemPath *pItemPath;
		ObjectPath *pObjectPath;
	};								//0x2C
	DWORD _3[5];					//0x30
	DWORD dwGfxFrame;				//0x44
	DWORD dwFrameRemain;			//0x48
	WORD wFrameRate;				//0x4C
	WORD _4;						//0x4E
	BYTE *pGfxUnk;					//0x50
	DWORD *pGfxInfo;				//0x54
	DWORD _5;						//0x58
	StatList *pStats;				//0x5C
	Inventory *pInventory;			//0x60
	Light *ptLight;					//0x64
	DWORD _6[9];					//0x68
	WORD wX;						//0x8C
	WORD wY;						//0x8E
	DWORD _7;						//0x90
	DWORD dwOwnerType;				//0x94
	DWORD dwOwnerId;				//0x98
	DWORD _8[2];					//0x9C
	OverheadMsg* pOMsg;				//0xA4
	Info *pInfo;					//0xA8
	DWORD _9[6];					//0xAC
	DWORD dwFlags;					//0xC4
	DWORD dwFlags2;					//0xC8
	DWORD _10[5];					//0xCC
	UnitAny *pChangedNext;			//0xE0
	UnitAny *pRoomNext;				//0xE4
	UnitAny *pListNext;				//0xE8 -> 0xD8
};

struct BnetData {
	DWORD dwId;					//0x00
	DWORD dwId2;				//0x04	
	BYTE _12[13];				//0xC0
	//DWORD dwId3;				//0x14
	//WORD Unk3;					//0x18	
	BYTE _13[6];				//0xC0
	char szGameName[22];		//0x1A
	char szGameIP[16];			//0x30
	DWORD _2[15];				//0x40
	DWORD dwId4;				//0x80
	BYTE _3[5];					//0x84
	char szAccountName[48];		//0x88
	char szPlayerName[24];		//0xB8
	char szRealmName[8];		//0xD0
	BYTE _4[273];				//0xD8
	BYTE nCharClass;			//0x1E9
	BYTE nCharFlags;			//0x1EA
	BYTE nMaxLvlDifference;		//0x1EB
	BYTE _5[31];				//0x1EC
	BYTE nDifficulty;			//0x20B
	void *_6;					//0x20C
	DWORD _7[3];				//0x210
	WORD _8;					//0x224
	BYTE _9[7];					//0x226
	char szRealmName2[24];		//0x227
	char szGamePass[24];		//0x23F
	char szGameDesc[256];		//0x257
	WORD _10;					//0x348
	BYTE _11;					//0x34B
};


struct WardenClientRegion_t {
	DWORD cbAllocSize; //+00
	DWORD offsetFunc1; //+04
	DWORD offsetRelocAddressTable; //+08
	DWORD nRelocCount; //+0c
	DWORD offsetWardenSetup; //+10
	DWORD _2[2];
	DWORD offsetImportAddressTable; //+1c
	DWORD nImportDllCount; //+20
	DWORD nSectionCount; //+24
};

struct SMemBlock_t {
	DWORD _1[6];
	DWORD cbSize; //+18
	DWORD _2[31];
	BYTE data[1]; //+98
};

struct WardenClient_t {
	WardenClientRegion_t* pWardenRegion; //+00
	DWORD cbSize; //+04
	DWORD nModuleCount; //+08
	DWORD param; //+0c
	DWORD fnSetupWarden; //+10
};

struct WardenIATInfo_t {
	DWORD offsetModuleName;
	DWORD offsetImportTable;
};

struct AttackStruct {
	DWORD dwAttackType;			//0x00
	UnitAny* lpPlayerUnit;		//0x04
	UnitAny* lpTargetUnit;		//0x08
	DWORD dwTargetX;			//0x0C
	DWORD dwTargetY;			//0x10
	DWORD _1;					//0x14
	DWORD _2;					//0x18
};

#pragma pack(push)
#pragma pack(1)

struct NPCMenu {
	DWORD dwNPCClassId;
	DWORD dwEntryAmount;
	WORD wEntryId1;
	WORD wEntryId2;
	WORD wEntryId3;
	WORD wEntryId4;	
	WORD _1;
	DWORD dwEntryFunc1;
	DWORD dwEntryFunc2; 
	DWORD dwEntryFunc3; 
	DWORD dwEntryFunc4;
	BYTE _2[5];
};

struct OverheadMsg {
	DWORD _1;
	DWORD dwTrigger;
	DWORD _2[2];
	char Msg[232];
};

#pragma pack(pop)

struct D2MSG {
	HWND myHWND;
	char lpBuf[256];
};


struct InventoryLayout {
	BYTE SlotWidth;
	BYTE SlotHeight;
	BYTE unk1;
	BYTE unk2;
	DWORD Left;
	DWORD Right;
	DWORD Top;
	DWORD Bottom;
	BYTE SlotPixelWidth;
	BYTE SlotPixelHeight;
};

struct MpqTable;

struct sgptDataTable {
	MpqTable*	pPlayerClass;
	DWORD		dwPlayerClassRecords;
	MpqTable*	pBodyLocs;
	DWORD		dwBodyLocsRecords;
	MpqTable*	pStorePage;
	DWORD		dwStorePageRecords;
	MpqTable*	pElemTypes;
};

#pragma warning ( pop )
#pragma optimize ( "", on )

#endif
