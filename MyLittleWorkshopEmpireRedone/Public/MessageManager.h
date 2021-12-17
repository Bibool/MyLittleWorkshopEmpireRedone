#ifndef _MESSAGEMANAGER_H_
#define _MESSAGEMANAGER_H_

#include "MessageType.h"

class GameManager;

class MessageManager
{
public:
	MessageManager();
	~MessageManager();

	// Prints a preset message based on the Enum value provided. 
	// Non dynamic messages are setup in config.h.
	void PrintMessage( const EMessageType& inType, const char* inMessage = nullptr, int atIndex = 0 );

	// Prints an error message to the cmd. It is defaulted to an input error message.
	// Takes a custom error message as parameter. It should be a description of the error.
	//  e.g: Error: <your error message will show here> \n. Error and \n is included.
	void PrintError( const char* inCustomError = nullptr );

private:
	void PrintInventory();
	void PrintPlayerTools();
	void PrintPlayerMoney();
	void PrintShop();
	void PrintJobs();
};

#endif // !_MESSAGEMANAGER_H_