#ifndef VEHICLETYPE_H
#define VEHICLETYPE_H

#include <cstdint>

#ifndef ENUM_MIN
	#define ENUM_MIN 0
#endif // !ENUM_MIN

#ifndef ENUM_MAX
	#define ENUM_MAX 2
#endif // !ENUM_MAX


enum class EVehicleType : uint8_t
{
	CompactCar = ENUM_MIN,
	RacingCar,
	MotorCycle = ENUM_MAX
};

#endif