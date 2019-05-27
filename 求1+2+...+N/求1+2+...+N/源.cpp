#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
// 题目:求1+2+ ... +n, 要求不能使用乘除法、for 、while、if、else、switch、case等
class Solution {
public:
	int Sum_Solution(int n) {
		int result = n;
		result && (result += Sum_Solution(n - 1));  //运用短路性质，左边为假右边就不需要计算
		return result;
	}
};

int main()
{
	int n=10;
	Solution s;
	cout <<s.Sum_Solution(n);
	system("pause");
	return 0;

}