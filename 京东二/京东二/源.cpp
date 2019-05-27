#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int getcount(vector<int>nums)
{
	int len = nums.size();
	if (len <= 0)
		return -1;
	int i = len - 1;
	while (i > 0)
	{
		if (nums[i] > nums[i - 1])
			i--;
		else
			break;

	}
	int count = i;
	return count;
}
int main()
{
	int N;
	cin >> N;
	vector<int> nums;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}
	int result = getcount(nums);
	cout << result;
	//system("pause");
	return 0;

}