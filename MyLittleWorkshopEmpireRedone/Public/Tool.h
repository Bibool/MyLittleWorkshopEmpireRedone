#ifndef TOOL_H
#define TOOL_H

class Tool
{
public:
	Tool();
	Tool( const char* name, const int cost );
	~Tool() = default;

	// Getters
	int			GetWear()	const { return m_uiWear;  }
	int			GetCost()	const { return m_uiCost;  }
	bool		IsOwned()	const { return m_bOwned;  }
	const char* GetName()	const { return m_pszName; }

	// Setters
	void		DecreaseWear( const int inAmount )	{ m_uiWear -= inAmount; }
	void		IncreaseWear( const int inAmount )	{ m_uiWear += inAmount; }
	void		SetIsOwned	( const bool bUsed )	{ m_bOwned = bUsed;  }

private:
	int			m_uiWear;
	int			m_uiCost;
	bool		m_bOwned;
	const char* m_pszName;

};

#endif