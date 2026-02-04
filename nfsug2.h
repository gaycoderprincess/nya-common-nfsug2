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
#include "types/CarPartDatabase.h"
#include "types/CAnimManager.h"
#include "types/cFrontendDatabase.h"
#include "types/Player.h"
#include "types/SkipFE.h"

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

auto& UnlockAllThings = *(bool*)0x838464;
auto& ForceAllAICarsToBeThisType = *(int*)0x7FAA78;
auto& EvaluatingDrivingLines = *(bool*)0x8650B0;
auto& OnlineEnabled = *(bool*)0x865084;
auto& MovieIsStarted = *(bool*)0x8383AC;
auto& WorldTimeElapsed = *(float*)0x865154;
auto& g_tweakIsDragRace = *(bool*)0x890108;

auto LZDecompress = (uint32_t(*)(uint8_t* pSrc, uint8_t* pDst))0x574670;

auto& GameWindow = *(HWND*)0x870990;
auto& GameD3D = *(IDirect3D9**)0x870970;
auto& GameD3DDevice = *(IDirect3DDevice9**)0x870974;

auto bInitTicker = (void(*)())0x43BD90;
auto FEngIsPackagePushed = (bool(*)(const char*))0x52CF60;

auto bStringHash = (uint32_t(*)(const char*))0x43DB50;
auto FEHashUpper = (uint32_t(*)(const char*))0x505450;
auto FEngHashString = (uint32_t(*)(const char*, ...))0x50B990;

#include "nfsug2hooks.h"
#include "nfsug2helpers.h"