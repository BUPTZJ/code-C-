#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int zeroonepack(vector<vector<int>>v, vector<vector<int>>w, int V)
{
	int nums =v.size();
	if (nums == 0)
		return 0;
	vector<int> value(V + 1, 0); //刚好装满仅改变初始化方式
	for (int i = 0; i < nums; i++)
	{
		int count = v[i].size();
		for (int j = V; j > 0; j--)
		{
			for (int k = 0; k <count; k++)
			{
				if(j>=v[i][k])
				  value[j]=max(value[j],value[j-v[i][k]]+w[i][k]);
			}
		}

	}
	return value[V];
}
int main()
{
	int N, V;
	cin >> N >> V;
	vector<vector<int>>v; // 行为组数，列为每一组中元素的值
	vector<vector<int>>w;
	for (int i = 0; i<N; i++)
	{
		int temps;
		vector<int> vtemp;
		vector<int>wtemp;
		cin>> temps;
		for (int j = 0; j < temps; j++)
		{
			int tempv, tempw;
		    cin >> tempv >> tempw;
			vtemp.push_back(tempv);
			wtemp.push_back(tempw);
		}	
		v.push_back(vtemp);
		w.push_back(wtemp);
	}
	int maxvalue = zeroonepack(v, w,V);
	cout << maxvalue;
	// system("pause");
	return 0;

}