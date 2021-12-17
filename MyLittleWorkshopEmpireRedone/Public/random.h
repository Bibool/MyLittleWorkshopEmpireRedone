#ifndef RANDOM_H
#define RANDOM_H

#include <random>

static std::random_device randomDevice;
static std::mt19937 randomEngine( randomDevice() );

inline int GetRandomNumInRange( int min = 0, int max = 1 )
{
	const std::uniform_int_distribution<int> randomPick( min, max );
	return randomPick( randomEngine );
}

inline float GetRandomNumInRange( float min, float max )
{
	const std::uniform_real_distribution<float> randomPick( min, max );
	return randomPick( randomEngine );
}

#endif // ! RANDOM_H