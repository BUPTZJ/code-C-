#include<iostream>
using namespace std;
void exchange(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
long getmaxproduct(int *A)
{
	// 考虑到无序数组中包含负数，故乘积最大的三个数为最大的三个正数，或者最大的一个正数与最小的两个负数，
	// 故问题就简化为求最大的三个正数以及最小的两个负数
	
	int j = 0;
	while (j<3)
	{
		int index_max = j;
		for (int i = j+1; i<sizeof(A) /sizeof( A[0]); i++)
		{
			if (A[i]>A[index_max])
				index_max=i;
		}
		exchange(A[index_max], A[j]);
		j++;
	}
	long a = A[0] * A[1] *A[2];
	long b = A[0] * A[1] * A[2];
	return a>b ? a : b;
}
int main()
{
	/*int len;
	cin >> len;
	int *A = new int[len];
	if (len<3)
		return NULL;
	for (int i = 0; i<len; i++)
	{
		cin >> A[i];
	}
	*/
	int A[4] = {4,1,2,3};
	cout << sizeof(A) / sizeof(A[0]);
	long result = getmaxproduct(A);
	cout << result;
	int j = 0;
	while (j<3)
	{
		int index_max = j;
		for (int i = j + 1; i<sizeof(A) / sizeof(A[0]); i++)
		{
			if (A[i]>A[index_max])
				index_max = i;
		}
		exchange(A[index_max], A[j]);
		j++;
	}
	system("pause");
	//delete[]A;
	return 0;
	
}