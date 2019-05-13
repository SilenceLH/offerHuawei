// offerHuawei.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "string"
#include "vector"
#include "map"
#include "unordered_map"
using namespace std;

class Sultion {
	/************************************************************************/
	/*                        1、字符串最后一个单词的长度
	题目描述：计算字符串最后一个单词的长度，单词以空格隔开。
	*/
	/************************************************************************/
	int main_1()
	{
		string s;
		while (getline(cin, s))
		{
			int len = s.length();
			int num = 0;
			while (s[len - 1] == ' ') {
				len--;
			}
			for (int i = len - 1; i >= 0; i--)
			{
				if (s[i] == ' ')
				{
					break;
				}
				num++;
			}
			cout << num << endl;
		}
		return 0;
	}
	/************************************************************************/
	/*                           2\计算字符个数
	题目描述;写出一个程序，接受一个由字母和数字组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写。
	*/
	/************************************************************************/
	int main_2()
	{
		string s;
		char str;
		int num = 0;
		while (getline(cin, s))
		{
			cin >> str;
			for (int i = 0; i < s.length(); i++)
			{
				if (str == s[i] || str + 32 == s[i] || str - 32 == s[i])
				{
					num++;
				}
			}
		}
		cout << num << endl;
		return 0;
	}
	/************************************************************************/
	/*                      3\明明的随机数
	题目描述:明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，
	他先用计算机生成了N个1到1000之间的随机整数（N≤1000），对于其中重复的数字，
	只保留一个，把其余相同的数去掉，不同的数对应着不同的学生的学号。
	然后再把这些数从小到大排序，按照排好的顺序去找同学做调查。
	请你协助明明完成“去重”与“排序”的工作(同一个测试用例里可能会有多组数据，
	希望大家能正确处理)。
	*/
	/************************************************************************/
	int main_3() {
		int N, n;
		while (cin >> N) {
			int a[1001] = { 0 };
			while (N--) {
				cin >> n;
				a[n] = 1;
			}
			for (int i = 0; i < 1001; i++)
				if (a[i])
					cout << i << endl;
		}
		return 0;
	}
	/************************************************************************/
	/*                            4、字符串分隔
	题目描述
	•连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组；
	•长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
	*/
	/************************************************************************/
	int main_4()
	{
		vector<vector<char>> res;
		vector<char> temp;
		string s1;
		string s2;
		getline(cin, s1);
		getline(cin, s2);
		int len_s1 = s1.size();
		int len_s2 = s2.size();
		for (int i = 0; i < len_s1; i++)
		{
			if (temp.size() == 8)
			{
				res.push_back(temp);
				temp.clear();
			}
			temp.push_back(s1[i]);
		}
		int len = temp.size();
		if (len != 0)
		{
			for (int i = 0; i < 8 - len; i++)
				temp.push_back('0');
		}
		res.push_back(temp);
		temp.clear();

		for (int i = 0; i < len_s2; i++)
		{
			if (temp.size() == 8)
			{
				res.push_back(temp);
				temp.clear();
			}
			temp.push_back(s2[i]);
		}
		len = temp.size();
		if (len != 0)
		{
			for (int i = 0; i < 8 - len; i++)
				temp.push_back('0');
		}
		res.push_back(temp);
		temp.clear();
		for (int i = 0; i < res.size(); i++)
		{
			for (int j = 0; j < 8; j++)
			{
				cout << res[i][j];
			}
			cout << endl;
		}
		return 0;
	}
	/************************************************************************/
	/*                             5\进制转换
	题目描述:写出一个程序，接受一个十六进制的数值字符串，输出该数值的十进制字符串。（多组同时输入 ）
	*/
	/************************************************************************/
	int main_5() {
		string str;

		while (getline(cin, str)) {
			if (str.length() <= 0) break;

			long num = 0; int index = 16;
			for (int i = 2; i < str.length(); ++i) {
				if (str[i] >= '0' && str[i] <= '9')
					num = num * 16 + (str[i] - '0');
				else
					num = num * 16 + (str[i] - 'A' + 10);
			}
			cout << num << endl;
		}

		return 0;
	}
	/************************************************************************/
	/*                            6\质数因子
	题目描述:功能:输入一个正整数，按照从小到大的顺序输出它的所有质数的因子（如180的质数因子为2 2 3 3 5 ）最后一个数后面也要有空格
	*/
	/************************************************************************/
	int main_6()
	{
		long num;
		cin >> num;
		while (num != 1)
		{
			for (int i = 2; i <= num; i++)
			{
				if (num % i == 0)
				{
					num = num / i;
					cout << i << ' ';
					break;
				}
			}

		}

		return 0;
	}
	/************************************************************************/
	/*                             7\取近似值
	题目描述:写出一个程序，接受一个正浮点数值，输出该数值的近似整数值。如果小数点后数值大于等于5,向上取整；小于5，则向下取整。
	*/
	/************************************************************************/
	int main_7()
	{
		float res;
		cin >> res;
		cout << int(res + 0.5) << endl;
	}
	/************************************************************************/
	/*                            8\合并表记录
	题目描述:数据表记录包含表索引和数值，请对表索引相同的记录进行合并，即将相同索引的数值进行求和运算，输出按照key值升序进行输出。
	*/
	/************************************************************************/
	int main_8()
	{
		int n;
		cin >> n;
		map<int, int> m;
		int key, value;
		for (int i = 0; i < n; i++)
		{

			cin >> key >> value;
			if (!m[key])
			{
				m[key] = value;
			}
			else
			{
				m[key] += value;
			}
		}
		for (map<int, int> ::iterator k = m.begin(); k != m.end(); k++)
		{
			cout << k->first << " " << k->second << endl;
		}
		return 0;
	}
	/************************************************************************/
	/*                            9\提取不重复的整数
	题目描述:输入一个int型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数。
	*/
	/************************************************************************/
	int main_9()
	{
		int num;
		cin >> num;
		int arr[10] = { 0 };
		int temp = 0;
		while (num != 0)
		{
			temp = num % 10;
			if (arr[temp] == 0)
			{
				cout << temp;
			}
			arr[temp] = 1;
			num = num / 10;
		}
		return 0;
	}
	/************************************************************************/
	/*                          10\字符个数统计
	题目描述:编写一个函数，计算字符串中含有的不同字符的个数。字符在ACSII码范围内(0~127)。不在范围内的不作统计。
	*/
	/************************************************************************/
	int main_10()
	{
		string s;
		cin >> s;
		int num = 0;
		int char_num[127] = { 0 };
		int len = s.length();
		for (int i = 0; i < len; i++)
		{
			int temp = s[i];
			if (temp < 127 && temp > 0 && char_num[temp] == 0)
			{
				num++;
				char_num[temp] = 1;
			}
		}
		cout << num;
		return 0;
	}



};


int main()
{
	string s;
	cin >> s;
	int num = 0;
	int char_num[127] = { 0 };
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		int temp = s[i];
		if (temp < 127 && temp > 0 && char_num[temp] == 0)
		{
			num++;
			char_num[temp] = 1;
		}
	}
	cout << num;
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
