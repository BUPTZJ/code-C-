#include<iostream>
#include<vector>
#include<algorithm>

// 该题可以看成连续数组的最大和问题
using namespace std;

class Solution {
public:
	int maxvalue(vector<int> socket)
	{
		int len = socket.size();
		if ( len== 0)
			return 0;
		int maxsum = INT32_MIN;
		int cursum = 0;
		for (int i = 1; i < len; i++)
		{
			int res = socket[i] - socket[i - 1];
			if (cursum < 0)
				cursum = res;
			else
				cursum += res;
			maxsum = max(maxsum, cursum);
			
		}
		return maxsum;

	}
};

int main()
{
	cout << INT32_MIN<<endl;
	int a = 0x80000000;
	cout <<a <<endl;
	vector<int>socket{9, 11, 8, 5,7,12,16,14 };
	Solution s;
	int result=s.maxvalue(socket);
	cout << result;
	system("pause");
	return 0;

}