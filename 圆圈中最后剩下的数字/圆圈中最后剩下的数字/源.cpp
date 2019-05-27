#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n < 0 || m < 0)
			return -1;
		vector<int> vec;
		for (int i = 0; i < n; i++)
		{
			vec.push_back(i);
		}
		auto current =vec.begin();
		while (vec.size() > 1)
		{
			for (int i=1; i<m; i++)
			{
				current++;
				if (current == vec.end())
					current = vec.begin();
			}
			
			auto next=vec.erase(current);
			
			if (next== vec.end())
				next = vec.begin();
			current = next;
			
		}
		return vec[0];
	}
};

int main()
{
	Solution s;
	int n, m, result;
	cin >> n >> m;
	result=s.LastRemaining_Solution(n, m);
	cout << result;
	system("pause");
	return 0;

}