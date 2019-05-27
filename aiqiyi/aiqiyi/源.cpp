#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

vector<int> resort(vector<int> nums, vector<int> T, vector<int> X)
{
	if (nums.empty() || T.size()==0)
		return nums;
	int M = T.size();
	for (int i = 0; i < M; i++)
	{
		if (T[i] == 0)
		{
			sort(nums.begin(), nums.begin()+ X[i]);
		}
		if (T[i] == 1)
		{
			sort(nums.begin(), nums.begin() + X[i], greater<int>());
		}
	}
	return nums;
}

int main(){
// ÊäÈë
	int N, M;
	cin >> N >> M;
	vector<int>nums;
	vector < int>T;
	vector<int>X;
	vector<int>results;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}
	for (int i = 0; i < M; i++)
	{
		int t, x;
		cin >> t >> x;
		if (t < 0 || t>1)
			return -1;
		if (x<1 || x>N)
			return -1;
		T.push_back(t);
		X.push_back(x);
	}
	results = resort(nums, T, X);
	for (auto s : results)
	{
		cout << s << " ";
	}
	system("pause");
	return 0;
}
