typedef int eTuningSetting;
class FECarRecord {
public:
	uint8_t _4[0x4];
	uint32_t Handle; // +8
	float PerformanceMeasure; // +C
	uint8_t _10[0x8];

	virtual void _vf0();
	virtual int GetCarType();
	virtual uint32_t GetCarTypeNameHash();
	virtual void BuildRide(int, RideInfo*, eTuningSetting);
};
static_assert(sizeof(FECarRecord) == 0x18);
static_assert(offsetof(FECarRecord, Handle) == 0x8);

class FEStockCar : public FECarRecord {
	uint32_t CarType; // +18
};
static_assert(sizeof(FEStockCar) == 0x1C);

class PresetCarSlot {
public:
	uint8_t _0[0x8];
	uint32_t CarTypeHash; // +8
	uint32_t InstalledParts[CARSLOTID_NUM]; // +C
	uint8_t _2B4[0x94]; // performance data
};
static_assert(offsetof(PresetCarSlot, CarTypeHash) == 0x8);

class FECarConfig : public FECarRecord {
public:
	PresetCarSlot PresetCar; // +18
	uint8_t _360[0xD4];
};
static_assert(sizeof(FECarConfig) == 0x434);

class FECareerCar : public FECarConfig {
public:
	uint8_t _434[0x3C4];
};
static_assert(sizeof(FECareerCar) == 0x7F8);

class FEOnlineCareerCar : public FECarConfig {
public:
	uint8_t _434[0x4];
};
static_assert(sizeof(FEOnlineCareerCar) == 0x438);

class SponsorCarInfo : public FECarRecord {
	uint32_t PresetName; // +18
};
static_assert(sizeof(SponsorCarInfo) == 0x1C);

class FEPlayerCarDB {
public:
	FEStockCar StockCars[48]; // +0
	int NumStockCars; // +540
	FECarConfig TunerCars[20]; // +544
	FECareerCar CareerCars[5]; // +5954
	int NumCareerCars; // +812C
	FEOnlineCareerCar OnlineCareerCars[6]; // +8130
	int NumOnlineCareerCars; // +9A80
	SponsorCarInfo SponsorCars[12]; // +9A84
	int NumSponsorCars; // +9BD4
	uint8_t _9BD8[0x16C];
};
static_assert(sizeof(FEPlayerCarDB) == 0x9D44);
static_assert(offsetof(FEPlayerCarDB, NumStockCars) == 0x540);
static_assert(offsetof(FEPlayerCarDB, CareerCars) == 0x5954);
static_assert(offsetof(FEPlayerCarDB, NumCareerCars) == 0x812C);
static_assert(offsetof(FEPlayerCarDB, OnlineCareerCars) == 0x8130);
static_assert(offsetof(FEPlayerCarDB, NumOnlineCareerCars) == 0x9A80);
static_assert(offsetof(FEPlayerCarDB, SponsorCars) == 0x9A84);
static_assert(offsetof(FEPlayerCarDB, NumSponsorCars) == 0x9BD4);

class UserProfile {
public:
	char m_aProfileName[16]; // +0
	uint8_t _10[0x3A0];
	FEPlayerCarDB PlayersCarStable; // +3B0
	uint8_t _A0F4[0xA58];
};
static_assert(sizeof(UserProfile) == 0xAB4C);

class cFrontendDatabase {
public:
	uint8_t _0[0x10];
	UserProfile CurrentUserProfiles[2]; // +10

	static inline auto NotifyExitRaceToFrontend = (void(__thiscall*)(cFrontendDatabase*, bool))0x503040;
};
auto& FEDatabase = *(cFrontendDatabase*)0x83A9D0;