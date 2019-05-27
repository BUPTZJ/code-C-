#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<vector<int>>result(N+1, vector<int>(N+1));
	result[0][0] = 1;
	for (int i = 0; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i < j)
				result[i][j] = result[i][i];
			else
				result[i][j] = result[i][j - 1] + result[i - j][j];
		}
	}
	cout << result[N][N];
	//system("pause");
	return 0;
}