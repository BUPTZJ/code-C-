#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
int getlen2(string a, string b)
{
	int len1 = a.size();
	int len2 = b.size();
	int max_len = 0;
	vector<vector<int>> matrix(len1 + 1, vector<int>(len2 + 1));
	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				matrix[i][j] = 1 + matrix[i - 1][j - 1];
				max_len = max(max_len, matrix[i][j]);
			}
				
			else
				matrix[i][j] = 0;
		}

	}
	return matrix[len1][len2];
}

// �ռ��Ż��汾��ֻ��洢���У�������Ҫ��������
int getlen3(string a, string b)
{
	int len1 = a.size();
	int len2 = b.size();
	vector<int>up(len2 + 1, 0);
	vector<int>cur(len2 + 1, 0);
	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1;j <= len2; j++)
		{
			if (a[i - 1] == b[j - 1])
				cur[j] = up[j - 1]+1;
			else
				cur[j] = max(cur[j - 1], up[j]);
		}
		up = cur;
	}
	return cur[len2];
}
//��̬�滮��ⲻ����������Ӵ�
int getlen1(string a, string b)
{
	int len1 = a.size();
	int len2 = b.size();
	vector<vector<int>> matrix(len1 + 1, vector<int>(len2 + 1));
	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (a[i - 1] == b[j - 1])
				matrix[i][j] = 1 + matrix[i - 1][j - 1];
			else
				matrix[i][j] = max(matrix[i-1][j],matrix[i][j - 1]);
		}
		
	}
	return matrix[len1][len2];
}
int main()
{
	string a = "abcddbca";
	string b = "dbacbca";
	int result = getlen3(a, b);
	cout << result;
	system("pause");
	return 0;

}