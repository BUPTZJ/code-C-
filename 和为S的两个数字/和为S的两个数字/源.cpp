#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
	// 使用hashmap求解，且根据两个数靠的越近其值越大，而数组又是排序的，所以只要找到第一个he为S的就是积最小的
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		int len = array.size();
		vector<int> result;
		if (len<2)
			return result;
		unordered_map<int, int>hashmap;
		for (int i = 0; i<len; i++)
		{
			hashmap[array[i]];
		}
		cout << hashmap.count(array[3]);
		for (int i = 0; i<len; i++)
		{
			int res = sum - array[i];
			if (hashmap.find(res) != hashmap.end())
			{
				result.push_back(array[i]);
				result.push_back(res);
				break;

			}
		}
		return result;
	}

};

int main()
{
	vector<int> vec{ 1,2,4,4,11,16};
	vector<int>result;
	Solution s;
	result=s.FindNumbersWithSum(vec,10);
	for (auto a : result)
		cout << a << " ";
	system("pause");
	return 0;
	
}