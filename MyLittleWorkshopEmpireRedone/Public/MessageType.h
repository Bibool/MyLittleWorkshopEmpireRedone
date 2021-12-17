#ifndef MESSAGETYPE_H
#define MESSAGETYPE_H

#include <cstdint>

enum class EMessageType : uint8_t
{
	Default = 0,
	Welcome,
	Help,
	Commands,
	Shop,
	BuySuccess,
	BuyFail,
	Inventory,
	Jobs,
	JobSuccess,
	JobFail,
	ExitComfirmation
};

#endif