#include<iostream>
#include<string>

using namespace std;
int replacestr(string str)
{
	int len = str.length();
	if (len < 2)
		return len;
	//�����ַ����������
	int i = 0;
	while (i <str.length())
	{
		if ((str[i] == '0'&&str[i + 1] == '1') || (str[i] == '1'&&str[i + 1] == '0'))
		{
			str.erase(i , 2);
			i--;
			// ��i<0˵��ǰ��û���ַ��ˣ���ʱ��ͷ��ʼ��
			if (i < 0)
				i = 0;  
		}
		else
		{
			i++;
		}
	}
	return str.length();

}


int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	//����Ƿ�����쳣����
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '0' || s[i] == '1')
			continue;
		else
			return -1;
	}
	int length = replacestr(s);
	cout <<length;
	system("pause");
	return 0;
}
