#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int zeroonepack(vector<int>v, vector<int>w, int V)
{
	// ��value(i,j)==value[i-1,j] && value(i,j)!=value[i-1,j-v[i]]+w[i], ��maxcount(i,j)=maxcount[i-1,j]
	// ��value(i,j)!=value[i-1,j] && value(i,j)==value[i-1,j-v[i]]+w[i], ��maxcount(i,j)=maxcount[i-1,j-v[i]]
	// ��value(i,j)==value[i-1,j] && value(i,j)==value[i-1,j-v[i]]+w[i], ��maxcount(i,j)=maxcount[i-1,j-v[i]]+maxcount[i-1,j]
	int nums = v.size();
	if (nums == 0)
		return 0;
	vector<int> value(V + 1, 0); //�պ�װ�����ı��ʼ����ʽ
	vector<int> maxcount(V + 1, 1); // ��������ֵ�µķ�������
	for (int i = 0; i<nums; i++)
	{
		for (int j = V; j >= v[i]; j--)
		{
			if (value[j] < value[j - v[i]] + w[i])
			{
				value[j] = value[j - v[i]] + w[i];
				maxcount[j] = maxcount[j - v[i]];
			}
			else if (value[j] == value[j - v[i]] + w[i])
			{
				maxcount[j] = maxcount[j - v[i]] + maxcount[j];
			}


		}
	}
	return maxcount[V];
}

int main()
{
	int N, V;
	cin >> N >> V;
	vector<int>v;
	vector<int>w;
	for (int i = 0; i<N; i++)
	{
		int tempv, tempw;
		cin >> tempv >> tempw;
		v.push_back(tempv);
		w.push_back(tempw);
	}
	int maxvalue = zeroonepack(v, w, V);
	cout << maxvalue;
	// system("pause");
	return 0;
}