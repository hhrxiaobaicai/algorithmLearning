// CowStall.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<queue>
#include<algorithm>

using namespace std;

struct Cow
{
	int a, b;//开始挤奶时间和结束挤奶时间
	int No; //所在畜栏的编号
	bool operator< (const Cow& c) const
	{ 
		return a < c.a; 
	}
}Cows[50100];

struct Stall
{
	int E;//当前cow的结束时间
	int No;//畜栏的编号
	Stall(int b, int no) :E(b), No(no) {}
	bool operator< (const Stall& s) const
	{
		return E>s.E;
	}

};


int main()
{
	int N;
	while (cin >> N)
	{
		int pos[50100];

		for (int i = 0; i < N; i++)
		{
			cin >> Cows[i].a >> Cows[i].b;
			Cows[i].No = i;
		}
		//对奶牛的开始时间进行排序，让开始时间早的放前面。
		sort(Cows, Cows + N);
		//对于基础类型 默认是大顶堆，大的在前面，因此需要重载Stall的<,
		//使结束时间早的放在前面供新的奶牛挑选
		priority_queue<Stall> pQueue; 
		int total = 0;
		for (int i = 0; i < N; i++)
		{
			if (pQueue.empty())
			{
				total++;
				pQueue.push(Stall(Cows[i].b, total));
				pos[Cows[i].No] = total;//排序之后奶牛的编号不是i
			}
			else
			{
				Stall st = pQueue.top();
				//第二头奶牛的开始时间大于等于畜栏的结束时间，
				//不用新建畜栏，直接修改畜栏的结束时间为第二头奶牛的结束时间，
				//相当于将第二头奶牛放入当前的畜栏。
				if (st.E <= Cows[i].a)	
				{
					pQueue.pop();
					pQueue.push(Stall(Cows[i].b, st.No));
					pos[Cows[i].No] = st.No;
				}
				else
				{
					//第二头奶牛的开始时间小于畜栏的结束时间，
				   //新建畜栏，将第二头奶牛放入新建的畜栏。
					total++;
					pQueue.push(Stall(Cows[i].b, total));
					pos[Cows[i].No] = total;
				}
			}

		}
		cout << total << endl;
		for (int i = 0; i < N; i++)
		{
			printf("the stall of cow[%d] is: %d\n", i, pos[i]);
			
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
