#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> nums;
	vector<string> strings;
	int num;
	string s;
	while (!cin.eof())
	{
		cin >> num >> s;
		if (cin.eof() == 1)
			break;
		nums.push_back(num);
		strings.push_back(s);
	}
	for (auto s : nums)
		cout << s<<" ";
	cout << endl;
	for (auto s : strings)
		cout << s << " ";
	system("pause");
	return 0;

}