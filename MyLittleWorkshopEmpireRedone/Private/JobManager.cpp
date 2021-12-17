#include "../Public/JobManager.h"

#include "../Public/config.h"
#include "../Public/random.h"
#include "../Public/Vehicle.h"
#include "../Public/debug.h"
#include "../Public/Malfunction.h"
#include "../Public/Player.h"
#include "../Public/GameManager.h"
#include "../Public/ToolManager.h"
#include "../Public/MalfunctionManager.h"
#include "../Public/MessageManager.h"

JobManager::JobManager()
	: m_iNameIndex( 0 )
	, m_iMalfunctionIndex( 0 )
	, m_iJobsCompleted( 0 )
	, m_apcJobs()
{
}

JobManager::~JobManager()
{
	for (auto element : m_apcCurrentVehicles)
	{
		SafeDelete( element );
	}
}

const std::list<Vehicle*>& JobManager::GetVehicles() const
{
	return m_apcCurrentVehicles;
}

Malfunction** JobManager::GetJobs()
{
	return m_apcJobs;
}

void JobManager::Init()
{
	GeneratorJobs();
}

void JobManager::SelectJob( int atIndex )
{
	if (m_apcJobs[atIndex])
	{
		Malfunction* job = m_apcJobs[atIndex];

		int iCounter = 0;
		std::list<Tool*> toolsToUse;

		if (!job->GetIsJobComplete())
		{
			for (Tool* tool : job->GetRequiredTools())
			{
				for (int x = 0; x != g_GameManager->GetToolManager()->GetTools().size(); ++x)
				{
					Tool* it = g_GameManager->GetToolManager()->GetTools()[x];
					if (it == tool && it->IsOwned() && it->GetWear())
					{
						toolsToUse.push_back( tool );
						++iCounter;
						break;
					}
				}
			}

			if (iCounter == job->GetRequiredTools().size())
			{
				printf( "You have the required tools: \n" );
				for (auto tool : toolsToUse)
				{
					printf( "	 - [%s]. Wear: [%d].\n", tool->GetName(), tool->GetWear() );
				}

				for (auto tool : toolsToUse)
				{
					if (!GetRandomNumInRange( 0, 1 ))
					{
						tool->DecreaseWear( 1 );
						printf( "OH NO! Your [%s] got worn down and now has [%d] Wear.\n", tool->GetName(), tool->GetWear() );
					}
				}

				g_GameManager->GetPlayer()->Payday( m_apcJobs[atIndex]->GetJobReward() );
				printf( "You did the job! Cash Money Rewarded: [$%d]. You now have: [$%d]. \n", m_apcJobs[atIndex]->GetJobReward(), g_GameManager->GetPlayer()->GetMoney() );
				job->SetJobCompleted( true );
				CheckIfAllJobsFinished();
			}
			else
			{
				job->SetJobCompleted( true );
				g_GameManager->GetMessageManager()->PrintMessage( EMessageType::JobFail );
				CheckIfAllJobsFinished();
			}
		}
		else
		{
			printf( "This job is finished. Please try another. \n" );
		}
	}
}

void JobManager::GeneratorJobs()
{
	int iCounter = 0;
	for (int i = 0; i != MAX_JOBS; ++i)
	{
		if (iCounter != MAX_JOBS)
		{
			EVehicleType vehicleType = EVehicleType( GetRandomNumInRange( ENUM_MIN, ENUM_MAX ) );
			Vehicle* newVehicle = new Vehicle( GetVehicleName( vehicleType ), vehicleType );
			int numMalfunctions = GetNumMalfunctionForVehicle( vehicleType );

			for (int n = 0; n != numMalfunctions; ++n)
			{
				if (iCounter != MAX_JOBS)
				{
					Malfunction* malfunctionToAdd = GetMalfunction( vehicleType );
					newVehicle->AddMalfunction( malfunctionToAdd );
					m_apcJobs[iCounter] = malfunctionToAdd;
					++iCounter;

				}
				else
					break;
			}

			m_apcMalfunctionsFound.clear();
			m_apcCurrentVehicles.push_back( newVehicle );
		}
		else
			break;
	}
	m_apcMalfunctionsFound.clear();
	m_apszNames.clear();
	m_iNameIndex = 0;
	m_iMalfunctionIndex = 0;
}

