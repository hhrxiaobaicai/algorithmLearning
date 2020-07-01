// CharNum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <functional>
#include <string>
#include<map>
#include <algorithm>
#include<set>
#include<unordered_map>
using namespace std;

bool Compare(char a, char b)
{
	char A = tolower(a);
	char B = tolower(b);	
	return A==B;
}
int CompareQ(void const* a, void const* b)
{
	return (*(int*)a - *(int*)b);
}

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
	int Tranverse(TreeNode* root, int depth) {
		if (!root) return 0;
		if (root->left == NULL && root->right == NULL)
			return depth;

		int left = Tranverse(root->left, depth + 1);

		int right = Tranverse(root->right, depth + 1);

		return max(max(left, right), depth);

	}
	int maxDepth(TreeNode* root) {
		if (!root) return 0;
		//return Tranverse(root, 1);
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};

class Solution3 {
public:
	void iniMatchStr(string t, unordered_map<char, int>& Needle) {
		for (size_t i = 0; i < t.length(); i++) {
			Needle[t[i]]++;
		}
	}
	string minWindow(string s, string t) {
		
		if (s.empty() || t.empty())
			return "";
		if (s.length() < t.length())
			return "";

		int left = 0;
		int right = 0;
		unordered_map<char, int> Needle; 
		unordered_map<char, int> window;
		iniMatchStr(t, Needle);

		int match = 0; //字符匹配种类，但一个字符的类型和个数都匹配时增1
		int minLen = INT_MAX;
		int pos = 0;
		while (right < s.length()) {
			char ch = s[right];
			window[ch]++;
			if (Needle.count(ch) > 0) {
				if (window[ch] == Needle[ch]) {
					match++;
				}
			}
			right++;

			while (match == Needle.size()) {
				//记录当前窗口的长度
				if (minLen > right - left) {
					pos = left;
					minLen = right - left;
				}
				//丢弃窗口左边字符
				char c = s[left];
				window[c]--;
				//如果丢弃的字符是匹配字符串中的字符，则match数减1
				if (Needle.count(c) > 0)
				{
					if(window[c] < Needle[c]) match--;
				}
				left++;
			}
		}

		return (minLen == INT_MAX) ? "" : s.substr(pos,minLen);
	}
};
class Solution5 {
public:
	void iniMatchStr(string t, unordered_map<char, int>& Needle) {
		for (size_t i = 0; i < t.length(); i++) {
			Needle[t[i]]++;
		}
	}
	vector<int> findAnagrams(string s, string p) {
		vector<int> res;
		if (s.empty())
			return res;
		if (s.length() < p.length())
			return res;

		int left = 0;
		int right = 0;
		unordered_map<char, int> Needle;
		unordered_map<char, int> window;
		iniMatchStr(p, Needle);

		int match = 0; //字符匹配种类，但一个字符的类型和个数都匹配时增1
		int minLen = INT_MAX;
		int pos = 0;
		while (right < s.length()) {
			char ch = s[right];			
			if (Needle.count(ch) > 0) {
				window[ch]++;
				if (window[ch] == Needle[ch]) {
					match++;
				}
			}
			right++;

			while (match == Needle.size()) {
				//记录当前窗口的长度
				if (p.size() == right - left) {
					res.push_back(left);
				}
				
				char c = s[left];
				//如果丢弃的字符是匹配字符串中的字符，则match数减1
				if (Needle.count(c) > 0)
				{
					window[c]--;//丢弃窗口左边字符
					if (window[c] < Needle[c]) match--;
				}
				left++;
			}
		}

		return res;
	}
};
class Solution4 {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.empty())
			return 0;
		int left = 0;
		int right = 0;
		//记录不重复的字符，
		unordered_map<char, int> window;
		int maxLen = 0;
		while (right < s.length()) {
			char c1 = s[right];
			window[c1]++;
			right++;
			//出现重复字符时去除重复字符前面的字符
			while (window[c1] > 1) {
				//记录当前窗口的长度
				char c2 = s[left];
				window[c2]--;
				left++;
			}
			//窗口增加字符后比较长度
			maxLen = max(maxLen, right - left);
		}
		return maxLen;
	}
};
class Solution6 {
public:
	string Palindrome(string s, int l, int k) {
		while (l >= 0 && k < s.length()) {
			if (s[l] != s[k]) {
				break;
			}
			l--;
			k++;
		}
		return s.substr(l + 1, k - l - 1);
	}
	string longestPalindrome(string s) {
		if (s.empty())
			return "";
		string res;
		for (size_t i = 0; i < s.length(); i++) {
			string s1 = Palindrome(s, i, i);
			string s2 = Palindrome(s, i, i + 1);
			res = (s1.length() > res.length()) ? s1 : res;
			res = (s2.length() > res.length()) ? s2 : res;
		}
		return res;
	}
};
class Solution7 {
public:
	bool isValidTree(TreeNode* root, TreeNode* min, TreeNode* max) {
		if (!root) return true;
		if (min && root->val <= min->val) return false;
		if (max && root->val >= max->val) return false;
		return isValidTree(root->left, min, root) && isValidTree(root->right, root, max);
	}
	bool isValidBST(TreeNode* root) {

		return isValidTree(root, nullptr, nullptr);
	}
};

