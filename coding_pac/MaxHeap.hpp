//
//  MaxHeap.hpp
//  coding_pac
//
//  Created by Edgar Wong on 02/01/2023.
//

#ifndef MaxHeap_hpp
#define MaxHeap_hpp

#include <stdio.h>
#include <iostream>

class MaxHeap
{
public:
	MaxHeap(){};
	~MaxHeap(){};
	int parent(int i ){
		return ( i - 1 )/ 2;
	}
	int leftChild(int i){
		return 2*i + 1;
	}
	int rightChild(int i){
		return 2*i + 2;
	}
	
	void MaxHeapify(int arr[], int n, int i);
	void BuildMaxHeap(int arr[], int n);
};

#endif /* MaxHeap_hpp */
