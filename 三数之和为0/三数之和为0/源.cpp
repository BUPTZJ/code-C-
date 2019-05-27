#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
	// 可以看作target不断变化的两数之和，故可以先排序，然后不断夹逼，做的时候注意去重。
public:
	vector<vector<int>> threesum(vector<int>&nums)
	{
		vector<vector<int>>result;
		if (nums.size() <= 2)
			return result;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; i++)
		{
			if (nums[i] > 0)
				break;
			if (i>0 &&nums[i] == nums[i - 1])
				continue;
			int target = -nums[i];
			int left = i + 1;
			int right = nums.size() - 1;
			while (left < right)
			{
				if (nums[left] + nums[right] == target)
				{
					vector<int>temp;
					temp.push_back(-target);
					temp.push_back(nums[left]);
					temp.push_back(nums[right]);
					result.push_back(temp);
					while ( left<right&&nums[left] == nums[left + 1] ) left++;
					while (right>left&&nums[right] == nums[right - 1]  ) right--;
					left++;
					right--;
				}
				else if (nums[left] + nums[right] < target)
					left++;
				else
					right--;
			}
		}
		return result;
	}
};

int main()
{
	vector<int>nums{ 0,0,0 };
	vector<vector<int>>result;
	Solution s;
	result = s.threesum(nums);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j]<<",";
		cout << endl;
	}
	system("pause");
	return 0;

}