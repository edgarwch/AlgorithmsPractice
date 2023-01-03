//
//  delete_num.hpp
//  coding_pac
//
//  Created by Edgar Wong on 02/09/2022.
//

#ifndef delete_num_h
#define delete_num_h
#include "library.h"
class DeleteNum {
public:
    int removeElement(vector<int>& nums, int val) {
        int leftIndex = 0;
        int rightIndex = nums.size() - 1;
        while (leftIndex <= rightIndex) {
            // 找左边等于val的元素
            while (leftIndex <= rightIndex && nums[leftIndex] != val){
                ++leftIndex;
            }
            // 找右边不等于val的元素
            while (leftIndex <= rightIndex && nums[rightIndex] == val) {
                -- rightIndex;
            }
            // 将右边不等于val的元素覆盖左边等于val的元素
            if (leftIndex < rightIndex) {
                nums[leftIndex++] = nums[rightIndex--];
            }
        }
        return leftIndex;   // leftIndex一定指向了最终数组末尾的下一个元素
    }
};

class DeleteNumTwoPointer
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        int slowptr = 0;
        for(int fastptr = 0; fastptr< nums.size(); fastptr++)
        {
            if (nums[fastptr] != val)
            {
                nums[slowptr++] = nums[fastptr];
            }
        }
        return slowptr;
    }
};
#endif /* delete_num_h */
