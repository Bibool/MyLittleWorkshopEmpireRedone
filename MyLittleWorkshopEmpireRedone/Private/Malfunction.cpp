#include "../Public/Malfunction.h"

Malfunction::Malfunction()
	: m_sData ( SMalfunctionData() )
{
}

Malfunction::Malfunction( const Malfunction& malfunction )
	: m_sData ( malfunction.m_sData )
{
}

Malfunction::Malfunction( const SMalfunctionData& init )
	: m_sData ( init )
{
}

void Malfunction::AddRequiredTool( Tool* newTool )
{
	m_apcRequiredTools.push_back( newTool );
}

std::list<Tool*> Malfunction::GetRequiredTools() const
{
	return m_apcRequiredTools;
}

const char* Malfunction::GetName() const
{
	return m_sData.pszName;
}

const EVehicleType& Malfunction::GetVehicleType() const
{
	return m_sData.eType;
}

bool Malfunction::GetIsJobComplete() const
{
	return m_bJobComplete;
}

int Malfunction::GetJobReward() const
{
	return m_sData.iReward;
}

const SMalfunctionData& Malfunction::GetMalfunctionData() const
{
	return m_sData;
}

void Malfunction::SetJobCompleted( bool bCompleted )
{
	m_bJobComplete = bCompleted;
}

void Malfunction::SetMalfunctionData( const SMalfunctionData& inData )
{
	m_sData = inData;
}

void Malfunction::SetRequiredTools( const std::list<Tool*>& inTools )
{
	m_apcRequiredTools = inTools;
}
