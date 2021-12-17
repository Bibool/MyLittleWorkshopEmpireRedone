#include "../Public/MalfunctionManager.h"

#include "../Public/debug.h"
#include "../Public/Malfunction.h"
#include "../Public/ToolManager.h"
#include "../Public/GameManager.h"

MalfunctionManager::MalfunctionManager()
	: m_apcMalfunctions()
{}

MalfunctionManager::~MalfunctionManager()
{
	for (auto malfunction : m_apcMalfunctions)
	{
		SafeDelete( malfunction );
	}
}

const std::array<Malfunction*, Malfunctions::MaxMalfunctions>& MalfunctionManager::GetMalfunctions() const
{
	return m_apcMalfunctions;
}

void MalfunctionManager::Init()
{
	GenerateMalfunctions();
}

void MalfunctionManager::GenerateMalfunctions()
{
	int index = 0;

	for (int i = 0; i != Malfunctions::CompactCar::MaxMalfunctions; ++i)
	{
		m_apcMalfunctions.at( i ) = new Malfunction( Malfunctions::CompactCarMalfunctions[i] );
		for (const auto tool : Malfunctions::CompactCarMalfunctions->apszTools)
		{
			m_apcMalfunctions.at( i )->AddRequiredTool( g_GameManager->GetToolManager()->FindTool( tool ) );
		}
		++index;
	}
	for ( int i = 0; i != Malfunctions::RacingCar::MaxMalfunctions; ++i )
	{
		m_apcMalfunctions.at( index ) = new Malfunction( Malfunctions::RacingCarMalfunctions[i] );
		for (const auto tool : Malfunctions::RacingCarMalfunctions->apszTools)
		{
			m_apcMalfunctions.at( index )->AddRequiredTool( g_GameManager->GetToolManager()->FindTool( tool ) );
		}
		++index;
	}
	for ( int i = 0; i != Malfunctions::MotorCycle::MaxMalfunctions; ++i )
	{
		m_apcMalfunctions.at( index ) = new Malfunction( Malfunctions::MotorCycleMalfunctions[i] );
		for (const auto tool : Malfunctions::MotorCycleMalfunctions->apszTools)
		{
			m_apcMalfunctions.at( index )->AddRequiredTool( g_GameManager->GetToolManager()->FindTool( tool ) );
		}
		++index;
	}
}