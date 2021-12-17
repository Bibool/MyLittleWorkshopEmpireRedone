#include "Public/GameManager.h"
#include "Public/MessageManager.h"
#include "Public/InputManager.h"
#include "Public/Player.h"

#include "Public/debug.h"
#include "Public/config.h"

#include <iostream>
#include <cstdio>
#include <string>


void ParseCheats( int argc, char* argv[] );

// Entry and Exit point.
int main( const int argc, char* argv[] )
{
	g_GameManager = new GameManager();
	g_GameManager->GetMessageManager()->PrintMessage( EMessageType::Welcome );
	ParseCheats( argc, argv );

	// Game start. PLAYING = 1, EXIT = 0
	int gameIsRunning = 1;

	// Input will be stored in this string
	std::string input;

	// Game loop. Feed the input to the input manager.
	while (gameIsRunning)
	{
		std::getline( std::cin, input );
		gameIsRunning = g_GameManager->GetInputManager()->HandleInput( input );
	}

	// Delete the GameManager (which will in turn call delete on the others)
	SafeDelete( g_GameManager );

	return 0;
}

void ParseCheats( int argc, char* argv[] )
{
	constexpr int max = 1 + Cheats::Codes;
	if ((argc >= 2))
	{
		printf( "\n\n~~~~~~~~~~~~~~~~~~~~~* WOW *~~~~~~~~~~~~~~~~~~~~~\n" );
		for (int x = 1; x != max; ++x)
		{
			if ( strcmp( argv[x], Cheats::AddMoney.c_str() ) == 0 )
			{
				g_GameManager->GetPlayer()->Cheat( ECheats::Money );
				printf( Messages::AddMoneyCheatEvent.c_str() );
			}
			if ( strcmp( argv[x], Cheats::UnlockTools.c_str() ) == 0 )
			{
				g_GameManager->GetPlayer()->Cheat( ECheats::Tools );
				printf( Messages::UnlockToolsCheatEvent.c_str() );
			}
		}
		printf( "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );
	}
}