#pragma once

class Allocator
{
private:
	struct obj
	{
		//嵌入指针，把obj对象的前四个字节作为next指针，没有浪费其他字节来作为指针
		struct obj* next;

	};
public:
	void* allocate(size_t);
	void deallocate(void*, size_t);

private:
	obj* freeStore = nullptr;
	const int CHUNK = 5;

};

