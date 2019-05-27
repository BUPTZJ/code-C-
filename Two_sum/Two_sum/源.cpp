#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;
class Solution {
public:
	vector<int> twosum(vector<int> nums, int target)
	{
		vector<int>result;
		if (nums.size()< 2)
			return result;
		unordered_map<int, int>map;
		for (int i = 0; i < nums.size(); i++)
		{
			
			int res =target - nums[i];
			if (map[res] != 0) 
			{
				if(i !=map[res]-1)
				{
					result.push_back(map[res] - 1);
					result.push_back(i);
				}		
			}
			map[nums[i]] = i + 1; // ±ÜÃâ0µÄÓ°Ïì
		}
		return result;
	}
};
int main()
{
	vector<int> nums{ 2,7,11,15 };
	Solution s;
	vector<int>result;
	result = s.twosum(nums,9);
	for (auto s : result)
		cout << s<<" ";

	system("pause");
	return 0;

}