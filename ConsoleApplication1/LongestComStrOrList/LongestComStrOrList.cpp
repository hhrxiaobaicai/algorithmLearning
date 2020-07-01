// LongestComStrOrList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[100][100];
int Sign[100][100];
int FindLongestComStr(const string& strA, const string& strB)
{
	int maxlen = 0;
	for (size_t i = 0; i < strA.length(); i++)
	{
		if (strB[0] == strA[i])
			dp[i][0] = 1;
	}
	for (size_t i = 0; i < strB.length(); i++)
	{
		if (strB[i] == strA[0])
			dp[0][i] = 1;
	}
	for (size_t i = 0; i < strA.length(); i++)
	{
		for (size_t j = 0; j < strB.length(); j++)
		{
			if (strB[j] == strA[i])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				maxlen = max(maxlen, dp[i][j]);
			}
			
		}
	}

	return maxlen;

}
int FindLongestComList(const string& strA, const string& strB)
{
	for (size_t i = 0; i < strA.length(); i++)
	{
		dp[i][0] = 0;
			
	}
	for (size_t i = 0; i < strB.length(); i++)
	{
		dp[0][i] = 0;
			
	}
	for (size_t i = 1; i <= strA.length(); i++)
	{
		for (size_t j = 1; j <= strB.length(); j++)
		{
			if (strA[i-1]== strB[j-1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				Sign[i][j] = 1;
			}
			else
			{
				if (dp[i][j - 1]> dp[i - 1][j])
				{
					dp[i][j] = dp[i][j - 1];
					Sign[i][j] = 2;
				}
				else
				{
					dp[i][j] = dp[i-1][j];
					Sign[i][j] = 0;
				}
			}

		}
	}

	return dp[strA.length()][strB.length()];

}
void PrintStr(int a[][100],const string& strA, int i,int j)
{
	if (i==0||j==0)
	{
		return;
		
	}
	if (a[i][j]==1)
	{
		PrintStr(a, strA, i - 1, j - 1);
		cout << strA[i - 1];
	}
	else if (a[i][j] == 2)
	{
		PrintStr(a, strA, i, j - 1);
	}
	else
	{
		PrintStr(a, strA, i-1, j);
	}

}
int main()
{
	string strA, strB;
	while (cin>> strA>> strB)
	{
		string A;
		//int comlen = FindLongestComStr(strA, strB);
		/*for (size_t i = 1; i < strA.length(); i++)
		{
			for (size_t j = 1; j < strB.length(); j++)
			{
				if (dp[i][j] == comlen)
				{
					for (size_t k = i- comlen+1; k <= i; k++)
					{
						A = A + strA[k];
					}
					cout << A << endl;
					break;
				}

			}
		}*/

		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				Sign[i][j] = 0;
			}
		}
		int comlen = FindLongestComList(strA, strB);
		cout << comlen << endl;
		PrintStr(Sign, strA, (int)strA.length(), (int)strB.length());
		
		/*cin >> A;*/
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
