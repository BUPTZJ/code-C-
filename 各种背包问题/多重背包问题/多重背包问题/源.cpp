#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*---------------��������-----------------
�� N ����Ʒ��һ������Ϊ V �ı������� i ����Ʒ����� Mi �����ã�ÿ���ķѵ�
�ռ��� Ci����ֵ�� Wi��
����i �� ת��Ϊ0/1�������⣬���Ӷȣ�O(Vsum(Mi))��
����ii: ���Mi�����Ӷȣ�O(Vsum(logMi))��

*/
// ����2
int getmaxvalue(vector<int> w, vector<int> v,vector<int>count,int V)
{
	int nums = w.size();
	vector<int> neww;
	vector<int> newv;
	for (int i = 0; i < nums; i++)
	{
		int k = 1;
		int M = count[i];
		while (k <M)
		{
			M = M - k;
			k = k * 2;
			neww.push_back(k*w[i]);
			newv.push_back(k*v[i]);
		}
		neww.push_back(M*w[i]);
		newv.push_back(M*v[i]);
	}
	vector<int>value(V + 1, 0);
	for (int i = 1; i <= neww.size(); i++)
	{
		for (int j = V; j >= neww[i-1]; j--)
		{
			value[j] = max(value[j], value[j - neww[i-1]] + newv[i-1]);
		}
	}
	return value[V];

}

// ����1
int getmaxvalue2(vector<int> w, vector<int> v, vector<int>count, int V)
{
	int nums = w.size();
	vector<int>value(V+ 1, 0);
	for (int i = 1; i <= w.size(); i++)
	{
		for (int j = V; j >= w[i - 1]; j--)
		{
			for(int k=0;k<=count[i-1]&&k*w[i-1]<=j;k++)
			  value[j] = max(value[j], value[j - k*w[i - 1]] + k*v[i - 1]);
		}
	}
	return value[V];
}

int main()
{
	vector<int> w{2,4 };
	vector<int> v{ 100,100 };
	vector<int>count{4,2 };
	int V = 8;
	int result = getmaxvalue2(w,v,count,V);
	int result2 = getmaxvalue(w, v, count, V);
	cout << result<<endl;
	cout << result2;
	system("pause");
	return 0;

}