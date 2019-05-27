#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

enum Status {kvaild=0,kInvaild};
int g_nStatus = kvaild;

class Solution {
public:
	int StrToInt(string str) {
		g_nStatus = kInvaild;
		long long num = 0;
		int digits = 0;
		if (str.length()>=1)
		{
			bool minus = false;
			if (str[digits] == '+')
				digits++;
			else if (str[digits] == '-')
			{
				digits++;
				minus = true;
			}	
			if (str.begin() + digits != str.end())
			{
				
				num = StrtoIntCore(str, minus,digits);
			}
		}
		return num;
	}
	long long StrtoIntCore(string str, bool minus,int digits)
	{
		long long num = 0;
		while (digits< str.length())
		{
			
			if (str[digits] >= '0' && str[digits] <= '9')
			{
				int flag = minus ? -1 : 1;
				num = num * 10 + flag*(str[digits] - '0');
				// 判断是否超出数的范围
				if ((!minus&&num > 0x70000000) || (minus&&num < (signed int)0x80000000))
				{
					num = 0;
					break;
				}
				digits++;
			}
			else
			{
				num = 0;
				break;
			}
		}
		if (digits = str.length())
			g_nStatus = kvaild;
		return num;
	}
};   


int main()
{
	string str = "-";
	Solution s;
	int result = s.StrToInt(str);
	cout << result;
	
	system("pause");
	return 0;
	
}