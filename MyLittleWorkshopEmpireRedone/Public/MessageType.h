#ifndef _MESSAGETYPE_H_
#define _MESSAGETYPE_H_

#include <stdint.h>

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