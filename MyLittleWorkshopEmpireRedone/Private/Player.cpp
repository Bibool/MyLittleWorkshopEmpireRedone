#include "../Public/Player.h"

#include "../Public/config.h"
#include "../Public/ToolManager.h"
#include "../Public/Tool.h"
#include "../Public/MessageManager.h"
#include "../Public/GameManager.h"

Player::Player()
	: m_iMoney		( PlayerInit::StartingMoney )
{
}

void Player::Init()
{
	for (Tool* inTool : g_GameManager->GetToolManager()->GetTools())
	{
		if (inTool->GetName() == PlayerInit::FirstStartingToolName || inTool->GetName() == PlayerInit::SecondStartingToolName)
		{
			inTool->SetIsOwned( true );
		}
	}
}

void Player::Cheat( const ECheats& inCheat )
{
	switch (inCheat)
	{
		case ECheats::Money:
			Payday( Cheats::NumMoney );
			break;
		case ECheats::Tools:
			UnlockAllTools();
			break;
	}
}

void Player::PurchaseTool( int toolIndex )
{
	Tool* toolAtIndex = g_GameManager->GetToolManager()->GetTools().at( toolIndex );

	if ( toolAtIndex )
	{
		if (toolAtIndex->GetCost() <= m_iMoney)
		{
			DeduceMoney( toolAtIndex->GetCost() );

			if (toolAtIndex->IsOwned())
			{
				toolAtIndex->IncreaseWear( Tools::ToolInitialWear );
				const std::string wearUpgraded = toolAtIndex->GetName() + std::string(". You already owned this tool so it's wear has been increased");
				g_GameManager->GetMessageManager()->PrintMessage( EMessageType::BuySuccess, wearUpgraded.c_str() );
			}
			else
			{
				toolAtIndex->SetIsOwned( true );
				g_GameManager->GetMessageManager()->PrintMessage( EMessageType::BuySuccess, toolAtIndex->GetName() );
			}
		}
		else
		{
			g_GameManager->GetMessageManager()->PrintMessage( EMessageType::BuyFail );
		}
	}
}

int Player::GetMoney() const
{
	return m_iMoney;
}

void Player::DeduceMoney( const int inAmountToDeduce )
{
	m_iMoney -= inAmountToDeduce;
}

void Player::Payday( int iAmount )
{
	m_iMoney += iAmount;
}

void Player::UnlockAllTools()
{
	for (Tool* inTool : g_GameManager->GetToolManager()->GetTools())
	{
		inTool->SetIsOwned( true );
	}
}