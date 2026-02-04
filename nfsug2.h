#include <d3d9.h>

#include "types/bNode.h"
#include "types/bVector.h"
#include "types/RaceStarter.h"
#include "types/RaceParameters.h"
#include "types/TrackInfo.h"
#include "types/CarTypeInfo.h"
#include "types/GameSettings.h"
#include "types/PresetCar.h"
#include "types/GameFlowManager.h"
#include "types/RideInfo.h"
#include "types/Car.h"
#include "types/SkipFE.h"

class cFrontendDatabase {
public:
	static inline auto NotifyExitRaceToFrontend = (void(__thiscall*)(cFrontendDatabase*, bool))0x503040;
};
auto& FEDatabase = *(cFrontendDatabase*)0x83A9D0;

class CAnimManager {
public:
	static inline auto IsPlayingIntroNIS = (bool(__thiscall*)(CAnimManager*))0x430350;
	static inline auto IsPlayingEndNIS = (bool(__thiscall*)(CAnimManager*))0x430420;
	static inline auto EndNIS_SafeRemove = (void(__thiscall*)(CAnimManager*))0x43B640;
};
auto& TheAnimManager = *(CAnimManager*)0x827E88;

class Race {
public:
	static inline auto GetCountdownNumberToDisplay = (int(__thiscall*)(Race*))0x5EEA40;
};
auto& pCurrentRace = *(Race**)0x890118;

class RaceCoordinator {
public:
	int RaceState;

	static inline auto TheRaceHasFinished = (void(__thiscall*)(RaceCoordinator*))0x60AAA0;
};
auto& pRaceCoordinator = *(RaceCoordinator**)0x8900D8;

class Player {
public:
	uint8_t _0[0x50];
	bool bFinishedRacing; // +50

	static inline auto pPlayersByIndex = (Player**)0x8900B4;
	static inline auto& NumPlayers = *(int*)0x8900BC;
};

auto& UnlockAllThings = *(bool*)0x838464;
auto& ForceAllAICarsToBeThisType = *(int*)0x7FAA78;
auto& EvaluatingDrivingLines = *(bool*)0x8650B0;
auto& OnlineEnabled = *(bool*)0x865084;
auto& MovieIsStarted = *(bool*)0x8383AC;

auto& GameWindow = *(HWND*)0x870990;
auto& GameD3D = *(IDirect3D9**)0x870970;
auto& GameD3DDevice = *(IDirect3DDevice9**)0x870974;

auto FEngIsPackagePushed = (bool(*)(const char*))0x52CF60;

auto bStringHash = (uint32_t(*)(const char*))0x43DB50;
auto FEHashUpper = (uint32_t(*)(const char*))0x505450;
auto FEngHashString = (uint32_t(*)(const char*, ...))0x50B990;

#include "nfsug2hooks.h"