class Solution8 {
public:
	bool isSymmetric(TreeNode* root1, TreeNode* root2) {
		if (root1 == NULL && root2 == NULL) return true;
		if (root1 == NULL && root2 != NULL) return false;
		if (root1 != NULL && root2 == NULL) return false;
		if (root1->val != root2->val)  return false;
		return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
	}
	bool isSymmetric(TreeNode* root) {

		return isSymmetric(root, root);
	}
};

class Solution9 {
public:
	string CalNextStr(string s) {		
		int left = 0;
		int right = 0;
		string res;
		while (right < s.length())
		{
			int n = 0;
			while (right < s.length() && s[left] == s[right]) {
				n++;
				right++;
			}
			res += (n + '0');
			res += s[left];

			left = right;
		}
		
		return res;
	}
	string countAndSay(int n) {
		string s;
		s = "1";
		int num = 1;

		while (num < n) {
			s = CalNextStr(s);
			num++;
		}
		return s;
	}
};

class Solution10 {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) return "";
		string res;
		int len = strs[0].length();
		string first = strs[0];
		for (int n = 1; n < strs.size(); n++) {
			string str = strs[n];
			int i;
			for (i = 0; i< first.length() && i < str.length(); i++) {
				if (first[i] != str[i]) {
					len = i;
					break;
				}
			}
			if (len == 0) return "";
			if (i == str.length()) len = i;
		}

		return first.substr(0, len);
	}
};

class Solution12 {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() < 3)
			return res;
		/*sort(nums.begin(), nums.end());
		for (int i = 0; i < length; i++)
		{

		}*/


		//set<string> setIndex;
		for (int k = 0; k < nums.size(); k++) {
			
			int fix = -nums[k];			
			unordered_map<int, int> index;
			for (int i = 0; i < nums.size(); i++) {
				if (k == i) continue;
				int target = fix - nums[i];
				if (index.count(target)) {
					//string str;
					//str += (k + '0');
					//str += (index[target] + '0');
					//str += (i + '0');
					//sort(str.begin(), str.end());
					//if (setIndex.insert(str).second == 0) {
					//	continue;// 三个数组合已经存在了
					//}
					//setIndex.insert(str);
					vector<int> three;
					three.push_back(nums[k]);
					three.push_back(target);
					three.push_back(nums[i]);
					res.push_back(three);
					
				}

				index[nums[i]] = i;
			}
			
			/*for (int i = 0, k = 1; k < res.size(); k++)
			{
				vector<int> threeL = res[i];
				vector<int> threeR = res[k];
				sort(threeL.begin(), threeL.end());
				if (threeL == threeR)
				{
					res[i] = res[k];
					i++;
				}
				k++;
			}*/
		}

		return res;
	}
};
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		int len = nums.size();		
		sort(nums.begin(), nums.end());
		if (len < 3 || nums[0] > 0 || nums[len - 1] < 0) return res;

		for (int i = 0; i < len-2; i++)
		{
			int target = 0 - nums[i];
			int l = i + 1;
			int r = len - 1;
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			while (l<r) {
				if (nums[l] + nums[r] == target) {
					res.push_back(vector<int>{nums[i], nums[l], nums[r]});					
					l++;
					r--;
					while (l < r && nums[l] == nums[l - 1]) l++;
					while (l < r && nums[r] == nums[r + 1]) r--;
				}
				else if (nums[l] + nums[r] > target) {
					r--;
				} else {
					l++;
				}

			}
		}

		return res;
	}
};
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {

		int len = nums.size();
		sort(nums.begin(), nums.end());
		if (len < 3) return INT_MIN;
		int sum = nums[0] + nums[1] + nums[2];
		if (sum == target)
			return target;
		for (int i = 0; i < len - 2; i++)
		{
			int l = i + 1;
			int r = len - 1;			
			while (l < r) {

				int temp = nums[i] + nums[l] + nums[r];
				sum = abs(temp - target) < abs(sum - target) ? sum : temp;
				if (sum == target){
					return target;			
				}
				else if (sum > target) {
					r--;
				}
				else {
					l++;
				}

			}
		}

		return sum;
	}
};
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> res;
		int len = nums.size();
		sort(nums.begin(), nums.end());
		if (len < 4) return res;

		for (int i = 0; i < len - 3; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			for (int j = i + 1; j < len -2; j++)
			{
				int fix = target - nums[i] - nums[j];
				int l = j + 1;
				int r = len - 1;
				if (j > i + 1 && nums[j] == nums[j - 1]) continue;
				while (l < r) {
					if (nums[l] + nums[r] == fix) {
						res.push_back(vector<int>{nums[i], nums[j], nums[l], nums[r]});
						l++;
						r--;
						while (l < r && nums[l] == nums[l - 1]) l++;
						while (l < r && nums[r] == nums[r + 1]) r--;
					}
					else if (nums[l] + nums[r] > fix) {
						r--;
					}
					else {
						l++;
					}
				}				
			}			
		}

		return res;
	}
};
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target)
	{
		int len = nums.size();//获取数组长度
		vector<vector<int>> ans;//保存结果
		if (len < 4)//小于4个，返回空
			return ans;

		sort(nums.begin(), nums.end());//排序

		for (int i = 0; i < len - 3; ++i)//迭代第一个定点
		{
			for (int j = i + 1; j < len - 2; ++j)//迭代第二个定点
			{
				int l = j + 1;//定义左右指针
				int r = len - 1;

				while (l < r)
				{
					int sum = nums[i] + nums[j] + nums[l] + nums[r];//计算当前四数之和
					if (sum == target)//相等，记录这四个数
					{
						ans.push_back(vector<int>{nums[i], nums[j], nums[l], nums[r]});
						while (l + 1 < r&&nums[l + 1] == nums[l])//过滤相等值
							++l;
						while (r - 1 > l&&nums[r - 1] == nums[r])
							--r;
						++l;
						--r;
					}
					else if (sum < target)//与三数之和一致
						++l;
					else
						--r;
				}
				while (j + 1 < len - 2 && nums[j + 1] == nums[j])//过滤第二个相等的定点
					++j;
			}
			while (i + 1 < len - 3 && nums[i + 1] == nums[i])//过滤第一个相等的定点
				++i;
		}
		return ans;
	}
};

