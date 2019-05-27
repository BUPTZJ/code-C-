#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;
/*------------01��������--------------
��N����Ʒ����������СΪV�ı�����ÿ����Ʒ�����Ϊwi,��ֵΪvi������Ի�õ�����ֵ
״̬ת�Ʒ���
if j>wi
V[i,j]=max(V[i-1,j-wi]+vi, V[i-1,j])
else
V[i,j]=V[i-1,j]
*/

// ��ά����汾
int getmaxvalue(vector<int> w, vector<int> v, int V)
{
	int nums = w.size();
	vector<int>choose(nums, 0);
	vector<vector<int>> value(nums + 1, vector<int>(V + 1, 0));
	for (int i = 1; i <=nums; i++)
	{
		for (int j = 1; j <=V; j++)
		{
			if (j < w[i - 1])
				value[i][j] = value[i - 1][j];
			else
				value[i][j] = max(value[i - 1][j - w[i - 1]] + v[i - 1], value[i - 1][j]);
		}
		
	}
	int temp = V;
	for (int i = nums; i > 0; i--)
	{
		if (value[i][temp] > value[i - 1][temp])
		{
			choose[i - 1] = 1;
			temp = temp - w[i - 1];
		}
	}
	for (auto s : choose)
		cout << s<<' ';
	return value[nums][V];

}

// һά���飬�ռ��Ż��汾��ÿ�θ���ֻ�õ���ǰһ�ε����Ľ�������迼��һ�´Ӻ���ǰ����
int getmaxvalue2(vector<int> w, vector<int> v, int V)
{
	int nums = w.size();
	vector<int>choose(nums, 0);
	vector<int> value(V + 1, 0);
	for (int i = 1; i <= nums; i++)
	{
		for (int j = V; j >=w[i-1]; j--)
		{
				value[j] = max(value[j], value[j - w[i-1]] + v[i-1]);
				
		}
	}
	return value[V];
}

// ǡ��װ����������ʼ����һ��
int getmaxvalue3(vector<int> w, vector<int> v, int V)
{
	int nums = w.size();
	vector<int>choose(nums, 0);
	vector<int> value(V + 1, INT32_MIN);
	value[0] = 0;
	for (int i = 1; i <= nums; i++)
	{
		for (int j = V; j >= w[i - 1]; j--)
		{
			value[j] = max(value[j], value[j - w[i - 1]] + v[i - 1]);

		}
	}
	return value[V];
}

// ��ȫ��������
int getmaxvalue4(vector<int> w, vector<int> v, int V)
{
	int nums = w.size();
	vector<int>choose(nums, 0);
	vector<int> value(V + 1, 0);
	for (int i = 1; i <= nums; i++)
	{
		for (int j =w[i-1]; j<=V; j++)
		{
			value[j] = max(value[j], value[j - w[i - 1]] + v[i - 1]);

		}
	}
	return value[V];
}

// ��ȫ��������ת��Ϊ01����������⣬���Ӷ�O(NVk),����ki=floor(V/wi)
int getmaxvalue5(vector<int> w, vector<int> v, int V)
{
	int nums = w.size();
	vector<int>choose(nums, 0);
	vector<int> value(V + 1, 0);
	for (int i = 1; i <= nums; i++)
	{
		for (int j = V; j >=w[i-1]; j--)
		{
			for(int k=0;k<=j/w[i-1];k++)
			 value[j] = max(value[j], value[j - k*w[i - 1]] +k* v[i - 1]);

		}
	}
	return value[V];
}

// ʹ���滻�ķ�����⣬������������ֵС���滻Ϊ���С����ֵ��ģ�
int main()
{
	int V = 12;
	vector<int>v{ 5,4,7,2,6 };
	vector<int>w{12,3,10,4,6};
	int maxvalue = getmaxvalue5(w, v, V);
	cout << maxvalue;
	system("pause");
	return 0;

}