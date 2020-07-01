// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

string FindComStr(const string & strA, const string& strB)
{
	int num = 0;
	int ** dp = new int*[strA.size()+1];
	for (size_t i = 0; i < strA.size()+1; i++)
	{
		dp[i] = new int[strB.size()+1];
		memset(dp[i],0,sizeof(int)*strB.size() + 1);
	}

	for (int i = 0; i < strB.length(); i++)
	{
		if (strA[0]==strB[i])
		{
			dp[0][i] = 1;
		}
	}
	for (int i = 0; i < strA.length(); i++)
	{
		if (strB[0] == strA[i])
		{
			dp[i][0] = 1;
		}
	}

	for (int i = 1; i < strA.length(); i++)
	{
		for (size_t j = 1; j < strB.length(); j++)
		{
			if (strA[i] == strB[j])
			{
				dp[i][j] = dp[i-1][j-1] + 1;
				num = max(dp[i][j], num);
			}

		}
	}
	string Str = "";
	bool flag = false;
	for (int i = 1; i < strA.length(); i++)
	{
		for (size_t j = 1; j < strB.length(); j++)
		{
			if (dp[i][j] == num)
			{
				for (int k = i-num+1; k <= i; k++)
				{
					Str = Str + strA[i];
				}
				flag = true;
				break;
			}
		}

		if (flag)
			break;
	}

	for (size_t i = 0; i < strA.size() + 1; i++)
	{
		delete[] dp[i];
	}

	delete[] dp;

	return Str;
}

int CountCharacters(char** words,int wordsize, char* chars)
{
	int num = 0;
	string strChar = chars;
	sort(strChar.begin(), strChar.end());
	transform(strChar.begin(), strChar.end(), strChar.begin(), tolower);
	for (int i = 0; i < wordsize; i++)
	{
		string A = words[i];
		sort(A.begin(), A.end());
		transform(A.begin(), A.end(), A.begin(), tolower);		
		if ( FindComStr(strChar, A)== A)
		{
			num = num + (int)A.size();
		}

	}

	cout << num << endl;

	return num;
}
int main()
{
	int N;
	
	while (cin>>N)
	{
		char** words = new char*[N+1];
		for (int i = 0; i < N; i++)
		{
			words[i] = new char[100];
			memset(words[i],0,sizeof(char)*100);
			string strIn;
			cin >> strIn;
			strcpy_s(words[i], strIn.length()-1, strIn.c_str());
		}

		string chars;
		cin >> chars;

		int num = CountCharacters(words, N, (char*)chars.c_str());

		cout << num;
	
		for (size_t i = 0; i < N + 1; i++)
		{
			delete[] words[i];
		}

		delete[] words;
	
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
