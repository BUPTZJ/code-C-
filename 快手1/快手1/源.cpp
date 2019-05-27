#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;


int count(int m, int n)
{
	unordered_map<int, int> visited;
	queue<int> q;
	q.push(m);
	visited[m] = 1;
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		if (temp == n)
		{
			return  visited[n] - 1;
		}
		if (temp * 2 <= n && visited[temp * 2] == 0)
		{
			q.push(temp * 2);
			visited[temp * 2] = visited[temp] + 1;
		}
		if (temp + 1 <= n && visited[temp + 1] == 0)
		{
			q.push(temp + 1);
			visited[temp + 1] = visited[temp] + 1;
		}
		if (temp - 1 <= n && visited[temp - 1] == 0)
		{
			q.push(temp - 1);
			visited[temp - 1] = visited[temp] + 1;
		}
		
	}
}

int main()
{
	int x, y;
	cin >> x;
	cin.get();
	cin >> y;
	int result = count(x,y);
	cout << result;
	system("pause");
	return 0;

}
