#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int *arr, int size);
void SelectionSort(int *arr, int size);
void InsertionSort(int *arr, int size);
void ShellSort(int *arr, int size);
void MergeSort(int *arr, int size);
void QuickSort(int *arr, int size);
void HeapSort(int *arr, int size);
void CountingSort(int *arr, int size);
void BucketSort(int *arr, int size);
void RedixSort(int *arr, int size);

int main(void)
{






}

void BubbleSort(int *arr, int size)
{
	for (int i=0; i<size-1; i++)
	{
		for (int j=0; j<size-i-1; j++)
		{
			if (arr[j]>arr[j+1])
			{
				tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
			}
		}
	}
}
