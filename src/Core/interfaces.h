#pragma once

#include "CustomGameMode/GameModeManager.h"
#include "D3D9EXWrapper/d3d9.h"
#include "D3D9EXWrapper/ID3D9EXWrapper_Device.h"
#include "Game/Player.h"
#include "Game/Room/Room.h"
#include "Network/NetworkManager.h"
#include "Network/OnlineGameModeManager.h"
#include "Network/OnlinePaletteManager.h"
#include "Network/ReplayUploadManager.h"
#include "Network/RoomManager.h"
#include "Palette/PaletteManager.h"
#include "SteamApiWrapper/SteamApiHelper.h"
#include "SteamApiWrapper/SteamFriendsWrapper.h"
#include "SteamApiWrapper/SteamMatchmakingWrapper.h"
#include "SteamApiWrapper/SteamNetworkingWrapper.h"
#include "SteamApiWrapper/SteamUserStatsWrapper.h"
#include "SteamApiWrapper/SteamUserWrapper.h"
#include "SteamApiWrapper/SteamUtilsWrapper.h"
#include "Settings.h"

struct interfaces_t
{
	SteamFriendsWrapper* pSteamFriendsWrapper;
	SteamMatchmakingWrapper* pSteamMatchmakingWrapper;
	SteamNetworkingWrapper* pSteamNetworkingWrapper;
	SteamUserWrapper* pSteamUserWrapper;
	SteamUserStatsWrapper* pSteamUserStatsWrapper;
	SteamUtilsWrapper* pSteamUtilsWrapper;

	IDirect3DDevice9Ex* pD3D9ExWrapper;

	NetworkManager* pNetworkManager;
	RoomManager* pRoomManager;
	SteamApiHelper* pSteamApiHelper;

	PaletteManager* pPaletteManager;
	OnlinePaletteManager* pOnlinePaletteManager;

	GameModeManager* pGameModeManager;
	OnlineGameModeManager* pOnlineGameModeManager;

	ReplayUploadManager* pReplayUploadManager;

	Player player1;
	Player player2;
};

struct gameVals_t
{
	int* pGameState;
	int* pGameMoney;
	int* pGameMode;
	int* pMatchState;
	int* pMatchTimer;
	int* pMatchRounds;

	int playerAvatarBaseAddr;
	int* playerAvatarAddr;
	int* playerAvatarColAddr;
	byte* playerAvatarAcc1;
	byte* playerAvatarAcc2;

	int isP1CPU;
	//DWORD P1InputJumpBackAdress;
	unsigned char* stageListMemory;
	int *stageSelect_X;
	int *stageSelect_Y;
	int *musicSelect_X;
	int *musicSelect_Y;

	/////////////////
	// New fields below
	/////////////////

	// *pIsHUDHidden is a bitfield:
	// 0x00 - hud is visible
	// 0x01 - hud is hidden (intro)
	// 0x02 - hud is hidden (astral)
	// 0x04 - loading icon is shown
	int* pIsHUDHidden;

	bool isFrameFrozen;
	unsigned framesToReach;
	unsigned* pFrameCount;

	D3DXMATRIX* viewMatrix;
	D3DXMATRIX* projMatrix;

	int* pEntityList;
	int entityCount;

	int onlineDelay;

	Room* pRoom;
	
};

struct gameProc_t
{
	HWND hWndGameWindow;
};
struct modValues_t {
	bool enableForeignPalettes = true; 
	int save_states_save_keycode;
	int save_states_load_keycode;
	int replay_takeover_load_keycode;
	int freeze_frame_keycode;
	int step_frames_keycode;
	int uploadReplayData;
	std::string uploadReplayDataHost; 
	std::string uploadReplayDataEndpoint;
	unsigned short uploadReplayDataPort;
	bool uploadReplayDataVeto = false; //this refers to when other players disable replay upload
};
//temporary placeholders until wrappers are created / final addresses updated
struct temps_t
{
	ISteamFriends** ppSteamFriends;
	ISteamMatchmaking** ppSteamMatchmaking;
	ISteamNetworking** ppSteamNetworking;
	ISteamUser** ppSteamUser;
	ISteamUserStats** ppSteamUserStats;
	ISteamUtils** ppSteamUtils;
};

extern interfaces_t g_interfaces;
extern gameProc_t g_gameProc;
extern gameVals_t g_gameVals;
extern temps_t g_tempVals;
extern modValues_t g_modVals;

void InitManagers();
void CleanupInterfaces();
