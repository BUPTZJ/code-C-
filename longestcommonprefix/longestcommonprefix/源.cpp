#include<iostream>
#include<string>
#include<vector>
#include<array>
#include<unordered_set>
using namespace std;
int lengthOfLongestSubstring(string s) {
	int n = s.size();
	unordered_set<char> Hashset;
	int ans = 0, i = 0, j = 0;
	while (i<n && j<n)
		if (!Hashset.count(s[j])) {
			Hashset.insert(s[j]);
			ans = max(ans, j - i+1);
			j++;	
		}
		else {
			Hashset.erase(s[i]);
			i++;
		}
		return ans;

}




	
int main()
{
	string a = "pwwkew";
	int len=0;
	len = lengthOfLongestSubstring(a);
	cout << len;
	system("pause");
}
