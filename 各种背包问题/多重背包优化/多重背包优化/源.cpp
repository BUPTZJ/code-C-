#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int zeroonepack(vector<int>v, vector<int>w, vector<int>count, int V)
{
	int nums = v.size();
	if (nums == 0)
		return 0;
	vector<int> value(V + 1, 0); //刚好装满仅改变初始化方式
	vector<int> newv;
	vector<int>neww;
	// 二进制拆分
	for (int i = 0; i < nums; i++)
	{
		int temp = count[i];
		for (int j = 1; j <= temp; j << 1)
		{
			newv.push_back(j*v[i]);
			neww.push_back(j*w[i]);
			temp = temp - j;

		}
		if (temp)
		{
			newv.push_back(temp*v[i]);
			neww.push_back(temp*w[i]);
		}
   }

	for (int i = 0; i<nums; i++)
	{
		if (v[i] * count[i] >= V)  // 物品足够多采用完全背包解法
		{
			for (int j = v[i]; j <= V; j++)
				value[j] = max(value[j], value[j - v[i]] + w[i]);

		}
		else
		{
		 	for (int j = V; j >= v[i]; j--)
			{
				for (int k = 0; k <= j / v[i] && k <= count[i]; k++)
					value[j] = max(value[j], value[j - k * v[i]] + k * w[i]);
			}
		}

	}
	return value[V];
}
int zeroonepack2(vector<int>v, vector<int>w, int V)
{
	int nums = v.size();
	if (nums == 0)
		return 0;
	vector<int> value(V + 1, 0); //刚好装满仅改变初始化方式
	for (int i = 0; i<nums; i++)
	{
		for (int j = v[i]; j <= V; j++)
		{

			value[j] = max(value[j], value[j - v[i]] + w[i]);
		}

	}
	return value[V];
}

int main()
{
	int N, V;
	cin >> N >> V;
	vector<int>v;
	vector<int>w;
	vector<int>count;
	for (int i = 0; i<N; i++)
	{
		int tempv, tempw, temps;
		cin >> tempv >> tempw >> temps;
		v.push_back(tempv);
		w.push_back(tempw);
		count.push_back(temps);
	}
	int maxvalue = zeroonepack(v, w, count, V);
	cout << maxvalue;
	// system("pause");
	return 0;

}