//
//  test_area.h
//  coding_pac
//
//  Created by Edgar Wong on 04/08/2022.
//

#ifndef test_area_h
#define test_area_h
#include "library.h"
#include <math.h>>
/*
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res(A.size());
        int l = 0, r = A.size() - 1;
        for (int k = A.size() - 1; k >= 0; k--) {
            if (abs(A[r]) > abs(A[l])) res[k] = A[r] * A[r--];
            else res[k] = A[l] * A[l++];
        }
        return res;
    }
};
*/
/*
bool canConstruct(string ransomNote, string magazine)
{
    map<char, int> mp;
    for (int i = 0; i<ransomNote.size(); i++)
    {
        mp[ransomNote[i]]++;
    }
    for(int i = 0; i<magazine.size(); i++)
    {
        if(mp[magazine[i]] == 0) return false;
        mp[magazine[i]]--;
    }
    return true;
}*/
/*
class Solution {
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> res;
        for(int i = 1; i<=n; i++)
        {
            string temp="";
            if(i%3 == 0) temp += "Fizz";
            if(i%5 == 0) temp += "Buzz";
            if(temp=="") temp += to_string(n);
            res.push_back(temp);
            
        }
        return res;
    }
};*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;
        sort (nums.begin(), nums.end());
        for (int i = 1; i <= target; i++) {
            for (auto num : nums) {
                if (i < num) break;
                dp[i] += dp[i - num];
            }
        }
        return dp.back();
    }
};

/*
 class Solution {
 public:
     
     vector<int> dp;
     
     Solution() {
         dp.resize(1001);
         fill(dp.begin(), dp.end(), -1);
     }
     
     int combinationSum4(vector<int>& nums, int target, int currSum=0) {
         if(currSum > target) return 0;
         if(currSum == target) return 1;
         if(dp[currSum] != -1) return dp[currSum];
         int ways = 0;
         for(int i=0; i<nums.size(); i++) {
             if(currSum + nums[i] <= target)
                 ways += combinationSum4(nums, target, currSum + nums[i]);
         }
         return dp[currSum] = ways;
     }
 };*/
#endif /* test_area_h */
