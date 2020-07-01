// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<math.h>
#include<algorithm>
#include<list>

#include"Airplace.h"
int compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
void Merge(int a[], int s,int m, int e, int b[])
{
	int p1 = s;
	int p2 = m + 1;
	int idx = 0;
	while (p1<=m&&p2<=e)
	{
		if (a[p1]<a[p2])
		{
			b[idx++] = a[p1++];
		}
		else
		{
			b[idx++] = a[p2++];
		}
	}

	while (p1<=m)
	{
		b[idx++] = a[p1++];
	}

	while (p2<=e)
	{
		b[idx++] = a[p2++];
	}
	for (int i = 0; i < e-s+1; i++)
	{
		a[s+i] = b[i];
	}

}
//归并排序
void MergeSort(int a[], int s, int e, int b[])
{
	if (s<e)
	{
		int m =s+ (e-s) / 2;
		MergeSort(a,s,m,b);
		MergeSort(a, m+1, e, b);
		Merge(a,s,m,e,b);
	}


}
void swap(int& a, int &b)
{
	int tmp = b;
	b = a;
	a = tmp;

}
void QuickSort(int a[],int s,int e)
{
	if (s>=e)
	{
		return;
	}

	int k = a[s];
	int i = s;
	int j = e;
	while (i<j)
	{
		while (i < j&&a[j]>=k)
		{
			j--;
		}
		swap(a[i], a[j]);
		while (i<j&&a[i]<=k)
		{
			i++;
		}
		swap(a[i],a[j]);

	}
	QuickSort(a,s,i-1);
	QuickSort(a, i+1, e);

}
bool BSearch(int a[],int n, int q)
{
	int s = 0;
	int m = 0;
	while (s<=n)
	{
		m = s +(n-s) / 2;
		if (q==a[m])
		{
			return true;
		}
		else if (q>a[m])
		{
			s = m + 1;
		}
		else
		{
			n = m - 1;
		}
	}

	return false;

}

using namespace std;
int main()
{
	cin >> N;
	NQueen(0);
	int nums[10];
	for (int i = 0; i < 10; i++) {
		nums[i] = i + 1;
	}

	int n;
	cin >> n;
	do {
		for (int i = 0; i < n; i++) {
			cout << nums[i];
		}
		cout << endl;
	} while (next_permutation(nums, nums + n));
	

	

	return 0;


	multimap<int, int>mmap;

	mmap.insert(make_pair(1,1));
	mmap.insert(make_pair(2, 3));
	mmap.insert(make_pair(2, 3));
	mmap.insert(make_pair(4, 4));
	for (int i = 0; i < mmap.size(); i++)
	{
		
		cout << mmap.find(i)->second << endl;
	}

	int a[10] = {13,2,33,32,1,2,3,5,3,6};
	int b[10] = {};

	int size = 10;

	QuickSort(a, 0, size - 1);

	
	//MergeSort(a,0,size-1,b);//归并排序
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << endl;
	}

	bool bRet = BSearch(a, size-1, 0);
	cout << bRet << endl;
	string ss = "jds";
	list<int> bb;
	vector<int> aa;
	aa.push_back(1);
	aa.push_back(22);
	aa.push_back(4);
	aa.push_back(3);
	aa.push_back(1);

	//int a[5] = { 1,22,4,3,1 };
	qsort(a, 5, sizeof(int), compare);
	
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << endl;
	}
	/*Airplace A(1);
	set_new_handler(Airplace::noMemory);
	try
	{
		int *p = new int[204472320];
		cout << "allocate succeed!" << endl;
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}*/
	
	

	//Airplace* p[100];
	//cout << "sizeof(Airplace)=" << sizeof(Airplace) << endl;

	//for (int i = 0; i <23; i++)
	//{
	//	p[i] = new Airplace(i);
	//	cout << p[i] << " " << p[i]->miles << endl;
	//}
	//for (size_t i = 0; i < 23; i++)
	//{
	//	delete p[i];
	//}

	//string *pc = new string[3];
	//for (int i = 0; i < 3; i++)
	//{
	//	//placement new, 允许我们将对象放在已经分配的内存中。
	//	new(pc)string(to_string(i));
	//	pc++;
	//}
	//pc--;
	//for (size_t i = 0; i < 3; i++)
	//{
	//	cout << *(pc) << endl;
	//	pc--;
	//}
	//pc++;
	//delete[] pc;
	///*cin >> N;
	//NQueen(0);*/
	//printf("%.1f", Exp());
	//double a = Exp();
	//cout << a << endl;
	/*obj* p = Airplace::MyAlloc.freeStore;
	while (p !=nullptr)
	{
		void* q = p->next;
			
	}*/
	int N;
	cin >> N;
}


