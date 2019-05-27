#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int leaststep(vector<int>A)
{
	int len = A.size();
	if (len == 0)
		return -1;
	
	int minstep = 0x01111111;
	for (int i = 0; i < len; i++
	{
		int curstep = 0;
		for (int j = 0; j < len; j++)
		{
			curstep += A[j] * abs(j - i);
		}
		minstep = min(curstep, minstep);
	}
	return minstep;
}
int main()
{
	int N;
	cin >> N;
	vector<int> A;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		A.push_back(temp);
	}
	int result = leaststep(A);
	cout << result;
	system("pause");
	return 0;
}