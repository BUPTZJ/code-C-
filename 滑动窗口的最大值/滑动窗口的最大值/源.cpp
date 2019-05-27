#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;
class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int>result;
		deque<int>index;
		if (num.size() < size || size < 1)
			return result;
		for (int i = 0; i < num.size(); i++)
		{
			while (!index.empty() && num[index.back()] < num[i])
				index.pop_back();
			if (!index.empty() && index.front() == i - size)
				index.pop_front();
			index.push_back(i);
			// 当索引大于等于窗口大小时，开始保存窗口最大值。
			if (!index.empty() && i >= size - 1)
				result.push_back(num[index.front()]);
		}
		return result;
	}
};

int main()
{
	vector<int> num{ 2,3,4,2,6,2,5,1 };
	vector<int>result;
	int size = 3;
	Solution s;
	result=s.maxInWindows(num, size);
	for (auto a : result)
		cout << a << " ";
	system("pause");
	return 0;

}