//NQueen摆放，不能同行同列以及对角线
int queenPos[100];
int N;
void NQueen(int k)
{
	int i;
	if (k==N)
	{
		for ( i = 0; i < N; i++)
		{
			cout << queenPos[i] + 1 << " ";
		}
		cout << endl;
		return;
	}
	for ( i = 0; i < N; i++)//i代表列
	{
		int j;
		for ( j = 0; j < k; j++)//j代表行
		{
			if (queenPos[j] == i || abs(queenPos[j] - i) == abs(k - j))
				break;
		}
		if (j==k)
		{
			queenPos[k] = i;
			NQueen(k + 1);
		}
	}

}
//逆波兰表达式
double Exp()
{
	char str[20];
	cin >> str;
	switch (str[0])
	{
	case '+':
		return Exp() + Exp();
		break;
	case '-':
		return Exp() - Exp();
		break;
	case '*':
		return Exp() * Exp();
		break;
	case '/':
		return Exp() / Exp();
		break;

	default:
		return atof(str);
		break;
	}


}

void Hanoi(int n, char src, char mid, char dest)
{

	if (n == 1)
	{
		cout << src << "->" << dest << endl;
		return;
	}

	Hanoi(n - 1, src, dest, mid);
	cout << src << "->" << dest << endl;
	Hanoi(n - 1, mid, src, dest);
	return;
}


int main111()
{

	vector<int> vecData;
	vecData.push_back(1);
	vecData.push_back(2);
	vecData.push_back(3);
	vecData.push_back(4);
	vecData.push_back(5);
	int a=0 ,b= 0;
	//lambda 表达式 [](int a){;}
	std::for_each(vecData.begin(), vecData.end(), [&](int x) {if(x % 2 == 0) a++; else b++;});
	int num = (int)std::count_if(vecData.begin(), vecData.end(), [](int x) {return x % 2 == 0; });

	std::cout << a <<" "<<b <<" "<< num << endl;


	return 0;

}

//int main()
//{
//	int N = 0;
//	while (cin>>N)
//	{
//		vector<string> vecOut;
//		
//		for (int i = 0; i < N; i++)
//		{
//			string strIn = "";
//			cin >> strIn;
//			string strTmp = "00000000";
//			if (strIn.length()<8)
//			{
//				for (size_t i = 0; i < strIn.size(); i++)
//				{
//					strTmp[i] = strIn[i];
//				}
//				vecOut.push_back(strTmp);
//			}
//			else if(strIn.length() == 8)
//			{
//				vecOut.push_back(strIn);
//			}
//			else
//			{
//				int length = (int)strIn.length();
//				int start = 0;
//				do
//				{
//					strTmp = strIn.substr(start, 8);
//					vecOut.push_back(strTmp);
//					start += 8;
//
//				} while (start+8 <= length);
//				
//				if (start< length)
//				{
//					string strTmp1 = strIn.substr(start);
//					for (int i = 0; i < 8-(length -start); i++)
//					{
//						strTmp1 = strTmp1 + "0";
//					}
//					vecOut.push_back(strTmp1);
//				}
//				
//				
//			}
//
//		}
//		
//		sort(vecOut.begin(), vecOut.end());
//		size_t i = 0;
//		for (; i < vecOut.size()-1; i++)
//		{
//			cout << vecOut[i] << " ";
//		}
//		cout << vecOut[i] << endl;
//	}
//
//	return 0;
//}




