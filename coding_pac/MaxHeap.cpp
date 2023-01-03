//
//  MaxHeap.cpp
//  coding_pac
//
//  Created by Edgar Wong on 02/01/2023.
//

#include "MaxHeap.hpp"

void MaxHeap::MaxHeapify(int *arr, int n, int i){
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
		std::swap(arr[i], arr[largest]);
		MaxHeapify(arr,n, largest);
	}
}

void MaxHeap::BuildMaxHeap(int *arr, int n){
	for(int i = n/2 - 1; i>=0; i --){
		MaxHeapify(arr, n, i);
	}
}
