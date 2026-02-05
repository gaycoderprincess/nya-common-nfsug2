class Player {
public:
	uint8_t _0[0x4];
	Car* pCar; // +4
	uint8_t _8[0x18];
	bool bManualTransmission; // +20
	uint8_t _21[0x2F];
	bool bFinishedRacing; // +50

	static inline auto pPlayersByIndex = (Player**)0x8900B4;
	static inline auto& NumPlayers = *(int*)0x8900BC;
};
static_assert(offsetof(Player, pCar) == 0x4);
static_assert(offsetof(Player, bManualTransmission) == 0x20);
static_assert(offsetof(Player, bFinishedRacing) == 0x50);