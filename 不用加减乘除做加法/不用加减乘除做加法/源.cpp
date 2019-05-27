#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int Add(int num1, int num2)
	{
		do {
			int sum = num1 ^ num2;
			int carry = (num1 & num2) << 1;
			num1 = sum;
			num2 = carry;
		}
		while (num2 != 0);
		return num1;
	}

	
};

int main()
{
	int num1 = 5;
	int num2 = 3;
	Solution s;
	int result=s.Add(num1, num2);
	cout << result;
	system("pause");
	return 0;

}