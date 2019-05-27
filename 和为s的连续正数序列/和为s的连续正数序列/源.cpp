#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> result;

		if (sum<2)
			return result;
		int small = 1;
		int big = 2;
		int tempsum = small + big;
		while (small <= sum / 2)
		{

			if (tempsum == sum)
			{
				vector<int> temp;
				for (int i = small; i <= big; i++)
				{
					temp.push_back(i);
				}
				result.push_back(temp);
				tempsum -= small;
				small++;
				
			}
			else if (tempsum<sum)
			{
				big++;
				tempsum += big;
			}

			else
			{
				tempsum -= small;
				small++;

			}

		}

		return result;
	}
};
int main()
{
	int num;
	cin >> num;
	Solution s;
	vector<vector<int>>result;
	result= s.FindContinuousSequence(num);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j=0;j<result[i].size();j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}