enum eLocationName {
	UPPER_CLASS = 0,
	CITY_CORE = 1,
	SUBURBAN_HILLS = 2,
	INDUSTRIAL_PARK = 3,
	AIRPORT = 4,
	MODE_SPECIFIC = 5,
};

enum eDriftType {
	VS_AI = 0,
	DOWNHILL = 1,
	TEAM = 2,
};

class TrackInfo {
public:
	char Name[32];
	char TrackDirectory[32];
	char RegionName[8];
	char RegionDirectory[32];
	int LocationNumber;
	char LocationDirectory[16];
	eLocationName LocationName;
	eDriftType DriftType;
	char IsValid;
	char Point2Point; // +85
	uint8_t _86[0xA2];

	static inline auto& TrackInfoTable = *(TrackInfo**)0x883DA0;
	static inline auto& NumTrackInfo = *(int*)0x883DA4;
	static inline auto& LoadedTrackInfo = *(TrackInfo**)0x883DAC;

	static inline auto GetTrackInfo = (TrackInfo*(*)(int track_number))0x5D3E40;
};
static_assert(sizeof(TrackInfo) == 0x128);
static_assert(offsetof(TrackInfo, Point2Point) == 0x85);