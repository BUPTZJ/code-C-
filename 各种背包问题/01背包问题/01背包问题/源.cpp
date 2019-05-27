#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;
/*------------01背包问题--------------
把N个物品放入容量大小为V的背包，每个物品的体积为wi,价值为vi，求可以获得的最大价值
状态转移方程
if j>wi
V[i,j]=max(V[i-1,j-wi]+vi, V[i-1,j])
else
V[i,j]=V[i-1,j]
*/

// 二维数组版本
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

// 一维数组，空间优化版本，每次更新只用到了前一次迭代的结果，但需考虑一下从后往前更新
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

// 恰好装满，仅仅初始化不一样
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

// 完全背包问题
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

// 完全背包问题转化为01背包问题求解，复杂度O(NVk),其中ki=floor(V/wi)
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

// 使用替换的方法求解，即将体积大而价值小的替换为体积小而价值大的，
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