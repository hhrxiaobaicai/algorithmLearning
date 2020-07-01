// migong.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//迷宫问题，运用广度优先搜索算法

#include <iostream>
#include <queue>
#include<map>
#include<stack>
using namespace std;
#define N 5


int flag[N+1][N+1];

/* 创建迷宫矩阵 */
int num[N][N];
/* 读入数独矩阵 */
void Input()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> num[i][j];
		}
	}
}
struct Node
{
	int r, c;
	int parent;//父节点的下表
	Node() 
	{
		r = -1;//行
		c = -1;//列
		parent = -1;//在列表中索引下标
	}
	Node(int nr, int nc, int p) :r(nr), c(nc), parent(p) {}
	
};

Node MyQueue[N*N + 10];

int main()
{
	
	while (true)
	{
		Input();
		MyQueue[0] = Node(0, 0, -1);//放置开始节点
		
		int head = 0;
		int tail = 1;
		flag[0][0] = 1;
		bool find = false;
		while (head != tail)
		{
			Node p = MyQueue[head];
			if (p.r == N - 1 && p.c == N - 1)
			{
				find = true;
				break;
			}
			if (p.c + 1 < N && !flag[p.r][p.c + 1] && num[p.r][p.c + 1] != 1)
			{
				MyQueue[tail++] = Node(p.r, p.c + 1, head);
				num[p.r][p.c + 1] = 1;
			}
			if (p.r + 1 < N && !flag[p.r + 1][p.c] && num[p.r + 1][p.c] != 1)
			{
				MyQueue[tail++] = Node(p.r + 1, p.c, head);
				num[p.r + 1][p.c] = 1;
			}
			if (p.c - 1 >= 0 && !flag[p.r][p.c - 1] && num[p.r][p.c - 1] != 1)
			{
				MyQueue[tail++] = Node(p.r, p.c - 1, head);
				num[p.r][p.c - 1] = 1;
			}
			if (p.r - 1 >= 0 && !flag[p.r - 1][p.c] && num[p.r - 1][p.c] != 1)
			{
				MyQueue[tail++] = Node(p.r - 1, p.c, head);
				num[p.r - 1][p.c] = 1;
			}

			head++;

		}

		if (find)
		{
			stack<Node> st;
			Node top = MyQueue[head];
			while (top.parent >= 0)
			{
				st.push(top);
				top = MyQueue[top.parent];
			}
			cout << "[0,0]" <<"->";
			int size = (int)st.size();
			for (int i = 0; i < size; i++)
			{
				Node a = st.top();
				if (i< size-1)
					cout << "[" << a.r << "," << a.c << "]" << "->";
				else 
					cout << "[" << a.r << "," << a.c << "]";
				st.pop();
			}
			cout << endl;
		}
		else
		{
			cout << "Trace does not exist" << endl;
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
