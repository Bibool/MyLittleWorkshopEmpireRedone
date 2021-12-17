#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Cheats.h"

#include <array>

class Player
{
public:
	Player();
	~Player();

	// Initializes the tools the player starts with.
	void Init();

	void Cheat( const ECheats& inCheat );

	// Buys tool at given index.
	void PurchaseTool( int toolIndex );

	// Gets the current money.
	int GetMoney() const;

	// Deduces the money by given amount.
	void DeduceMoney( const int inAmountToDeduce );

	void Payday( int iAmount );

private:
	void UnlockAllTools();

	// Money the player is currently holding
	int m_iMoney;
};

#endif