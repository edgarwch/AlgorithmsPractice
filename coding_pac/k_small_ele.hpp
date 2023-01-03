//
//  k_small_ele.hpp
//  coding_pac
//
//  Created by Edgar Wong on 02/08/2022.
//

#ifndef k_small_ele_hpp
#define k_small_ele_hpp

#include <stdio.h>
#include "library.h"
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        // Store value of matrix size
        int n = matrix.size();
        
        int low = matrix[0][0]; // first element
        int high = matrix[n-1][n-1]; // Last element
        
        int mid, temp, count;
        
        while(low < high){
            mid = low + (high-low)/2;
            temp = n - 1;
            count = 0;
            
            // For each row count the elements that are smaller than mid
            for(int i = 0; i < n; i++){
                
                while(temp >= 0 && matrix[i][temp] > mid){
                    temp--;
                }
                count+= (temp+1);
            }
            
            if(count < k){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        return low;
    }
};

#endif /* k_small_ele_hpp */
