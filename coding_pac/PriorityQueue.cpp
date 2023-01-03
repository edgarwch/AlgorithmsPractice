//
//  PriorityQueue.cpp
//  coding_pac
//
//  Created by Edgar Wong on 02/01/2023.
//

#include "PriorityQueue.hpp"

#include <stdio.h>

PriorityQueue::PriorityQueue():
size(-1)
{
}

int PriorityQueue::MaxHeapMaximum(){
	return arr[0];
}

int PriorityQueue::MaxHeapExtractMax(){
	if(size == 0){
		return -1;
	}
	int max = MaxHeapMaximum();
	arr[0] = arr[size];
	size = size - 1;
	MaxHeapify(arr, size, 0);
	return max;
}


void PriorityQueue::MaxHeapIncreaseKey(int x, int val){
	if(val < arr[x]){
		//less
		return;
	}
	arr[x] = val;
	while(x > 0 && arr[parent(x)] < arr[x]){
		std::swap(arr[parent(x)], arr[x]);
		x = parent(x);
	}
}

void PriorityQueue::MaxHeapInsert(int val){
	size = size + 1;
	arr[size] = -1;
	MaxHeapIncreaseKey(size, val);
}

void PriorityQueue::printval(){
	for(int i = 0 ; i<= size; i++){
		std::cout<<arr[i]<<" ";
	}
}

void PriorityQueue::MaxHeapRemove(int x){
	arr[x] = MaxHeapMaximum() + 1;
	while(x > 0 && arr[parent(x)] < arr[x]){
		std::swap(arr[parent(x)], arr[x]);
		x = parent(x);
	}
	MaxHeapExtractMax();
}
