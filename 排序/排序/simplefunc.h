#pragma once
#include<iostream>
#include<vector>
using namespace std;
//exchange函数声明
template<typename T>
void exchange(T &a, T &b);

//取完全二叉树中节点父节点，节点序号按层次遍历编号
int parent(int i);
// 取左孩子节点
int leftchild(int i);
//取右孩子节点
int rightchild(int i);

/*
以下为堆排序相关的函数，包括维护最大堆，建立最大堆
maxHeapify(A,i);
buildMaxheap(A);
*/
template <typename Comparable>
void maxHeapify(vector<Comparable>&a, int i,int end);

template<typename Comparable>
void buildMaxheap(vector<Comparable>&a);

// 取n进制整数的最大位数
template<typename Comparable>
int maxdigits(vector<Comparable> a, int n);

/* 快速排序相关函数，即
partition(a,l,r);
getpivot(a,left,right)*/

template <typename Comparable>
int partition(vector<Comparable>&a, int l, int r);

template <typename Comparable>
void getpivot(vector<Comparable>&a, int l, int r);


// exchange 函数定义
template<typename T>
void exchange(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;

}
// 父节点
int parent(int i)
{
	return (i -1)/ 2;
}

// 左孩子节点
int leftchild(int i)
{
	return 2 * i+1;
}

//右孩子节点
int rightchild(int i)
{
	return 2 * i+2;
}

// 维护最大堆定义
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

// 建立最大堆定义
template<typename Comparable>
void buildMaxheap(vector<Comparable>&a)
{
	//建立最大堆的想法为对于每一个非叶子节点，执行维护最大堆操作
	int i = a.size()/2-1;
	for(;i>=0;i--)
	{
		maxHeapify(a, i,a.size());
	}
}

// 快速排序相关函数定义
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

// 取n进制整数的最大位数
template<typename Comparable>
int maxdigits(vector<Comparable> a, int p)
{
	// 先计算出vector a的最大值
	int maxdata = a[0];
	for(auto e:a)
	{
		if (e > maxdata)
		{
			maxdata = e;
		}
	}
	// 求最大值的位数
	int d = 1;
	int radix_value = p;
	while (maxdata >= radix_value)
	{
		d++;
		radix_value=radix_value*p ;
	}
	return d;
}

