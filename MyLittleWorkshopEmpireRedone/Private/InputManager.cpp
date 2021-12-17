#include "../Public/InputManager.h"

#include "../Public/config.h"
#include "../Public/MessageManager.h"
#include "../Public/Player.h"
#include "../Public/JobManager.h"
#include "../Public/GameManager.h"

#include <iostream>
#include <stdio.h>
#include <stddef.h>

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

int InputManager::HandleInput( const std::string& input )
{
	int gameStatus = CONTINUE;
	const char inputToChar = input.at( 0 );

	// Handle Help
	if (CharCompare( inputToChar, *Input::HelpKey ))
	{
		if ( IsSingleChar( input ) )
			g_GameManager->GetMessageManager()->PrintMessage( EMessageType::Commands );
	}

	// Handle Exit
	if (CharCompare( inputToChar, *Input::ExitKey ))
	{
		if ( IsSingleChar( input ) )
		{
			g_GameManager->GetMessageManager()->PrintMessage( EMessageType::ExitComfirmation );

			std::string inputExitChoice;
			std::getline( std::cin, inputExitChoice );

			if (IsSingleChar( inputExitChoice ))
			{
				if (CharCompare( inputExitChoice.at( 0 ), *Input::ConfirmKey ))
					gameStatus = EXIT;
				else if (CharCompare( inputExitChoice.at( 0 ), *Input::CancelKey ))
					g_GameManager->GetMessageManager()->PrintMessage( EMessageType::Help );
				else
					g_GameManager->GetMessageManager()->PrintError();
			}
			else
				g_GameManager->GetMessageManager()->PrintError();
		}
	}

	// Handle Jobs
	if (CharCompare( inputToChar, *Input::JobsKey ))
	{
		if ( IsSingleChar( input ) )
			g_GameManager->GetMessageManager()->PrintMessage( EMessageType::Jobs );
	}

	// Handle Job at index
	if (CharCompare( inputToChar, *Input::AcceptJobKey ))
	{
		const int selection = input.at( 1 ) - '0';

		// Cannot be over single digit and above (max index)
		if (input.length() < 3 && selection <= MAX_INPUT_INDEX)
			g_GameManager->GetJobManager()->SelectJob( selection );
		else
			g_GameManager->GetMessageManager()->PrintError( "Index chosen is invalid." );
	}

	// Handle Shop
	if (CharCompare( inputToChar, *Input::ShopKey ))
	{
		if ( IsSingleChar( input ) )
			g_GameManager->GetMessageManager()->PrintMessage( EMessageType::Shop );
	}	

	// Handle Tool at index
	if (CharCompare( inputToChar, *Input::BuyToolKey ))
	{
		// Necessary check to see if just B wasn't put in otherwise it would crash.
		if ( !IsSingleChar( input ) )
		{
			const int selection = input.at( 1 ) - '0';

			if (input.length() < 3 && selection <= MAX_TOOLS_INDEX )
				g_GameManager->GetPlayer()->PurchaseTool( selection );
			else
				g_GameManager->GetMessageManager()->PrintError( "Index chosen is invalid." );
		}
		else
			g_GameManager->GetMessageManager()->PrintError();
	}

	// Handle Inventory
	if (CharCompare( inputToChar, *Input::InventoryKey ))
	{
		if ( IsSingleChar( input ) )
			g_GameManager->GetMessageManager()->PrintMessage( EMessageType::Inventory );
	}

	// Handle Clear
	if (CharCompare( inputToChar, *Input::ClearKey ))
	{
		if (IsSingleChar( input ))
		{
			system( "cls" );
			g_GameManager->GetMessageManager()->PrintMessage( EMessageType::Help );
		}
	}

	// Wrong input scenario.
	static bool bIncorrectInput = false;
	for (const char* Character : Input::Keys)
	{
		if (!CharCompare( inputToChar, *Character ))
			bIncorrectInput = true;
		else
		{
			bIncorrectInput = false;
			break;
		}
	}
	if (bIncorrectInput)
	{
		g_GameManager->GetMessageManager()->PrintError();
		gameStatus = CONTINUE;
	}

	return gameStatus;
}

bool InputManager::IsSingleChar( const std::string input ) const
{
	return input.length() == 1;
}

bool InputManager::CharCompare( const char input, const char inKey ) const
{
	return ( input == tolower( inKey ) || input == toupper( inKey ) );
}