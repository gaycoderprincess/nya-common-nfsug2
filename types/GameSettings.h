class GameSettings {
public:
	int VERSION;
	int SIZE;
	int g_CarEnvironmentMapEnable;
	int g_CarEnvironmentMapUpdateData;
	int g_CarShadowEnable;
	int g_CarHeadlightEnable;
	int g_CarLightingEnable;
	int g_CarDamageEnable;
	int g_CrowdEnable;
	int g_RoadReflectionEnable;
	int g_FogEnable;
	int g_MotionBlurEnable;
	int g_LightStreaksEnable;
	int g_LightGlowEnable;
	int g_AnimatedTextureEnable;
	int g_ParticleSystemEnable;
	int g_DepthOfFieldEnable;
	int g_WorldLodLevel;
	int g_CarLodLevel;
	int g_OverBrightEnable;
	int g_BleachByPassEnable;
	int g_TintingEnable;
	int g_FSAALevel;
	int g_HorizonFogEnable;
	int g_RainEnable;
	int dword_870D14;
	int g_TextureFiltering;
	int g_RacingResolution;
	int dword_870D20;
	int g_VSyncOn;
};
GameSettings TheGameSettings = *(GameSettings*)0x870CB0;

auto GetRacingResolution = (void(__stdcall*)(int*, int*))0x5BF610; // technically a thiscall but ecx is never used!