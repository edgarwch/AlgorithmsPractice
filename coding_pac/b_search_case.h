//
//  b_search_case.h
//  coding_pac
//
//  Created by Edgar Wong on 03/08/2022.
//

#ifndef b_search_case_h
#define b_search_case_h
#include "library.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int lo = 0;
        int mid = 0;
        int up = nums.size()-1;
        if(target > nums[up])
        {
            return up+1;
        }
        else if(target < nums[lo])
        {
            return lo;
        }
        while(lo < up)
        {
            mid = lo + (up - lo)/2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(target > nums[mid])
            {
                lo = mid+1;
            }
            else
            {
                up = mid - 1;
            }
        }
        return lo;
    }
};

#endif /* b_search_case_h */
