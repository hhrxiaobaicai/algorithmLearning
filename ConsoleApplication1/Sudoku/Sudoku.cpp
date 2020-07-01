// Sudoku.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//深度优先算法

#include <iostream>
using namespace std;

/* 构造完成标志 */
bool sign = false;

/* 创建数独矩阵 */
int num[9][9];
/* 读入数独矩阵 */
void Input()
{
	char temp[9][9];
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> temp[i][j];
			num[i][j] = temp[i][j] - '0';
		}
	}
}

/* 输出数独矩阵 */
void Output()
{
	cout << endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (j <8)
			{
				cout << num[i][j] << " ";
			}
			else
			{
				cout << num[i][j];
			}
		}
		cout << endl;
		
	}
}
bool Check(int n, int key)
{
	/* 判断n所在横列是否合法 */
	for (int i = 0; i < 9; i++)
	{
		/* j为n竖坐标 */
		int j = n / 9;
		if (num[j][i] == key) 
			return false;
	}

	/* 判断n所在竖列是否合法 */
	for (int i = 0; i < 9; i++)
	{
		/* j为n横坐标 */
		int j = n % 9;
		if (num[i][j] == key) 
			return false;
	}
	/* x为n所在的小九宫格左顶点竖坐标 */
	int x = n / 9 / 3 * 3;

	/* y为n所在的小九宫格左顶点横坐标 */
	int y = n % 9 / 3 * 3;

	/* 判断n所在的小九宫格是否合法 */
	for (int i = x; i < x + 3; i++)
	{
		for (int j = y; j < y + 3; j++)
		{
			if (num[i][j] == key) 
				return false;
		}
	}

	return true;
}

void DFS(int n)
{
	//终止条件
	if (n>80)
	{
		sign = true;
		return;
	}
	//已知数据
	if (num[n/9][n%9]!=0)
	{
		DFS(n + 1);
	}
	else//未知数据
	{
		for (int i = 1; i <= 9; i++)
		{
			if (Check(n, i))
			{
				num[n / 9][n % 9] = i;
				DFS(n + 1);
				/* 返回时如果构造成功，则直接退出 */
				if (sign == true) 
					return;
				/* 如果构造不成功，还原当前位 */
				num[n / 9][n % 9] = 0;
			}
		}
	}
	
}
int main()
{
	Input();
	DFS(0);
	Output();

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
