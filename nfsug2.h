#include <d3d9.h>

#include "types/bNode.h"
#include "types/RaceStarter.h"
#include "types/RaceParameters.h"
#include "types/TrackInfo.h"
#include "types/CarTypeInfo.h"
#include "types/GameSettings.h"
#include "types/PresetCar.h"
#include "types/GameFlowManager.h"
#include "types/RideInfo.h"
#include "types/SkipFE.h"

auto& UnlockAllThings = *(bool*)0x838464;
auto& ForceAllAICarsToBeThisType = *(int*)0x7FAA78;
auto& EvaluatingDrivingLines = *(bool*)0x8650B0;
auto& OnlineEnabled = *(bool*)0x865084;

auto& GameWindow = *(HWND*)0x870990;
auto& GameD3D = *(IDirect3D9**)0x870970;
auto& GameD3DDevice = *(IDirect3DDevice9**)0x870974;

auto bStringHash = (uint32_t(*)(const char*))0x43DB50;
auto FEHashUpper = (uint32_t(*)(const char*))0x505450;
auto FEngHashString = (uint32_t(*)(const char*, ...))0x50B990;

#include "nfsug2hooks.h"