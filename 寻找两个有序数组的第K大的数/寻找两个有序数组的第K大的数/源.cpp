#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
// 归并排序找第K大
int getkth(vector<int>a, vector<int>b,int k)
{
	int len1 = a.size();
	int len2 = b.size();
	vector<int>mer(len1 + len2);
	int i = 0, j = 0, count = 0;
	while (i < len1 && j < len2)
	{
		if (i >= len1)
			a[i] = INT32_MAX;
		if (j >= len2)
			b[j] = INT32_MAX;  //过界处理
	
		if (a[i] < b[j])
		{
			mer[count++] = a[i++];

		}
		else
		{
			mer[count++] = b[j++];
		}
		if (count == k)
			return mer[k - 1];
	}
}
// 基于二分法求第K大的数
int getkth2(a, b, 4)
{

}
int main()
{
	vector<int>a{1,3,6,94};
	vector<int>b{2,4,5,8,10,22};
	int result = getkth(a, b,4);
	cout << result;
	system("pause");
	return 0;

}