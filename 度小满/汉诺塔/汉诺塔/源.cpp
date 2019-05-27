#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
	

int main() {
	int n;
	int m;
	cin >> n;
	cin >> m;
	vector<int>A;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		A.push_back(a);
	}
	sort(A.begin(), A.end());
	int max_k = A[n - 1] + m;
	int temp1 = m / n;
	int min_k = A[n - 1] + temp1;
	cout << min_k << " " << max_k;
	//system("pause");
	return 0;
}