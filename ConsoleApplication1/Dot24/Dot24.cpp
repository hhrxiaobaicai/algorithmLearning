// Dot24.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//递归算法

#include <iostream>
using namespace std;
#define EPS (1e-6)
bool IsZero(double n)
{
	return abs(n) < EPS;
}
bool Count24(double a[], int n)
{

	if (n==1)
	{
		if (IsZero(a[0] - 24))
			return true;
		else
			return false;
	}
	else
	{
		double b[5];
		for (int i = 0; i < n-1; i++)
		{
			for (int j = i+1; j < n; j++)
			{
				//将剩余的数放到b数组中
				int m = 0;
				for (int k = 0; k < n; k++)
				{
					if (k!=i&&k!=j)
					{
						b[m++] = a[k];
					}
					
					b[m] = a[i] + a[j];
					if (Count24(b, m + 1))
						return true;
					b[m] = a[i] - a[j];
					if (Count24(b, m + 1))
						return true;
					b[m] = a[j]- a[i];
					if (Count24(b, m + 1))
						return true;
					b[m] = a[i] * a[j];
					if (Count24(b, m + 1))
						return true;
					if (a[j]!=0)
					{
						b[m] = a[i]/ a[j];
						if (Count24(b, m + 1))
							return true;
					}
					if (a[i] != 0)
					{
						b[m] = a[j] / a[i];
						if (Count24(b, m + 1))
							return true;
					}
				}

			}

		}
	}

	return false;
}
int main()
{
	while (true)
	{
		double a[4];
		for (int i = 0; i < 4; i++)
		{
			cin >> a[i];
		}
		if (a[0]==0&& a[1] == 0&& a[2] == 0&& a[3] == 0)
		{
			break;
		}
		if (Count24(a, 4))
		{
			cout << "True" << endl;
		}
		else
		{
			cout << "False" << endl;
		}
	}
	int N;
	cin >> N;
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
