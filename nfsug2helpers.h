namespace NyaHelpers {
	PresetCar CreatePresetCar(FECarConfig* record, const char* presetName) {
		auto typeInfo = GetCarTypeInfoFromHash(record->PresetCar.CarTypeHash);

		PresetCar car;
		strcpy_s(car.CarTypeName, 32, typeInfo->CarTypeName);
		strcpy_s(car.PresetName, 32, presetName);
		car.PhysicsLevel = 3; // todo

		for (int i = 0; i < CARSLOTID_NUM; i++) {
			car.PartNameHashes[i] = record->PresetCar.InstalledParts[i];
		}
		return car;
	}
}