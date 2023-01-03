//
//  calender_1.h
//  coding_pac
//
//  Created by Edgar Wong on 03/08/2022.
//

#ifndef calender_1_h
#define calender_1_h
#include "library.h"
class MyCalendar {
private:
    vector<pair<int, int>>booked;
public:
    MyCalendar()
    {
    }
    bool book(int start, int end)
    {
        for (pair<int, int> temp : booked)
        {
            cout<<max(temp.first, start)<<"  ";
            cout<<min(end, temp.second)<<"  ";
            if (max(temp.first, start) < min(end, temp.second))
            {
                return false;
            }
        }
        booked.push_back({start, end});
        return true;
    }
};


class MyCalendar2
{
private:
    class tree
    {
    public:
        int start, end;
        tree *left = NULL;
        tree *right = NULL;
        tree(int start, int end)
        {
            this->start = start;
            this->end = end;
        }
    };
    tree *root;
public:
    MyCalendar2()
    {
        root = new tree(0,0);
    }
    bool book(int start, int end)
    {
        tree *tr = root;
        if(tr->start == 0 && tr->end == 0)
        {
            tr->start = start;
            tr->end = end;
            return true;
        }
        else
        {
            return insert(tr, start, end);
        }
    }
    bool insert(tree* root, int start, int end)
    {
        if(!root) return false;
        if (root->start >= end && root->start > start)
        {
            if (root->left) {
                return insert(root->left, start, end);
            }
            else{
                root->left = new tree(start,end);
                return true;
            }
        }
        if ( root->end<end &&root->end <= start)
        {
            if (root->right) {
                return insert(root->right, start, end);
            }
            else{
                root->right = new tree(start,end);
                return true;
            }
        }
        return false;
    }
};


class MyCalendar3 {
    map<int, int> mp;   // <endTime, statIme>
public:
    bool book(int start, int end) {
        auto itr = mp.upper_bound(start);
        auto a  = itr->second;
        if(itr == mp.end() || end<= itr->second) {
            mp[end]=start;
            return true;
        }
        else  return false;
    }
};
#endif /* calender_1_h */
