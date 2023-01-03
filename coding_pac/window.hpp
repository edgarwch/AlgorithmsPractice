//
//  window.hpp
//  coding_pac
//
//  Created by Edgar Wong on 02/09/2022.
//
#include "library.h"
#ifndef window_h
#define window_h

class WindowMinSub
{
    
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int sum = 0;
        int subLength = 0;
        int result = INT32_MAX;
        int i = 0;
        for(int f = 0; f<nums.size(); f++)
        {
            sum += nums[f];
            while (sum >= target)
            {
                subLength = f - i + 1;
                result = min(subLength, result);
                sum -= nums[i++];
            }
        }
        return result == INT32_MAX? 0:result;
    }
};

class Windowsubstring
{
    map<char, int> tg, wd;
public:
    int minWinSub(string s, string t)
    {
        int start = 0;
        int Leng  = INT32_MAX;
        int l = 0;
        int valid = 0;
        for(auto c:t) tg[c]++;
        for (int r = 0; r<s.size(); r++)
        {
            wd[r]++;
            if (wd[r] == tg[r])
            {
                vaild++;
            }
            while (vaild == tg.size())
            {
                if ((r-l+1) < Leng)
                {
                    start = l;
                    Leng = r-l+1;
                }
                if (tg[s[l]] >0)
                {
                    if (wd[s[l]] == tg[s[l]])
                    {
                        vaild--;
                    }
                    wd[s[l]]--;
                }
                l++
            }
        }
        return Leng == INT32_MAX? "": s.substr(start, Leng);
    }
};



#endif /* window_h */
