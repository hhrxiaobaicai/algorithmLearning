// zhishuyinzi.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
#include<vector>
using namespace std;
bool isSushu(long A)
{
	if (A==2)
	{
		return true;
	}
	int i = 2;
	do
	{
		if (A%i == 0)
			return false;
		i++;
	} while ((i*i)<=A);

	return true;
}
string getResult(long ulDataInput)
{
	string strOut = "";
	if (isSushu(ulDataInput))
	{
		strOut = strOut + to_string(ulDataInput) + " ";
		return strOut;
	}

	long end = ulDataInput / 2;
	long A = 2;
	do
	{
		while(ulDataInput% A ==0)
		{
			ulDataInput = ulDataInput / A;
			if (isSushu(A))
			{
				strOut = strOut + to_string(A)+" ";
			}
		}
		if (ulDataInput<A)
		{
			break;
		}
		A++;
	} while (A<= end);

	return strOut;
}

int main()
{
	long N;
	while (cin>>N)
	{
		string out = getResult(N);
		cout << out << endl;

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
