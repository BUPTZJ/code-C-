#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*
��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С���������磬
�ַ���"+100","5e2","-123","3.1416"��"-1E-16"����ʾ��ֵ��
����"12e","1a3.14","1.2.3","+-5"��"12e+4.3"�����ǡ�
˼·�� �����ַ������Ѵ���ų�����ok�ˡ���Ҫ�����´���
i С�����������Ϊ��,��e���治����С����
ii ���Ӻ��ǵڶ��γ��֣�����ǰ�治Ϊe����Ϊ����
iii eֻ�ܳ���һ�Σ���eǰ���������

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