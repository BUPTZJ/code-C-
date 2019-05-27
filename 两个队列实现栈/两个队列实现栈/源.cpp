#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
class Solution {
public:
	void pop() {
		if (!q1.empty())
		{
			while (q1.size() > 1)
			{
				int top = q1.front();
				q1.pop();
				q2.push(top);
			}
			int front = q1.front();
			q1.pop();
			cout << front;
		}
		if (!q2.empty())
		{
			while (q2.size() > 1)
			{
				int top = q2.front();
				q2.pop();
				q1.push(top);
			}
			int front = q2.front();
			q2.pop();
			cout << front<<" ";
		}
		else
			return;//两个都为空

	}
	void push(int node)
	{
		if (!q1.empty())
			q1.push(node);
		else
			q2.push(node);
	}
private:
	queue<int> q1;
	queue<int> q2;
};

int main()
{
	Solution s;
	s.push(3);
	s.push(4);
	s.pop();
	s.pop();
	system("pause");
	return 0;

}