class Solution11 {
	vector<int> res;
public:
	void Reverse(vector<int>& A, int i, int j) {
		while (i < j)
		{
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			i++;
			j--;
		}
	}
	void sort(vector<int>& A, int n) {
		if (n == 1) return;
		int maxCakeIndex = 0;
		int maxCake = INT_MAX;
		for (int i = 0; i < A.size(); i++)
		{
			if (maxCake > A[i]) {
				maxCake = A[i];
				maxCakeIndex = i;
			}
		}

		Reverse(A, 0, maxCakeIndex);
		res.push_back(maxCakeIndex + 1);
		Reverse(A, 0, n-1);
		res.push_back(n);

		sort(A, n - 1);
	}
	vector<int> pancakeSort(vector<int>& A) {
		sort(A, A.size());
		return res;
	}
};
int main()
{
	string s = "abcabcbb";
	string t = "ABDC";
	vector<int> nums;
	nums.push_back(-1);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(-1);
	nums.push_back(-4);

	vector<int> nums1;
	nums1.push_back(-1);
	nums1.push_back(0);
	nums1.push_back(1);
	nums1.push_back(2);
	nums1.push_back(-1);
	nums1.push_back(-4);
	bool euqe = nums == nums1;

	Solution su;
	vector<vector<int>> res = su.threeSum(nums);

	int aaa = count(s.begin(), s.end(), 'A');

	int a[4] = {1,4,2,6};
	qsort(a, 4, sizeof(int), CompareQ);
	string strIn;
	int num = 0;
	while (getline(cin, strIn))
	{
		char c,dem;
		cin >> c;
		c = tolower(c);
		
		/*for (size_t i = 0; i < strIn.length(); i++)
		{
			char b = tolower(strIn.at(i));
			if (b==c)
			{
				num++;
			}
		}*/
		transform(strIn.begin(), strIn.end(), strIn.begin(), tolower);
		num = count_if(strIn.begin(), strIn.end(), bind2nd(equal_to<char>(),c));//将c绑定到equal_to的第二个参数。
		num = count(strIn.begin(), strIn.end(), 1);
		cout << num << endl;
		cin >> dem;
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
