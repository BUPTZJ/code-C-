#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
	// ʹ��hashmap��⣬�Ҹ�������������Խ����ֵԽ�󣬶�������������ģ�����ֻҪ�ҵ���һ��heΪS�ľ��ǻ���С��
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