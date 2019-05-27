#include <vector>
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n), w(n);//w´æ±ßµÄÈ¨Öµ
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
	}

	for (int i = 0; i < n - 1; i++) {

		for (int j = i + 1; j < n; j++) {
			if (a[j] != a[i]) {
				w[i]++;
				w[j]--;
			}
		}
		if (i != 0) {
			w[i] = w[i] + w[i - 1];
		}

		printf("%d ", w[i]);
	}

	return 0;
}
