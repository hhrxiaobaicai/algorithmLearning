#pragma once

class Allocator
{
private:
	struct obj
	{
		//Ƕ��ָ�룬��obj�����ǰ�ĸ��ֽ���Ϊnextָ�룬û���˷������ֽ�����Ϊָ��
		struct obj* next;

	};
public:
	void* allocate(size_t);
	void deallocate(void*, size_t);

private:
	obj* freeStore = nullptr;
	const int CHUNK = 5;

};

