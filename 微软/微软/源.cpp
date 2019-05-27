#include<iostream>
#include<vector>

using namespace std;
double x_l = 0.0;
double x_r = 1.0;
double y_low= 0.0;
double y_high = 1.0;
vector<double> getxy(vector<int> input)
{
	int len = input.size();
	vector<double> result;
	if (len == 0)
	{
		result.push_back(x_r);
		result.push_back(y_high);
	}
	for (int i = 0; i < len; i++)
	{
		if (input[i] == 1)
		{
			x_r = (x_l+x_r)/2;
			y_low = (y_low + y_high) / 2;
		}
		if (input[i] == 2)
		{
			x_l = (x_l + x_r) / 2;
			y_low= (y_low + y_high) / 2;
		}
		if (input[i] == 3)
		{
			x_r = (x_l + x_r) / 2;
			y_high = (y_low + y_high) / 2;
		}
		if (input[i] == 4)
		{
			x_l = (x_l + x_r) / 2;
			y_high = (y_low + y_high) / 2;
		}
	}
	result.push_back(x_r);
	result.push_back(y_high);
	return result;
}
int main() {
	vector<int> input;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		input.push_back(temp);
	}
	vector<double>result = getxy(input);
	for (auto s : result)
		cout << s << ',';
	system("pause");
	return 0;
}