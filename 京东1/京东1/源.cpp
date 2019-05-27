#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int getlen(string s)
{
	//string s = to_string(num);
	int left = 0;
	int right = 0;
	int i = 0;
	for (i; i < s.length(); i++)
	{
		if (s[i] == '1')
			left++;
		else
			break;
	}
	for (int j = s.length()-1; j >i; j--)
	{
		if (s[j] == '1')
			right++;
		else
			break;
	}

	int max_sum= left + right;
	int tempsum = 0;
	
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '1')
		{
			tempsum += 1;
			max_sum = max(max_sum, tempsum);
		}
		else
			tempsum = 0;
	}
	return max_sum;
}
int main()
{
	string num;
	cin >> num;
	int result = getlen(num);
	cout << result;
	//system("pause");
	return 0;

}