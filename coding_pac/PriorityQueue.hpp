//
//  PriorityQueue.hpp
//  coding_pac
//
//  Created by Edgar Wong on 02/01/2023.
//

#ifndef PriorityQueue_hpp
#define PriorityQueue_hpp
#include "MaxHeap.hpp"
class PriorityQueue:MaxHeap{
	int size;
	int arr[50];
public:
	PriorityQueue();
	~PriorityQueue(){};
	int MaxHeapMaximum();
	int MaxHeapExtractMax();
	void MaxHeapIncreaseKey(int x, int k);
	void MaxHeapInsert(int x);
	void MaxHeapRemove(int x);
	void printval();
};

#endif /* PriorityQueue_hpp */