int ChangeType(string In)
{
	int N = 0;
	In = In.substr(2);
	int len = (int)In.length() - 1;
	int pos = len;
	while (pos>=0)
	{
		char C = In.at(pos);
		switch (C)
		{
		case 'A':
			N += 10 * int(pow(16, len - pos));
			break;
		case 'B':
			N += 11 * int(pow(16, len - pos));
		case 'C':
			N += 12 * int(pow(16, len - pos));
			break;
		case 'D':
			N += 13 * int(pow(16, len - pos));
			break;
		case 'E':
			N += 14 * int(pow(16, len - pos));
			break;
		case 'F':
			N += 15 * int(pow(16, len - pos));
			break;
		case '9':
			N += 9 * int(pow(16, len - pos));
			break;
		case '8':
			N += 8 * int(pow(16, len - pos));
			break;
		case '7':
			N += 7 * int(pow(16, len - pos));
			break;
		case '6':
			N += 6 * int(pow(16, len - pos));
			break;
		case '5':
			N += 5 * int(pow(16, len - pos));
			break;
		case '4':
			N += 4 * int(pow(16, len - pos));
			break;
		case '3':
			N += 3 * int(pow(16, len - pos));
			break;
		case '2':
			N += 2 * int(pow(16, len - pos));
			break;
		case '1':
			N += 1 * int(pow(16, len - pos));
			break;
		case '0':
			N += 0;
			break;
		default:			
			break;
		}

		pos--;
	
	}
	return N;

}
//int main()
//{
//	string in ="";
//	vector<int> vecIn;
//	while (cin >> in)
//	{
//		int N = ChangeType(in);
//		vecIn.push_back(N);
//	}
//	for (size_t i = 0; i < vecIn.size(); i++)
//	{
//		cout << vecIn[i] << endl;
//	}
//
//	return 0;
//}



int sortInput()
{
	int N = 0;
	while (cin >> N)
	{
		int m = 0;
		cin >> m;
		map<int, map<int, string>> mapData;
		for (int i = 0; i < N; i++)
		{
			string name = "";
			int score = 0;
			cin >> name >> score;

			map<int, map<int, string>>::iterator iter = mapData.find(score);
			if (iter!= mapData.end())
			{
				map<int, string>& mapName = iter->second;
				mapName.insert(make_pair(i, name));
			}
			else
			{
				map<int, string> mapName;
				mapName.insert(make_pair(i, name));
				mapData.insert(make_pair(score, mapName));
			}


		}

		if (m!=0)
		{
			map<int, map<int, string>>::iterator iter = mapData.begin();
			for (; iter != mapData.end(); iter++)
			{
				int score = iter->first;
				map<int, string> mapName = iter->second;
				map<int, string>::reverse_iterator iterN = mapName.rbegin();
				for (;iterN!= mapName.rend(); iterN++)
				{
					string name = iterN->second;
					cout << name << " " << score<<endl;
				}
			}
		}
		else
		{
			map<int, map<int, string>>::reverse_iterator iter = mapData.rbegin();
			for (; iter != mapData.rend(); iter++)
			{
				int score = iter->first;
				map<int, string> mapName = iter->second;
				map<int, string>::iterator iterN = mapName.begin();
				for (; iterN != mapName.end(); iterN++)
				{
					string name = iterN->second;
					cout << name << " " << score << endl;
				}
			}
		}

	}


	return 0;
}

