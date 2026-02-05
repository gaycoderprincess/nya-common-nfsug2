enum EVIEW_ID {
	EVIEW_FIRST = 0,
	EVIEW_FLAILER = 0,
	NUM_RVM_VIEWS = 1,
	EVIEW_FIRST_PLAYER = 1,
	EVIEW_FIRST_RENDER = 1,
	EVIEW_PLAYER1 = 1,
	EVIEW_PLAYER2 = 2,
	NUM_PLAYER_VIEWS = 3,
};

class eViewPlatInfo;
class eViewPlatInterface {
public:
	eViewPlatInfo* PlatInfo;

	static inline auto GetScreenPosition = (void(__thiscall*)(eViewPlatInterface*, bVector3* screen_position, const bVector3* world_position))0x5BC4A0;
};

class eView : public eViewPlatInterface {
public:
	uint8_t _4[0x6C];
};
static_assert(sizeof(eView) == 0x70);

auto eViews = (eView*)0x832DE0;