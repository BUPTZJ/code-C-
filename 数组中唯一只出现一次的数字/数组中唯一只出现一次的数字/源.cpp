#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;
// 在一个数组中除一个数字出现一次以外，其他数字都出现了三次，请找出那个只出现一次的数字。
int main()
{
	vector<int> vec{ 1,1,2, 2, 2, 3, 3, 3, 4,4 ,4 };
	unordered_map<int, int>hashmap;
	for (int i = 0; i < vec.size(); i++)
	{
		hashmap[vec[i]]++;
	}

	// 遍历hashmap
	unordered_map<int, int>::iterator it;
	for (it = hashmap.begin(); it != hashmap.end(); it++)
	{
		if (it->second == 2)
		{
			cout << it->first;
			break;
		}
			

	}

	system("pause");
	return 0;
}