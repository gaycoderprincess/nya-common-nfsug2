class Player {
public:
	uint8_t _0[0x50];
	bool bFinishedRacing; // +50

	static inline auto pPlayersByIndex = (Player**)0x8900B4;
	static inline auto& NumPlayers = *(int*)0x8900BC;
};