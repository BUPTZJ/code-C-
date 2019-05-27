
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

int g_number = 0;
void Print(int ColumnIndex[], int length);
void Permutation(int ColumnIndex[], int length, int begin);

void EightQueen()
{
	const int queens = 4;
	int ColumnIndex[queens];
	for (int i = 0; i < queens; i++)
		ColumnIndex[i] = i;
	Permutation(ColumnIndex, queens, 0);

}
bool check(int ColumnIndex[], int length)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = i+1; j < length; j++)
		{
			if (i - j == ColumnIndex[i] - ColumnIndex[j] || j - i == ColumnIndex[i] - ColumnIndex[j])
				return false;
		}
	}
	return true;
}

void Permutation(int ColumnIndex[], int length, int begin)
{
	if (begin == length)
	{
		if (check(ColumnIndex, length))
		{
			++g_number;
			Print(ColumnIndex, length);
		}
	}
	else
	{
		for (int i = begin; i < length; i++)
		{
			swap(ColumnIndex[begin], ColumnIndex[i]);
			Permutation(ColumnIndex, length, begin + 1);
			swap(ColumnIndex[begin], ColumnIndex[i]);
		}
	}
}
void Print(int ColumnIndex[], int length)
{
	printf("%d\n", g_number);
	for (int i = 0; i < length; ++i)
		printf("%d ", ColumnIndex[i]);
	printf("\n");
}


int main(void)
{
	EightQueen();
	system("pause");
	return 0;
	
}
