#ifndef _RANDOM_H_
#define _RANDOM_H_

#include <random>

static std::random_device randomDevice;
static std::mt19937 randomEngine( randomDevice() );

int GetRandomNumInRange( int min = 0, int max = 1 )
{
	std::uniform_int_distribution<int> randomPick( min, max );
	return randomPick( randomEngine );
}

float GetRandomNumInRange( float min, float max )
{
	std::uniform_real_distribution<float> randomPick( min, max );
	return randomPick( randomEngine );
}

#endif // ! _RANDOM_H_