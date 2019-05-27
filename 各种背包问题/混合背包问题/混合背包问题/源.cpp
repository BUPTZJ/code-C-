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
	for (int i = 0; i < nums; i++)
	{
		if (count[i] == -1) //此时为01背包问题
		{
			for (int j = V; j >= v[i]; j--)
				value[j] = max(value[j], value[j - v[i]] + w[i]);
		}
		else if (count[i] == 0)  //此时为完全背包问题
		{
			for(int j=v[i];j<=V;j++)
				value[j] = max(value[j], value[j - v[i]] + w[i]);
		}
		else
		{
			for (int j = V; j >= v[i]; j--)
			{
				for(int k=0;k<=count[i]&& k*v[i]<=j;k++)
					value[j] = max(value[j], value[j - k*v[i]] + k*w[i]);
			}
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