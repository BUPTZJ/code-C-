#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

bool flag = true;
using namespace std;
int partition(vector<int> &nums, int left, int right)
{
	int vilot = nums[right];
	int i = left - 1;
	for (int j = left; j <right; j++)
	{
		if (nums[j] < vilot)
		{
			i++;
			if (i != j)
				swap(nums[i], nums[j]);
		}
	}
	swap(nums[right], nums[i + 1]);
	return i + 1;
}

class Solution {
	/*---------------------------解法-------------------
	i 快排，复杂度O(nlogn)
	ii 基于partition函数，O(n),缺陷，得调整数组中数字顺序
	iii 最大堆/最小堆（不断维护堆）,复杂度O(nlogk),非常适合处理海量数据
	*/
	bool cmp(int a,int b)
	{
		return a > b;
	}
public:

	int findkth1(vector<int> nums,int k)
	{
		// 使用排序
		if (nums.size() < k || k < 0)
		{
			flag = false;
			return -1;
		}
		sort(nums.begin(), nums.end(),greater<int>());
		return nums[k - 1];
	}

	
	int findkth2(vector<int> nums,int k)
	{
		if (nums.size() < k || k < 0)
		{
			flag = false;
			return -1;
		}
		int left = 0;
		int right = nums.size() - 1;
		int index = partition(nums, left, right);
		while (index != k - 1);
		{
			if (index > k-1)
			{
			    right = index - 1;
				index = partition(nums, left, right);
			}
			else if(index<k-1)
			{
				left = index + 1;
				index = partition(nums, left, right);
			}
		}
		return nums[index];
	}
	int findkth3(vector<int>nums,int k)
	{
		// 最小堆解法，复杂度klogn 维护堆k-1次
		if (nums.size() < k || k < 0)
		{
			flag = false;
			return -1;
		}
		make_heap(nums.begin(), nums.end(), greater<int>());
			for (int i = 0; i < k - 1; i++)
			{
				pop_heap(nums.begin(), nums.end(), greater<int>());
				nums.pop_back();
		    }
			return nums[0];
	}

	int findkth4(vector<int>nums, int k)
	{
		// 最大堆解法，O(nlogk)适合海量数据
		if (nums.size() < k || k < 0)
		{
			flag = false;
			return -1;
		}
		vector<int> temp;
		for (int i = 0; i < k; i++)
		{
			temp.push_back(nums[i]);
		}
		make_heap(temp.begin(),temp.end());
		for (int i = k; i < nums.size(); i++)
		{
			if (nums[i] < temp[0])
			{
				pop_heap(temp.begin(), temp.end());
				temp.pop_back();
				temp.push_back(nums[i]);
				make_heap(temp.begin(), temp.end());
			  
			}
		}
		return temp[0];
	}
};

int main()
{
	vector<int>nums{ 3,2,1,5,6,4,4,5,6};
	int k = 2;
	Solution s;
	int kth= s.findkth4(nums, k);
	cout << kth;
	system("pause");
	return 0;
}