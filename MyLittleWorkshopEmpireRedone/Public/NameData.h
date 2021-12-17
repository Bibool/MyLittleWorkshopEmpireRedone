#ifndef NAMEDATA_H
#define NAMEDATA_H

struct SNameData
{
	SNameData( const char* name )
		: pszName( name  )
		, bIsUsed( false )
	{};

	SNameData( const char* name, bool bUsed = false )
		: pszName( name	 )
		, bIsUsed( bUsed )
	{};

	const char* pszName;
	bool bIsUsed;
};

#endif