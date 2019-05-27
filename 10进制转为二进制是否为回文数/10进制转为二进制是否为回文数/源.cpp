#include<iostream>

using namespace std;

bool ishuiwen(string str)
{
	for (int i = 0; i<str.length() / 2; i++) {
		if (str[i]!= str[str.length() - i - 1])
			return false;
	}
	return true;

}
string InttoBinaryString(long long x)
{
	long i = 1;
	string ret;
	while (i != 0)
	{
		if ((i&x) == i)
		{
			ret += '1';
		}
		else
			ret += '0';
		i = i << 1;
	}
	long j = ret.size() - 1;
	while (j >= 0 && ret[j] == '0')
		j--;

	string r;
	for (j; j >= 0; j--)
	{
		r += ret[j];
	}
	return r;
}

long long counthuiwen(long long N)
{
if (N < 0)
     return -1;
long long count = 0;
long long start = 0;
while (start <= N)
{
	string temp = InttoBinaryString(start);
  if (ishuiwen(temp))
  {
     count++;
  }
     start++;

}
return count;
}


int main()
{
	long long N;
	cin >> N;
	long long result=counthuiwen(N);
	cout << result;
	system("pause");
	return 0;

}