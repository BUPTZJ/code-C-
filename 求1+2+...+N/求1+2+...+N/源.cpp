#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
// ��Ŀ:��1+2+ ... +n, Ҫ����ʹ�ó˳�����for ��while��if��else��switch��case��
class Solution {
public:
	int Sum_Solution(int n) {
		int result = n;
		result && (result += Sum_Solution(n - 1));  //���ö�·���ʣ����Ϊ���ұ߾Ͳ���Ҫ����
		return result;
	}
};

int main()
{
	int n=10;
	Solution s;
	cout <<s.Sum_Solution(n);
	system("pause");
	return 0;

}