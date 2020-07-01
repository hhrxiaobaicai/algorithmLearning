// Find2NumEquelM.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<algorithm>

using namespace  std;
int M;
bool BSearch(int a[],int s,int e,int k,int& m)
{
	if (s>=e)
	{
		return false;
	}
	int i = s;
	int j = e;
	while (i<=j)
	{
		m = i + (j - i) / 2;

		if (k == a[m])
			return true;
		else if (k > a[m])
			i = m + 1;
		else
			j = m - 1;		
	}

	return false;
}
bool Find2Num(int a[],int n, int& start,int& end)
{
	sort(a, a + n);

	for (int i = 0; i < n-1; i++)
	{
		int idx = 0;
		if (BSearch(a, i+1, n-1, M - a[i], idx))
		{
			start = i;
			end = idx;
			return true;
		}		
	}

	return false;
}

int main()
{
	int num[100001] = {0};
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	
	cin >> M;
	int start = 0;
	int end = 0;
	if (Find2Num(num,N, start,end))
	{
		cout << num[start] << " " << num[end] << endl;
	}
	else
	{
		cout << "None" << endl;
	}

	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
