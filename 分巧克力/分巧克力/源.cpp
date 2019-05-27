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
	int max_k = A[n-1]+m;
	while (m > 0)
	{
		A[0]++;
		m--;
		sort(A.begin(), A.end());
	}
	int min_k = A[n - 1];
	
	cout << min_k << " "<<max_k;
	
	system("pause");
	return 0;
	}
	
