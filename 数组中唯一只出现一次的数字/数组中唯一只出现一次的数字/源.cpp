#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;
// ��һ�������г�һ�����ֳ���һ�����⣬�������ֶ����������Σ����ҳ��Ǹ�ֻ����һ�ε����֡�
int main()
{
	vector<int> vec{ 1,1,2, 2, 2, 3, 3, 3, 4,4 ,4 };
	unordered_map<int, int>hashmap;
	for (int i = 0; i < vec.size(); i++)
	{
		hashmap[vec[i]]++;
	}

	// ����hashmap
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