void rand_number()
{
	int num;
	while (cin>>num)
	{
		map<int,int> input;
		for (int i = 0; i < num; i++)
		{
			int A;
			cin >> A;
			map<int, int>::iterator iter = input.find(A);
			if (iter!= input.end())
			{
				continue;
			}
			else
			{
				input.insert(make_pair(A, A));
			}
			
		}

		cout << input.size() << endl;
		
		map<int, int>::iterator iterS = input.begin();
		cout << input.begin()->first;
		++iterS;
		for (; iterS != input.end(); ++iterS)
		{
			cout << ", " << iterS->first;
		}
		cout << "." << endl;
	}


}
void SplitStr()
{
	vector<string> vecOut;
	string str ="";
	while (getline(cin,str))
	{
		string sub = "00000000";
		if (str.length()<=8)
		{
			for (size_t i = 0; i < str.length(); i++)
			{
				sub[i] = str[i];
			}
			vecOut.push_back(sub);
			continue;
		}
		int start = 0;
		do
		{
			sub = str.substr(start, 8);
			vecOut.push_back(sub);
			sub = "00000000";
			start = start + 8;
		} while (str.length() -start >8 );
		
		for (size_t i = start; i < str.length(); i++)
		{
			sub[i] = str[i];
		}
		vecOut.push_back(sub);
		
	}

	for (size_t i = 0; i < vecOut.size(); i++)
	{
		cout << vecOut[i] << endl;
	}
}
void RecordError()
{
	map<string, map<string, int>> mapOut;
	vector<string> vecOut;
	string str = "";
	while (getline(cin, str, '\n'))
	{
		int pos = (int)str.find(" ");
		string path = str.substr(0, pos);
		string seq = str.substr(pos + 1);
		pos = (int)path.find_last_of("\\");
		string file = "";
		if (pos != -1)
		{
			file = path.substr(pos + 1);
		}
		else
		{
			file = path;
		}

		if (vecOut.size() == 8)
		{
			string file_seq = vecOut[0];
			int delim =(int)file_seq.find_last_of("\\");
			string delfile = file_seq.substr(0, delim);
			string delseq = file_seq.substr(delim + 1);
			map<string, map<string, int>>::iterator iterD = mapOut.find(delfile);
			if (iterD != mapOut.end())
			{
				map<string, int>& mapdel = iterD->second;
				map<string, int>::iterator iterS = mapdel.find(delseq);
				if (iterS != mapdel.end())
				{
					mapdel.erase(iterS);
					vecOut.erase(vecOut.begin());
				}
			}
		}

		map<string, map<string, int>>::iterator iter = mapOut.find(file);
		if (iter != mapOut.end())
		{
			map<string, int>& mapTmp = iter->second;
			map<string, int>::iterator iterS = mapTmp.find(seq);
			if (iterS != mapTmp.end())
			{
				iterS->second++;
			}
			else
			{
				mapTmp.insert(make_pair(seq, 1));
				string file_seq = file + "\\" + seq;
				vecOut.push_back(file_seq);
			}
		}
		else
		{
			map<string, int> mapNew;
			mapNew.insert(make_pair(seq, 1));
			mapOut.insert(make_pair(file, mapNew));
			string file_seq = file + "\\" + seq;
			vecOut.push_back(file_seq);
		}
	}


	for (size_t i = 0; i < vecOut.size(); i++)
	{
		string filename = vecOut[i];
		int delim = (int)filename.find_last_of("\\");
		string name = filename.substr(0, delim);
		string seq = filename.substr(delim + 1);
		map<string, map<string, int>>::iterator iter = mapOut.find(name);
		if (iter != mapOut.end())
		{
			if (name.length() > 16)
			{
				name = name.substr(name.length() - 16);
			}
			map<string, int> tmp = iter->second;
			map<string, int>::iterator iterS = tmp.find(seq);
			if (iterS != tmp.end())
			{
				cout << name << " " << seq << " " << iterS->second << endl;
			}
		}

	}


	
}
int CountOneNumber(long A, vector<int>& mark)
{
	int num = 0;
	while (A)
	{
		int remainder = A & 1;
		mark.push_back(remainder);
		if (remainder==1){
			num++;
		}
		A = A>>1;
	}

	return num;
}
void Combination(int m,int n,vector<vector<int>>& outdata)
{
	int mark[] = { 0 };
	long A = (long)pow(2, n) - 1;
	long Max = (long)(pow(2, m)-pow(2, m-n));
	//if m=4,n=2, initail mark ={0,0,1,1} 
	do
	{
		vector<int> mark;
		int num_of_one = CountOneNumber(A, mark);
		if (num_of_one== n)
		{
			outdata.push_back(mark);
		}
		A++;

	} while (A<=Max);
	
}
void ChoppingList()
{
	int N, m = 0;
	while (cin >> N >> m)
	{
		int v[60][4] = { 0 };
		int p[60][4] = { 0 };
		for (int i = 1; i < m + 1; i++)
		{
			int x, y, q = 0;
			cin >> x >> y >> q;
			x = x / 10;
			if (q == 0)//主件
			{
				for (int j = 0; j < 4; j++)
				{
					v[i][j] = v[i][j] + x;
					p[i][j] = p[i][j] + x * y;
				}

			}
			else if (v[q][1] == v[q][0])//没有附件，追加附件1
			{
				v[q][1] = v[q][1] + x;
				p[q][1] = p[q][1] + x * y;

				v[q][3] = v[q][3] + x;
				p[q][3] = p[q][3] + x * y;

			}
			else//有了一个附件1，追加附件2
			{
				v[q][2] = v[q][2] + x;
				p[q][2] = p[q][2] + x * y;

				v[q][3] = v[q][3] + x;
				p[q][3] = p[q][3] + x * y;
			}

		}
		N = N / 10;
		int V[3200] = { 0 };
		for (int i = 1; i <= m; i++)
		{
			for (int j = N; j > 0; j--)
			{
				for (int k = 0; k < 4; k++)
				{
					if (j >= v[i][k])
					{
						V[j] = max(V[j], V[j - v[i][k]] + p[i][k]);
					}

				}
			}

		}

		std::cout << V[N] * 10 << endl;

	}

}




