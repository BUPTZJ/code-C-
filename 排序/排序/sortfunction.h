#pragma once
#include<iostream>
#include"simplefunc.h"
#include<vector>
using namespace std;
//��������������
template <typename Comparable>
void insertionSort(vector<Comparable> &a);

//ѡ������������
template <typename Comparable>
void selectionSort(vector<Comparable> &a);

//ð����������
template <typename Comparable>
void bubbleSort(vector<Comparable> &a);

//�鲢��������
template <typename Comparable>
void mergeSort(vector<Comparable> &a, int l, int r);

//���������������ڶ�������
template <typename Comparable>
void heapSort(vector<Comparable> &a);

//������������
template <typename Comparable>
void quickSort(vector<Comparable> &a,int l,int r);





//����������
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

// ѡ������������
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

// ð��������
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

//�鲢������
template <typename Comparable>
void merge(vector<Comparable> &a, int l, int m, int r)
{
	int len_l = m -l+1;   //�������Ԫ�ظ���
	int len_r = r - m;   //�ұ�����Ԫ�ظ���
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

//��������
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

//����������
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



//����������
template <typename Comparable>
void countingSort(vector<Comparable> &a, vector<Comparable> &b, int k)
{
	//����ռ���Ϊ��������,�����ʼ��Ϊ0
	vector<int> c(k, 0);
	for (int i=0;i<a.size();i++)
	{
		c[a[i]] = c[a[i]] + 1;
	}
	// ����С�ڵ���i��Ԫ����Ŀ
	for (int j = 1; j < k; j++)
	{
		c[j] = c[j] + c[j - 1];
	}
	// ��������
	for (int i = a.size() - 1; i >= 0; i--)  //����������飬��֤�����ȶ���
	{
		b[c[a[i]]-1] = a[i];  // C++�����Ǵ�0��ʼ�ģ�����Ҫ��ȥ1
		c[a[i]] = c[a[i]] - 1;
	}
	
}

//����������
template <typename Comparable>
void radixSort(vector<Comparable> &a, int p)
{
	int d = maxdigits(a, p);
	int k;
	int radix = 1;
	for (int i = 1; i <= d; i++)
	{
		int *tmp = new int[a.size()];
		int *c = new int[p](); //������
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


