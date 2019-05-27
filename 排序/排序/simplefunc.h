#pragma once
#include<iostream>
#include<vector>
using namespace std;
//exchange��������
template<typename T>
void exchange(T &a, T &b);

//ȡ��ȫ�������нڵ㸸�ڵ㣬�ڵ���Ű���α������
int parent(int i);
// ȡ���ӽڵ�
int leftchild(int i);
//ȡ�Һ��ӽڵ�
int rightchild(int i);

/*
����Ϊ��������صĺ���������ά�����ѣ���������
maxHeapify(A,i);
buildMaxheap(A);
*/
template <typename Comparable>
void maxHeapify(vector<Comparable>&a, int i,int end);

template<typename Comparable>
void buildMaxheap(vector<Comparable>&a);

// ȡn�������������λ��
template<typename Comparable>
int maxdigits(vector<Comparable> a, int n);

/* ����������غ�������
partition(a,l,r);
getpivot(a,left,right)*/

template <typename Comparable>
int partition(vector<Comparable>&a, int l, int r);

template <typename Comparable>
void getpivot(vector<Comparable>&a, int l, int r);


// exchange ��������
template<typename T>
void exchange(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;

}
// ���ڵ�
int parent(int i)
{
	return (i -1)/ 2;
}

// ���ӽڵ�
int leftchild(int i)
{
	return 2 * i+1;
}

//�Һ��ӽڵ�
int rightchild(int i)
{
	return 2 * i+2;
}

// ά�����Ѷ���
template<typename Comparable>
void maxHeapify(vector<Comparable>&a, int i,int end)
{
	int lc = leftchild(i);
	int rc = rightchild(i);
	int largest = i;
	if (lc < end && a[lc]>a[largest])
	{
		largest = lc;
	}
	if (rc<end && a[rc]>a[largest])
	{
		largest = rc;
	}
	if (largest!=i)
	{
		exchange(a[i], a[largest]);
		maxHeapify(a, largest,end);
	}
}

// �������Ѷ���
template<typename Comparable>
void buildMaxheap(vector<Comparable>&a)
{
	//�������ѵ��뷨Ϊ����ÿһ����Ҷ�ӽڵ㣬ִ��ά�����Ѳ���
	int i = a.size()/2-1;
	for(;i>=0;i--)
	{
		maxHeapify(a, i,a.size());
	}
}

// ����������غ�������
template <typename Comparable>
int partition(vector<Comparable>&a, int l, int r)
{
	getpivot(a, l, r);
	Comparable pivot = a[r];
	int i = l - 1;
	for (int j = l; j < r; j++)
	{
		if (a[j] <= pivot)
		{
			i = i + 1;
			exchange(a[i], a[j]); 
		}
	}
	exchange(a[i + 1], a[r]);
	return i + 1;
}

template <typename Comparable>
void getpivot(vector<Comparable>&a, int l, int r)
{
	int median = (l + r) / 2;
	if (a[median] < a[l]) { exchange(a[median],a[l]); }
	if (a[r] < a[l]) { exchange(a[l],a[r]); }
	if (a[r] < a[median]) { exchange(a[r],a[median]); }
	exchange(a[median], a[r]);
}

// ȡn�������������λ��
template<typename Comparable>
int maxdigits(vector<Comparable> a, int p)
{
	// �ȼ����vector a�����ֵ
	int maxdata = a[0];
	for(auto e:a)
	{
		if (e > maxdata)
		{
			maxdata = e;
		}
	}
	// �����ֵ��λ��
	int d = 1;
	int radix_value = p;
	while (maxdata >= radix_value)
	{
		d++;
		radix_value=radix_value*p ;
	}
	return d;
}

