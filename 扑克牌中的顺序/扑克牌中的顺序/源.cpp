#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		int len = numbers.size();
		if (len<5)
			return false;
		// 统计大小王个数
		int countofzero = 0;
		for (int i = 0; i<len; i++)
		{
			if (numbers[i] == 0)
				countofzero++;
		}
		sort(numbers.begin(), numbers.end());
		// 计算gap；
		int gap = -countofzero;
		for (int i = countofzero; i<len-1; i++)
		{
			if (numbers[i] == numbers[i + 1])
				return false;
			gap += numbers[i + 1] - numbers[i] - 1;
		}
		return gap <= 0 ? true : false;

	}
};
int main()
{
	vector<int>vec{1, 0, 0, 1, 0};
	Solution s;
	bool flag= s.IsContinuous(vec);
	cout << flag;
	system("pause");
	return 0;

}