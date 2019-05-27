#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>


using namespace std;

int gcd(int a, int b)
{
	return b > 0 ? gcd(b, a%b) : a;
}
int countGroups(vector<int>&nums) {
	unordered_map<int, int> count;
	int res = 0;
	for (int i : nums) count[i]++;
	for (auto i : count) res = gcd(i.second, res);
	return res>1?nums.size()/res:0 ;
}



int main()
{
	int N;
	cin >> N;
	vector<int>nums;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}
	int result;
	result = countGroups(nums);
	cout << result;
	//system("pause");
	return 0;
}