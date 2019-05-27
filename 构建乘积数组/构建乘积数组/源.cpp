#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		int len = A.size();
		vector<int>B(len, 1);
		for (int i = 1; i<len; i++)
		{
			B[i] = B[i - 1] * A[i - 1];
		}
		int temp = 1;
		for (int i = len - 2; i >= 0; i--)
		{
			temp = temp * A[i + 1];
			B[i] *= temp;
		}

		return B;
	}
};

int main()
{
	vector<int>A{ 1,2,3,4,0,6,7};
	Solution s;
	vector<int> result;
	result = s.multiply(A);
	for (auto &a : result)
		cout << a;
	system("pause");
	return 0;

}