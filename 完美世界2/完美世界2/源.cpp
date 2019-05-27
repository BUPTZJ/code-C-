#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int>result(N + 1);
	if (N == 1)
		return 0;
	if (N == 2)
		return 1;
	result[2] = 1;
	for (int i = 3; i <= N; i++)
	{
		result[i] = (i - 1)*(result[i - 1] + result[i - 2]);
	}
	cout << result[N];
	system("pause");
	return 0;
}