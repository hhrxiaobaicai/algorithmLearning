#pragma once

#include "allocator.h"
#include<iostream>
using namespace std;
class Airplace
{
public:
	int miles;
	char c;
	//…Í√˜±‰¡ø
	static Allocator MyAlloc;
public:
	Airplace(int a) :miles(a) {}
	static void* operator new(size_t size)
	{
		return MyAlloc.allocate(size);
	}
	static void operator delete(void* p, size_t size)
	{
		return MyAlloc.deallocate(p,size);
	}

	static void noMemory()
	{
		cout << "out of memory!" << endl;
		abort();
	}
};

