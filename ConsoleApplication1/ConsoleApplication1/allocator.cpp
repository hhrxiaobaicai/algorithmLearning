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
	//pָ�򷵻ص��ǿ��ڴ棬freeStoreʼ�տ�����ڴ������ͷ
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
	//�ͷ�p,���ǽ�p���ڿ����ڴ��б��ͷ
	((obj*)p)->next = freeStore;
	freeStore = (obj*)p;
}
