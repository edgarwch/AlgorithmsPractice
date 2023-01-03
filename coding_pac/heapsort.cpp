//
//  heapsort.cpp
//  coding_pac
//
//  Created by Edgar Wong on 02/01/2023.
//

#include "heapsort.hpp"

using namespace std;

void MaxHeapify(int arr[], int n, int i){
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	if(l < n && arr[l]>arr[largest]){
		largest = l;
	}
	if(r < n && arr[r] > arr[largest]){
		largest = r;
	}
	if(largest != i){
		swap(arr[i], arr[largest]);
		MaxHeapify(arr,n, largest);
	}
}

void BuildMaxHeap(int arr[], int n){
	for(int i = n/2 - 1; i>=0; i --){
		MaxHeapify(arr, n, i);
	}
}

void HeapSort(int arr[], int n)
{
	BuildMaxHeap(arr, n);
	for(int i = n - 1; i>=0; i--){
		swap(arr[0], arr[i]);
		MaxHeapify(arr, i, 0);
	}
}


void MinHeapify(int arr[], int n, int i){
	int smallest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	if(l < n && arr[l]<arr[smallest]){
		smallest = l;
	}
	if(r < n && arr[r] < arr[smallest]){
		smallest = r;
	}
	if(smallest != i){
		swap(arr[i], arr[smallest]);
		MaxHeapify(arr,n, smallest);
	}
}

void BuildMinHeap(int arr[], int n){
	for(int i = n/2 - 1; i>=0; i --){
		MaxHeapify(arr, n, i);
	}
}

void HeapSortV2(int arr[], int n)
{
	BuildMinHeap(arr, n);
	for(int i = 0; i< n ; i++)
	{
		cout<<arr[i]<<" ";
	}
	for(int i = n - 1; i>=0; i--){
		swap(arr[0], arr[i]);
		MinHeapify(arr, i, 0);
	}
}

int run(){
	int arr[] = {60,20,40,70,30,10};
	int n = sizeof(arr)/sizeof(int);
	HeapSortV2(arr, n);
	for(int i = 0; i< n ; i++)
	{
		cout<<arr[i]<<" ";
	}
	return 1;
}
