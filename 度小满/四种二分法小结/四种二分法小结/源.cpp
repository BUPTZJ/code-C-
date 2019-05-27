#include<iostream>
#include<vector>

using namespace std;
// 构建四种二分查找法
int BS1(vector<int> vec, int x)
{
	// 双闭区间
	int left = 0;
	int right = vec.size();
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (vec[mid] >= x)
			right = mid-1;
		else 
			left = mid + 1;		
	}
	return left;
}

	int BS2(vector<int> vec, int x)
	{
		// 双闭区间
		int left = 0;
		int right = vec.size();
		while (left<=right)
		{
			int mid = (left + right) / 2;
			if (vec[mid] <=x)
				left = mid+1;
			else
				right = mid-1;
		}
		return right;
}



int main() {
	vector<int> vec{ 3,3,3};
	int left = BS1(vec, 3);
	int right = BS2(vec, 3);
	cout << "left:" << left << endl;
	cout << "right:" << right << endl;
	system("pause");
	return 0;
}