#ifndef PLAYER_H
#define PLAYER_H

#include "Cheats.h"

class Player
{
public:
	Player();

	// Initializes the tools the player starts with.
	static void Init();

	void Cheat( const ECheats& inCheat );

	// Buys tool at given index.
	void PurchaseTool( int toolIndex );

	// Gets the current money.
	int GetMoney() const;

	// Deduces the money by given amount.
	void DeduceMoney( const int inAmountToDeduce );

	void Payday( int iAmount );

private:
	static void UnlockAllTools();

	// Money the player is currently holding
	int m_iMoney;
};

#endif