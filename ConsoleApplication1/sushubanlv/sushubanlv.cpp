// sushubanlv.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//匈牙利算法

#include <iostream>
#include<vector>
#include<list>

using namespace std;
bool IsSushu(int A)
{
	int i = 3;
	do
	{
		if (A%i == 0)
			return false;
		i=i+1;
	} while ((i*i)<= A);

	return true;
}
int FindMaxLine(list<int> X, list<int> Y)
{
	int max = 0;
	
	for (list<int>::iterator i = X.begin(); i != X.end(); i++)
	{
		int cur = 0;
		int x1 = *i;
		for (list<int>::iterator j = Y.begin(); j != Y.end(); j++)
		{
			int y1 = *j;
			if (IsSushu(x1+y1))
			{
				cur++;
			}

			if (X.size() == 1)
			{
				if (cur == X.size())
					return cur;
				else
					continue;
			}

			list<int> subX = X;
			subX.remove(x1);
			list<int> subY = Y;
			subY.remove(y1);

			int submax = FindMaxLine(subX, subY);
			cur =  cur+ submax;
			if (cur == X.size())
			{
				return cur;
			}
		}

		if (cur>max)
		{
			max = cur;
		}

		
	}

	return max;

}
//匈牙利算法
int Used[100] = {0};
int Matched[100] = {-1};
bool FindMatch(int x, vector<int> vecA,vector<int> vecB)
{
	int A = vecA[x];
	for (size_t i = 0; i < vecB.size(); i++)
	{
		int B = vecB[i];
		if (IsSushu(A+B) && Used[i]==0)
		{
			Used[i] = 1;
			if (Matched[i] ==-1 || FindMatch(Matched[i], vecA,vecB))
			{
				Matched[i] = x;
				return true;
			}
		}
	}

	return false;
}
int main()
{
	int N;
	while (cin>>N)
	{
		vector<int> vecJishu;
		vector<int> vecOushu;

		for (int i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			if (a%2==0)
			{
				vecOushu.push_back(a);
			}
			else
			{
				vecJishu.push_back(a);
			}
		}
		
		if (vecOushu.size()==0|| vecJishu.size()==0)
		{
			cout << 0 << endl;
		}
		else
		{
			int max = 0;
			for (int i = 0; i < 100; i++)
			{
				Matched[i] = -1;
			}
			
			for (int i = 0; i < vecOushu.size(); i++)
			{
				for (int a = 0; a < 100; a++)
				{
					Used[a] = 0;
				}
				if (FindMatch(i, vecOushu, vecJishu))
				{
					max++;
				}
			}

			cout << max << endl;
		}
		
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
