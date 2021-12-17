#ifndef DEBUG_H
#define DEBUG_H

#ifdef _DEBUG
	#define ASSERT_CHECK(param) assert(param)
#else
	#define ASSERT_CHECK(param)
#endif

template <typename T> void SafeDelete( T*& ptr )
{
	delete ptr;
	ptr = nullptr;
}

template <typename T> void SafeDeleteArray( T*& ptr )
{
	delete[] ptr;
	ptr = nullptr;
}
#endif