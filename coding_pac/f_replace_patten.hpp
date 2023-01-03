//
//  f_replace_patten.hpp
//  coding_pac
//
//  Created by Edgar Wong on 29/07/2022.
//

#ifndef f_replace_patten_hpp
#define f_replace_patten_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <map>

using namespace std;
class f_replace_patten {
public:
    vector<int> found_patten(string pt)
    {
        vector<int> v;
        int pt_i = 0;
        map<char, int> mp;
        for (int i = 0; i<pt.size() ;++i)
        {
            if (mp.find(pt[i]) == mp.end()) {
                mp.insert({pt[i], ++pt_i});
                v.push_back(mp[pt[i]]);
            }
            else
            {
                v.push_back(mp[pt[i]]);
            }
        }
        return v;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern)
    {
        vector<int> v = found_patten(pattern);
        vector<string> result;
        for (int i = 0; i<words.size(); ++i)
        {
            vector<int>p_w = found_patten(words[i]);
            if (v == p_w)
            {
                result.push_back(words[i]);
            }
        }
        return result;
    }
    
};

#endif /* f_replace_patten_hpp */
