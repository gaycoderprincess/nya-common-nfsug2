enum eSetRideInfoReasons {
	SET_RIDE_INFO_REASON_VINYL = 0,
	SET_RIDE_INFO_REASON_LOAD_CAR = 1,
	SET_RIDE_INFO_REASON_CATCHALL = 2,
};

class GarageMainScreen {
public:
	static inline auto SetRideInfo = (void(__thiscall*)(GarageMainScreen*, RideInfo*, eSetRideInfoReasons))0x4D8C70;
};
auto& TopOrFullScreenRide = *(RideInfo*)0x8371B0;