#ifndef _MALFUNCTIONDATA_H_
#define	_MALFUNCTIONDATA_H_

#include "VehicleType.h"
#include <list>

struct SMalfunctionData
{
	SMalfunctionData()
		: pszName	( 0 )
		, iReward	( 0 )
		, apszTools	( 0 )
		, eType( EVehicleType::CompactCar )
	{}

	SMalfunctionData( const char* name, const int cost, const std::list<const char*>& tools, const EVehicleType& forType )
		: pszName	( name  )
		, iReward	( cost  )
		, apszTools	( tools )
		, eType		( forType )
	{}

	
	const char* pszName;
	int iReward;
	std::list<const char*> apszTools;
	EVehicleType eType;

};

#endif