#include "../Public/MessageManager.h"

#include "../Public/config.h"
#include "../Public/JobManager.h"
#include "../Public/Player.h"
#include "../Public/Tool.h"
#include "../Public/ToolManager.h"
#include "../Public/Vehicle.h"
#include "../Public/Malfunction.h"
#include "../Public/GameManager.h"

#include <stdio.h>


MessageManager::MessageManager()
{
}

MessageManager::~MessageManager()
{
}

void MessageManager::PrintMessage( const EMessageType& inType, const char* inMessage, int atIndex )
{
	switch (inType)
	{
		case EMessageType::Default:
			printf( "All jobs have been completed. Generating more...\n " );
			break;
		case EMessageType::Welcome:
			printf( Messages::Welcome.c_str() );
			printf( Messages::Help.c_str() );
			break;
		case EMessageType::Help:
			printf( Messages::Help.c_str() );
			break;
		case EMessageType::Commands:
			printf( Messages::Commands.c_str() );
			break;
		case EMessageType::Shop:
			PrintShop();
			break;
		case EMessageType::Inventory:
			PrintInventory();
			break;
		case EMessageType::Jobs:
			PrintJobs();
			break;
		case EMessageType::JobFail:
			printf( "You didn't have the required tools or they had (0) Wear so you failed. Big sorry. \n" );
			break;
		case EMessageType::JobSuccess:
			break;
		case EMessageType::ExitComfirmation:
			printf( Messages::ExitComfirmation.c_str() );
			break;
		case EMessageType::BuySuccess:
			printf( "You successfully bought %s.\n", inMessage );
			PrintPlayerMoney();
			break;
		case EMessageType::BuyFail:
			printf( "You do not have enough money to buy this tool!" );
			PrintPlayerMoney();
			break;
	}
}

void MessageManager::PrintError( const char* inCustomError )
{
	if (!inCustomError)
		printf( Messages::InputError.c_str() );
	else
		printf( "Error: %s \n", inCustomError );
}

void MessageManager::PrintInventory()
{
	PrintPlayerMoney();
	PrintPlayerTools();
}

void MessageManager::PrintPlayerTools()
{
	printf( "  Tools:\n" );
	for (Tool* inTool : g_GameManager->GetToolManager()->GetTools() )
		if (inTool->IsOwned())
			printf( "  - %s. Wear: (%d).\n", inTool->GetName(), inTool->GetWear() );
}

void MessageManager::PrintPlayerMoney()
{
	printf( "  Money: \n     [($%d)]\n", g_GameManager->GetPlayer()->GetMoney() );
}

void MessageManager::PrintShop()
{
	printf( "  Shop content:\n" );

	for (int8_t i = 0; i != g_GameManager->GetToolManager()->GetTools().size(); ++i)
	{
		std::string toolOwned = "";
		if (g_GameManager->GetToolManager()->GetTools()[i]->IsOwned())
			toolOwned = ". You own this tool and it's Wear is (" + std::to_string( g_GameManager->GetToolManager()->GetTools()[i]->GetWear() ) + ").";
		printf( "  - %d: %s. Cost: (%d$)%s\n", i, g_GameManager->GetToolManager()->GetTools()[i]->GetName(), g_GameManager->GetToolManager()->GetTools()[i]->GetCost(), toolOwned.c_str() );
	}
}

void MessageManager::PrintJobs()
{
	int i = 0;
	for ( Vehicle* vehicle : g_GameManager->GetJobManager()->GetVehicles() )
	{
		if ( vehicle )
		{
			printf( "%s: Malfunctions: \n", vehicle->GetName() );
			for ( Malfunction* malfunction : vehicle->GetMalfunctions() )
			{
				if ( !malfunction->GetIsJobComplete() )
				{
					printf( "  - [%d] | %s. Reward: (%d$). Tools Required: \n", i, malfunction->GetName(), malfunction->GetJobReward() );

					for ( Tool* tool : malfunction->GetRequiredTools() )
					{
						printf( "	 - %s.\n", tool->GetName() );
					}
				}
				else
					printf( "  - [%d] | This job has already been completed. \n", i );
				++i;
			}
		}
	}
}