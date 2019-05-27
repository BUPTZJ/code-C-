#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
/*-----------------��������---------------
�������ֲ�ͬ�ķ��ã�ѡ�������Ʒ����ͬʱ���������ִ��ۣ�
����ÿ�ִ��۶���һ���ɸ��������ֵ������������
���糣�������ص�Լ���������ֻ��ȡ���ټ���Ʒ�����߸պ�ֻ��ȡM������ʼ����һ����
*/
int getmaxvalue(vector<int>v, vector<int>m, vector<int>w,int V,int M ) {
	int nums = v.size();
	vector<vector<int>> value(V+1, vector<int>(M+1, 0));
	for (int i = 0; i < nums; i++)
	{
		for (int j = V; j >= v[i]; j--)
		{
			for (int k = M; k >= m[i]; k--)
			{
				value[j][k] = max(value[j][k], value[j - v[i]][k - m[i]] + w[i]);
			}

		}
	}
	return value[V][M];

}

int main()
{
	int N, V, M;
	cin >> N >> V >> M;
	vector<int>v;
	vector<int>m;
	vector<int>w;
	for (int i = 0; i < N; i++)
	{
		int tempv, tempm, tempw;
		cin >> tempv >> tempm >> tempw;
		v.push_back(tempv);
		m.push_back(tempm);
		w.push_back(tempw);
	}
	int maxvalue = getmaxvalue(v,m,w,V,M);
	cout << maxvalue;
	system("pause");
	return 0;

}