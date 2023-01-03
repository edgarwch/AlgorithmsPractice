//
//  fabb.h
//  coding_pac
//
//  Created by Edgar Wong on 04/08/2022.
//

#ifndef fabb_h
#define fabb_h
#include "library.h"
class Solution {
    map<int,int> mp;
    int result;
public:
    Solution()
    {
        mp[0] = 0;
        mp[1] = 1;
        mp[2] = 1;
    }
    int tribonacci(int n)
    {
        if(mp.count(n))
        {
            return mp[n];
        }
        else
        {
            result = tribonacci(n-3);
            mp[n] = result;
        }
        return result;
    }
};

class A
{
public:
    virtual void B() {}
};

class Son: public A
{
    
};
#endif /* fabb_h */
