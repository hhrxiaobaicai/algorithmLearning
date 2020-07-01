// PermutationCombination.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;
int Compare(void const* a, void const* b)
{
	return (*(int*)a - *(int*)b);
}
int main()
{

	//想要使用next_permutation和prev_permutation进行全排列时，你必须先将元素排序
	int n=4;
	int nums[4] = { 1,1,1,1};
	qsort(nums,4,sizeof(int), Compare);
	
	sort(nums, nums + n, greater<int>());
	do {
		for (int i = 0; i < n; i++) {
			cout << nums[i]<<" ";
		}
		cout << endl;
	} while (next_permutation(nums, nums + n));
	//虽然最后一个排列没有下一个排列，用next_permutation会返回false，但是使用了这个方法后，序列会变成字典序列的第一个，
	//如4321变成1234。
	
	do {
		for (int i = 0; i < n; i++) {
			cout << nums[i]<<" ";
		}
		cout << endl;
	} while (prev_permutation(nums, nums + n));
	//虽然最后一个排列没有下一个排列，用prev_permutation会返回false，但是使用了这个方法后，序列会变成字典序列的第一个，
	//如1234变成4321。

	
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
