class CAnimManager {
public:
	static inline auto IsPlayingIntroNIS = (bool(__thiscall*)(CAnimManager*))0x430350;
	static inline auto IsPlayingEndNIS = (bool(__thiscall*)(CAnimManager*))0x430420;
	static inline auto EndNIS_SafeRemove = (void(__thiscall*)(CAnimManager*))0x43B640;
};
auto& TheAnimManager = *(CAnimManager*)0x827E88;