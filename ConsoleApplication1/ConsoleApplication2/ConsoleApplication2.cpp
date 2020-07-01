// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool IsBrother(string a,string b)
{
	if (a==b || a.length() != b.length())
	{
		return false;
	}
	
	sort(a.begin(),a.end());
	sort(b.begin(), b.end());
	if (a == b)
	{
		return true;
	}

	return false;
}
int main()
{
	int N;
	while (cin>>N)
	{
		vector<string> vecIn;
		for (int i = 0; i < N; i++)
		{
			string strIn;
			cin >> strIn;
			vecIn.push_back(strIn);
		}
		string strA;
		int nIdx;
		cin >> strA >> nIdx;

		vector<string> vecBro;
		for (size_t i = 0; i < vecIn.size(); i++)
		{
			string strTmp = vecIn[i];
			if (IsBrother(strA,strTmp))
			{
				vecBro.push_back(strTmp);
			}
		}

		if (vecBro.size()>0)
		{
			sort(vecBro.begin(), vecBro.end());
			cout << vecBro.size() << endl;
			if (nIdx>0 && nIdx<= vecBro.size())
			{
				cout << vecBro[nIdx-1] << endl;
			}
		}
		else
		{
			cout << 0 << endl;
		}
	}

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
