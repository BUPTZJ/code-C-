#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long count(int n, int k) {
	if (n == 1 || k == 1)  return 1;
	if (n < k)
		return count(n, n);
	else
		return count(n, k - 1) + count(n - k, k);
}
int main()
{
	int M,N,K;
	cin >> M>>N>>K;
	if (M > 50 || M < 1 || N>50 || N < 1 || K>50 || K < 1)
		return 0;
	long sum = 0;
	for (int i = 1; i < K; ++i) {
		sum += count(M, i) + count(N, K - i);
	}
	sum = (sum / 4) % 10000;
	cout << sum;	
	system("pause");
	return 0;

}