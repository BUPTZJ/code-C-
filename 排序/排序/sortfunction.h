#pragma once
#include<iostream>
#include"simplefunc.h"
#include<vector>
using namespace std;
//插入排序函数声明
template <typename Comparable>
void insertionSort(vector<Comparable> &a);

//选择排序函数声明
template <typename Comparable>
void selectionSort(vector<Comparable> &a);

//冒泡排序声明
template <typename Comparable>
void bubbleSort(vector<Comparable> &a);

//归并排序声明
template <typename Comparable>
void mergeSort(vector<Comparable> &a, int l, int r);

//堆排序声明（基于二叉树）
template <typename Comparable>
void heapSort(vector<Comparable> &a);

//快速排序声明
template <typename Comparable>
void quickSort(vector<Comparable> &a,int l,int r);





//插入排序定义
template <typename Comparable>
void insertionSort(vector<Comparable> &a)
{
	for (int i = 1; i < a.size(); i++)
	{
		Comparable key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;

	}

}

// 选择排序函数定义
template <typename Comparable>
void selectionSort(vector<Comparable> &a)
{
	for (int i = 0; i < a.size(); i++)
	{
		int min_index=i;
		for (int j = i + 1; j < a.size(); j++)
		{
			if(a[j]<a[min_index])
			{
				min_index=j;
			}
		}
		exchange(a[i], a[min_index]);
	}
}

// 冒泡排序定义
template <typename Comparable>
void bubbleSort(vector<Comparable> &a)
{
	for (int i = a.size()-1; i >= 0; i--)
	{
		bool flag = false;
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1]) 
			{
				exchange(a[j], a[j + 1]);
				flag = true;
			}
		}
		if (flag == false)
		{
			break;
		}
	}
}

//归并排序定义
template <typename Comparable>
void merge(vector<Comparable> &a, int l, int m, int r)
{
	int len_l = m -l+1;   //左边数组元素个数
	int len_r = r - m;   //右边数组元素个数
	vector<Comparable> temp(r - l + 1);
	int i = 0,j = 0, k = 0;
	while (i < len_l && j < len_r)
	{
		if (a[l + i] <= a[m+1+j])
		{
			temp[k] = a[l + i];
			k++;
			i++;
		}
		else
		{
			temp[ k] = a[m+1+ j];
			k++;
			j++;
		}
	}

			while(i!=len_l)
			{
				temp[ k] = a[l + i];
				k++;
				i++;
			}				
		
		
			while (j!= len_r)
			{
				temp[ k] = a[m+1+j];
				k++;
				j++;
			}
		
		for (int i = l; i <= r; i++)
			a[i] = temp[i - l];
	}
		
template <typename Comparable>
void mergeSort(vector<Comparable> &a, int l, int r)
{
	if (l < r)
	{ 
		int mid = (l + r) / 2;
		mergeSort(a, l, mid);
		mergeSort(a, mid + 1, r);
		merge(a, l, mid, r);
	}
		
}

//堆排序定义
template<typename Comparable>
void heapSort(vector<Comparable>&a)
{
	buildMaxheap(a);
	int len = a.size();
	while (len > 1)
	{
		exchange(a[0], a[len-1]);
			len--;
			maxHeapify(a, 0, len);

	}
}

//快速排序定义
template <typename Comparable>
void quickSort(vector<Comparable> &a,int l,int r)
{
	if (l<r)
	{
		int q = partition(a,l,r);
		quickSort(a, l, q - 1);
		quickSort(a, q + 1, r);
	}
}



//计数排序定义
template <typename Comparable>
void countingSort(vector<Comparable> &a, vector<Comparable> &b, int k)
{
	//申请空间作为计数数组,数组初始化为0
	vector<int> c(k, 0);
	for (int i=0;i<a.size();i++)
	{
		c[a[i]] = c[a[i]] + 1;
	}
	// 计算小于等于i的元素数目
	for (int j = 1; j < k; j++)
	{
		c[j] = c[j] + c[j - 1];
	}
	// 排序数组
	for (int i = a.size() - 1; i >= 0; i--)  //反向填充数组，保证排序稳定性
	{
		b[c[a[i]]-1] = a[i];  // C++索引是从0开始的，所以要减去1
		c[a[i]] = c[a[i]] - 1;
	}
	
}

//基数排序定义
template <typename Comparable>
void radixSort(vector<Comparable> &a, int p)
{
	int d = maxdigits(a, p);
	int k;
	int radix = 1;
	for (int i = 1; i <= d; i++)
	{
		int *tmp = new int[a.size()];
		int *c = new int[p](); //计数器
		for (int j = 0; j < a.size(); j++)
		{
			k = (a[j] /radix) % p;
			c[k]++;
		}
		for (int m = 1; m < p; m++)
		{
			c[m] = c[m] + c[m - 1];
		}
		for (int n = a.size() - 1; n>= 0; n--) 
		{
			k = (a[n] / radix) % p;
			tmp[c[k] - 1] = a[n];
			c[k]--;
		}
		for (int l = 0; l < a.size(); l++)
		{
			a[l] = tmp[l];
		}
		radix = radix * p;
		delete[] tmp;
		delete[] c;
		
	}
}


