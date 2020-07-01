// NQueen.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//N个Queue摆放在N*N的矩阵上面的摆放方法

#include <iostream>
using namespace std;

//NQueen摆放，不能同行同列以及对角线,j=queenPos[i]表示第i行queen的排列位置是j，从0开始。

int queenPos[100];
int N;
void NQueen(int k)
{
	int i;
	if (k == N)
	{
		for (i = 0; i < N; i++)
		{
			cout << queenPos[i] + 1 << " "; //输出第i的queen的位置，从1开始
		}
		cout << endl;
		return;
	}
	for (i = 0; i < N; i++)//i代表列
	{
		int j;
		for (j = 0; j < k; j++)//j代表行
		{
			if (queenPos[j] == i || abs(queenPos[j] - i) == abs(k - j))
				break;
		}
		if (j == k)
		{
			queenPos[k] = i;
			NQueen(k + 1);
		}
	}

}
int main()
{
	cin >> N;
	NQueen(0);
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
