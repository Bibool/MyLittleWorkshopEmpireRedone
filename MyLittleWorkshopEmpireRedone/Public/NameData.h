#ifndef _NAMEDATA_H_
#define _NAMEDATA_H_

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