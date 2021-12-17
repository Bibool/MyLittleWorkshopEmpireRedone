#ifndef	_MALFUNCTION_H_
#define	_MALFUNCTION_H_

#include "MalfunctionData.h"
#include "Tool.h"

#include <list>


class Malfunction
{
public:
	Malfunction();
	Malfunction( const Malfunction& malfunction );
	Malfunction( const SMalfunctionData& init );

	void AddRequiredTool( Tool* newTool );
	std::list<Tool*>	GetRequiredTools() const;
	const char*			GetName() const;
	const EVehicleType& GetVehicleType() const;
	bool GetIsJobComplete() const;
	int GetJobReward() const;
	const SMalfunctionData& GetMalfunctionData() const;
	void SetJobCompleted(bool bCompleted);
	void SetMalfunctionData( const SMalfunctionData& inData );
	void SetRequiredTools( const std::list<Tool*>& inTools );

private:
	SMalfunctionData m_sData;
	std::list<Tool*> m_apcRequiredTools;
	bool m_bJobComplete = false;
};

#endif