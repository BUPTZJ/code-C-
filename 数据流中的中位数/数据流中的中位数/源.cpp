#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>


using namespace std;

class Solution1 {
public:
	vector<int>vec;
	void Insert(int num)
	{
		
		vec.push_back(num);
		for (int i = vec.size() - 1; i > 0 && vec[i] > vec[i - 1]; i--)
			swap(vec[i], vec[i - 1]);
	}

	double GetMedian()
	{
		int len = vec.size();
		return (vec[len >> 1] + vec[(len - 1)>>1]) / 2.0;
	}
	
};
class Solution2
{
public:
	void Insert(int num)
	{
		if (((min.size() + max.size())&1)==0)
		{
			if (max.size() > 0 && num < max[0])
			{
				max.push_back(num);
				push_heap(max.begin(), max.end(), less<int>());
				num = max[0];
				pop_heap(max.begin(), max.end(), less<int>());
				max.pop_back();
			}
			min.push_back(num);
			push_heap(min.begin(), min.end(), greater<int>());

		}
		else
		{
			if (min.size() > 0 && num > min[0])
			{
				min.push_back(num);
				push_heap(min.begin(), min.end(), greater<int>());
				num = min[0];
				pop_heap(min.begin(), min.end(), greater<int>());
				min.pop_back();
			}
			max.push_back(num);
			push_heap(max.begin(), max.end(), less<int>());
		}

	}
	double GetMedian()
	{
		int size= min.size() + max.size();
		if (size == 0)
			return -1;
		double median = (size & 1 == 1) ? min[0] : (max[0] + min[0]) / 2.0;
		return median;
	}
private:
	vector<int> max;
	vector<int >min;
};

int main()
{
	Solution2 s2;
	s2.Insert(2);
	s2.Insert(3);
	s2.Insert(1);
	cout << s2.GetMedian();
	system("pause");
	return 0;

}
