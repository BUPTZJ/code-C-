#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，
字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
思路： 遍历字符串，把错的排除掉就ok了。主要有以下错误
i 小数点出现两次为错,且e后面不能有小数点
ii 若加号是第二次出现，且其前面不为e，则为错误
iii e只能出现一次，且e前面必须有数

*/

class Solution {
public:
	bool isNumeric(const char* string)
	{
		if (string == nullptr)
			return false;
		int hasE = false;
		int decimal = false;
		for (int i = 0; i < strlen(string); i++)
		{
			if (string[i] == 'E' || string[i] == 'e')
			{
				if (hasE)
					return false;
				if (i == strlen(string) - 1)
				{
					return false;
				}
				hasE = true;
			}
			else if (string[i] == '+' || string[i] == '-')
			{
				if (i > 0 && string[i - 1] != 'E'&&string[i - 1] != 'e') return false;

			}
			else if (string[i] == '.')
			{
				if (decimal || hasE) return false;
				
				decimal = true;
			}
			else if (string[i] > '9' || string[i] < '0')
				return false;
	   }
		return true;
		
	}

};

int main()
{
	Solution s;
	const char* str="123.45e+6";
	bool result = s.isNumeric(str);
	cout << result;
	system("pause");
	return 0;

}