const char* JobManager::GetVehicleName( const EVehicleType& vehicleType )
{
	static const char* inName = nullptr;
	std::list <const char*> inNames;
	switch (vehicleType)
	{
		case EVehicleType::CompactCar:
			inNames = Vehicles::CompactCar::Names;
			break;
		case EVehicleType::RacingCar:
			inNames = Vehicles::RacingCar::Names;
			break;
		case EVehicleType::MotorCycle:
			inNames = Vehicles::MotorCycle::Names;
			break;
	}

	for (auto name : inNames)
	{
		bool bNamePreviouslyUsed = false;
		for (auto savedNames : m_apszNames)
		{
			if (name == savedNames)
				bNamePreviouslyUsed = true;
		}

		if (inName != name && !bNamePreviouslyUsed)
		{
			inName = name;
			++m_iNameIndex;
			break;
		}
	}

	m_apszNames.push_back( inName );
	return inName;
}

Malfunction* JobManager::GetMalfunction( const EVehicleType& vehicleType )
{
	Malfunction* malfunctionToAdd = new Malfunction();
	bool bDuplicateFoundInArray = false;

	for (auto malfunction : g_GameManager->GetMalfunctionManager()->GetMalfunctions())
	{
		if (malfunction->GetVehicleType() == vehicleType)
		{
			if (m_apcMalfunctionsFound.size())
			{
				// check against current array.
				for (auto currentMalfunctions : m_apcMalfunctionsFound)
				{
					if (currentMalfunctions->GetName() == malfunction->GetName())
					{
						bDuplicateFoundInArray = true;
						break;
					}
					//else
						
				}
			}
			// SCENARIO: NO CURRENT MALFUNCTIONS ADDED -> SET DATA
			else
			{
				malfunctionToAdd->SetMalfunctionData( malfunction->GetMalfunctionData() );
				malfunctionToAdd->SetRequiredTools( malfunction->GetRequiredTools() );
				break;
			}
			// SCENARIO: NO DUPLICATE FOUND -> SET DATA
			if (!bDuplicateFoundInArray)
			{
				malfunctionToAdd->SetMalfunctionData( malfunction->GetMalfunctionData() );
				malfunctionToAdd->SetRequiredTools( malfunction->GetRequiredTools() );
				break;
			}
			bDuplicateFoundInArray = false;
		}
	}

	m_apcMalfunctionsFound.push_back( malfunctionToAdd );
	return malfunctionToAdd;
}

int JobManager::GetNumMalfunctionForVehicle( const EVehicleType& vehicleType ) const
{
	int numMalfunctions = 0;
	switch (vehicleType)
	{
		case EVehicleType::CompactCar:
			numMalfunctions = GetRandomNumInRange( 1, Malfunctions::CompactCar::MaxMalfunctions );
			break;
		case EVehicleType::RacingCar:
			numMalfunctions = GetRandomNumInRange( 1, Malfunctions::RacingCar::MaxMalfunctions );
			break;
		case EVehicleType::MotorCycle:
			numMalfunctions = GetRandomNumInRange( 1, Malfunctions::MotorCycle::MaxMalfunctions );
			break;
	}
	return numMalfunctions;
}

void JobManager::CleanUp()
{
	for (auto element : m_apcCurrentVehicles)
	{
		SafeDelete( element );
	}
	m_apcCurrentVehicles.clear();
	m_apcMalfunctionsFound.clear();
	m_apszNames.clear();
	m_iNameIndex = 0;
	m_iMalfunctionIndex = 0;
	m_iJobsCompleted = 0;
}

void JobManager::CheckIfAllJobsFinished()
{
	++m_iJobsCompleted;
	if (m_iJobsCompleted == MAX_JOBS)
	{
		g_GameManager->GetMessageManager()->PrintMessage( EMessageType::Default );
		CleanUp();
		GeneratorJobs();
	}
}