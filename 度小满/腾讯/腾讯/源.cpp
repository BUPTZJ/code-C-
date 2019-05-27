#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int minContinousSequenceSum(vector<int> nums)
{
	int len = nums.size();
	vector<vector<int>>dp(len, vector<int>(len, 0));
	int minFirst = INT_MAX;
	int idxL = 0;
	int idxR = 0;
	for (int i = 0; i < len; i++)
	{
		dp[i][i] = nums[i];
		if (dp[i][i] < minFirst)
		{
			minFirst = dp[i][i];
			idxL = i;
			idxR = i;

		}
	}
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			dp[i][j] = dp[i][j - 1] + nums[j];
			if (dp[i][j] < minFirst)
			{
				minFirst = dp[i][j];
				idxL = i;
				idxR = j;
			}
		}
	}
	int minLeft = INT_MAX;
	for (int i = 0; i < idxL&&i < idxR; i++)
	{
		for (int j = i; j < idxL&&j < idxR; j++)
		{
			if (dp[i][j] < minLeft)
				minLeft = dp[i][j];
		}
	}
	int minRight= INT_MAX;
	for (int i = len-1; i > idxL&&i > idxR; i--)
	{
		for (int j = i; j > idxL&&j > idxR; j--)
		{
			if (dp[i][j] < minRight)
				minRight = dp[i][j];
		}
	}
	int res = 0;
	if (minLeft < minRight)
	{
		res = minFirst + minLeft;
	}
	else
		res = minFirst + minRight;
	return res;
}
int main()
{
	vector<int>nums;
	char c;
	int tmp;
	while ((c = getchar()) != '\n')
	{
		if (c != ' ')
		{
			ungetc(c, stdin);
			cin >> tmp;
			nums.push_back(tmp);
		}
	}
	int res = minContinousSequenceSum(nums);
	cout << res << endl;
	// system("pause");
	return 0;
}