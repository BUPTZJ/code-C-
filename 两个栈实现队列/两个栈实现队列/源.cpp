#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;
class Solution
{
	/* 思路： stack1 用于push数据， stack2用于pop数据
	pop前若stack2为空则将stack1数据push进satck2
	*/
public:
	void push(int node) {
		stack1.push(node);

	}

	int pop() {
		if (stack2.empty())
		{
			if (!stack1.empty())
			{
				while (!stack1.empty())
				{
					int temp = stack1.top();
					stack1.pop();
					stack2.push(temp);
				}
			}
			else
				   return NULL;  //两个都为空，没有数据可pop；
		}
		
		
			int top = stack2.top();
			stack2.pop();
			cout << top;
			return top;


	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

int main()
{
	Solution s;
	s.push(3);
	s.pop();
	system("pause");
	return 0;

}