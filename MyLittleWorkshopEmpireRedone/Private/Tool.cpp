#include "../Public/Tool.h"

#include "../Public/config.h"

Tool::Tool()
	: m_uiWear ( Tools::ToolInitialWear)
	, m_uiCost ( 0	   )
	, m_bOwned ( false )
	, m_pszName(  " "  )
{}

Tool::Tool( const char* name, const int cost )
	: m_uiWear ( Tools::ToolInitialWear )
	, m_uiCost ( cost  )
	, m_bOwned ( false )
	, m_pszName( name  )
{}