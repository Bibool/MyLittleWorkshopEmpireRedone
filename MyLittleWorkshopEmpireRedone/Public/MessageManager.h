#ifndef MESSAGEMANAGER_H
#define MESSAGEMANAGER_H

#include "MessageType.h"

class GameManager;

class MessageManager
{
public:
	MessageManager() = default;
	~MessageManager() = default;

	// Prints a preset message based on the Enum value provided. 
	// Non dynamic messages are setup in config.h.
	void PrintMessage( const EMessageType& inType, const char* inMessage = nullptr, int atIndex = 0 );

	// Prints an error message to the cmd. It is defaulted to an input error message.
	// Takes a custom error message as parameter. It should be a description of the error.
	//  e.g: Error: <your error message will show here> \n. Error and \n is included.
	static void PrintError( const char* inCustomError = nullptr );

private:
	void PrintInventory();
	static void PrintPlayerTools();
	static void PrintPlayerMoney();
	void PrintShop() const;
	static void PrintJobs();
};

#endif