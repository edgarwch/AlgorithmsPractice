//
//  roman_int.hpp
//  coding_pac
//
//  Created by Edgar Wong on 29/07/2022.
//

#ifndef roman_int_hpp
#define roman_int_hpp
/*
#include <stdio.h>
#include <string>
#include <map>
#include <iterator>
class Solution {
private:
    std::map<char, int> roman_lookup;
    int roman_int;
public:
    Solution()
    {
        roman_lookup['I'] = 1;
        roman_lookup['V'] = 5;
        roman_lookup['X'] = 10;
        roman_lookup['L'] = 50;
        roman_lookup['C'] = 100;
        roman_lookup['D'] = 500;
        roman_lookup['M'] = 1000;
        roman_int = 0;
    };
    int romanToInt(std::string s)
    {
        for(int i=0;i<s.length();i++)
        {
            if(roman_lookup[s[i]]<roman_lookup[s[i+1]])
            {
                roman_int=roman_int-roman_lookup[s[i]];
            }
            else
            {
                roman_int += roman_lookup[s[i]];
            }
        }
        return roman_int;
    }
};
*/
//faster !
#include <stdio.h>
#include <string>

class RomanToInt {
private:
    int roman_int;
public:
    int roman_lookup(char c)
    {
        switch (c)
        {
            case 'I':
                return 1;
                break;
            case 'V':
                return 5;
                break;
            case 'X':
                return 10;
                break;
            case 'L':
                return 50;
                break;
            case 'C':
                return 100;
                break;
            case 'D':
                return 500;
                break;
            case 'M':
                return 1000;
                break;
            default:
                break;
        };
        return 0;
    };
    
    RomanToInt()
    {
    };
    int romanToInt(std::string s)
    {
        roman_int=0;
        for(int i=0;i<s.length();i++)
        {
            if(roman_lookup(s[i])<roman_lookup(s[i+1]))
            {
                roman_int=roman_int-roman_lookup(s[i]);
            }
            else
            {
                roman_int += roman_lookup(s[i]);
            }
        }
        return roman_int;
    }
};

#endif /* roman_int_hpp */
