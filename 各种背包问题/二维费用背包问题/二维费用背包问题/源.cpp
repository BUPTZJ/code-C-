#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*-----------------问题描述---------------
具有两种不同的费用；选择这件物品必须同时付出这两种代价；
对于每种代价都有一个可付出的最大值（背包容量）
比如常见的隐藏的约束，即最多只能取多少件物品，或者刚好只能取M件（初始化不一样）
*/
int getmaxvalue(vector<int>v, vector<int>m, vector<int>w,int V,int M ) {
	int nums = v.size();
	vector<vector<int>> value(V+1, vector<int>(M+1, 0));
	for (int i = 0; i < nums; i++)
	{
		for (int j = V; j >= v[i]; j--)
		{
			for (int k = M; k >= m[i]; k--)
			{
				value[j][k] = max(value[j][k], value[j - v[i]][k - m[i]] + w[i]);
			}

		}
	}
	return value[V][M];

}

int main()
{
	int N, V, M;
	cin >> N >> V >> M;
	vector<int>v;
	vector<int>m;
	vector<int>w;
	for (int i = 0; i < N; i++)
	{
		int tempv, tempm, tempw;
		cin >> tempv >> tempm >> tempw;
		v.push_back(tempv);
		m.push_back(tempm);
		w.push_back(tempw);
	}
	int maxvalue = getmaxvalue(v,m,w,V,M);
	cout << maxvalue;
	system("pause");
	return 0;

}