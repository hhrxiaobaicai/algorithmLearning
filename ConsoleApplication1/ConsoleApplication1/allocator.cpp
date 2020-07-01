#include "allocator.h"
#include<stdlib.h>

void* Allocator::allocate(size_t size)
{
	obj* p = nullptr;
	if (!freeStore)
	{
		size_t chunk = CHUNK * size;
		freeStore = p = (obj*)malloc(chunk);

		for (int i=0; i < (CHUNK - 1); ++i)
		{
			p->next = (obj*)((char*)p + size);
			p = p->next;
		}
		p->next = nullptr;
	}
	//p指向返回的那块内存，freeStore始终空余的内存块链表头
	p = freeStore;
	freeStore = freeStore->next;
	return p;
		

}

void Allocator::deallocate(void * p, size_t size)
{
	if (p== nullptr)
	{
		return;
	}
	//释放p,就是将p放在空余内存列表的头
	((obj*)p)->next = freeStore;
	freeStore = (obj*)p;
}