//int main()
//{
//	shoppingList();
//
//	int m = 5;
//	vector<vector<int>> outdata;
//	vector<int> A;
//	for (size_t i =1; i <= m; i++)
//	{
//		A.push_back(i);
//	}
//	
//	Combination(m, 3, outdata);
//	for (size_t i = 0; i < outdata.size(); i++)
//	{
//		vector<int> B = outdata[i];
//		for (int k = 0; k < B.size(); k++)
//		{
//			if (B[k] == 1)
//			{
//				cout << A[k]<<" ";
//			}
//
//		}
//		cout << endl;
//	}
//
//	return 0;
//}

/*int num;
	vector<map<int, int>> vecMap;
	cin >> num;
	do
	{

		map<int, int> input;
		int A;
		for (int i = 0; i < num; i++)
		{
			cin >> A;
			map<int, int>::iterator iter = input.find(A);
			if (iter != input.end())
			{
				continue;
			}
			else
			{
				input.insert(make_pair(A, A));
			}
		}
		vecMap.push_back(input);

	} while (cin >> num);

	for (size_t i = 0; i < vecMap.size(); i++)
	{
		map<int, int> input = vecMap[i];
		map<int, int>::iterator iterS = input.begin();
		for (; iterS != input.end(); ++iterS)
		{
			cout<< iterS->first << endl;
		}
	}*/

/*string str;
while (getline(cin, str))
{
	vector<string> vecStr;
	int start = 0;
	int pos = (int)str.find(" ",start);
	if(pos!= string::npos)
	{
		bool error = false;
		do
		{
			string sub = str.substr(0, pos);
			if (sub =="joker"|| sub == "JOKER")
			{
				error = true;
				break;
			}
			vecStr.push_back(sub);
			start = pos + 1;
			pos = (int)str.find(" ", start);

		} while (pos != string::npos);

		string sub1 = str.substr(start);
		vecStr.push_back(sub1);

		if (error || sub1 =="joker" || sub1 == "JOKER" || vecStr.size()!=4)
		{
			cout << "ERROR" << endl;
			continue;
		}

	}
	else
	{
		cout << "ERROR" << endl;
	}

}*/