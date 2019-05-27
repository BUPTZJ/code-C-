#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
public:

	string ReverseSentence(string str) {
		string result;
		if (str.length() == 0)
			return result;
		stack<string> stack1;
		string tempstr;
		for (int i = 0; i < str.length(); i++)
		{   
			while (str[i] != ' ' && i<str.length())
			{
				tempstr += str[i];
				i++;
			}
			stack1.push(tempstr);
			tempstr.clear();
		}
		
		// ³öÕ»

		while (!stack1.empty())
		{
			string temp = stack1.top();
			stack1.pop();
			result.append(temp+' ');
		}
		 result.erase(result.length()-1,1);
		return result;
	}
};

int main()
{
	string str = "I am a student.";
	string str1{ "I am a student." };
	string result;
	Solution s;
	cout <<str<<endl;
	reverse(str.begin(), str.end());
	cout << str << endl;
	result =s.ReverseSentence(str);
	cout << result;
	cout << result.size();
	system("pause");
	return 0;

}