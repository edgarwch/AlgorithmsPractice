//
//  dfs.h
//  deep first search using stack
//  coding_pac
//
//  Created by Edgar Wong on 02/09/2022.

#include "library.h"
#include <stack>
#include <list>

#ifndef dfs_h
#define dfs_h

class DFS
{
private:
    int num_v;
    list<int> *adjs;
public:
    DFS(int V);
    void AddEdge(int start, int next);
    void ShowRoute();
    void DFSUtil(int s, vector<bool> &visited);
    void DFSVstart(int start);
};

DFS::DFS(int V)
{
    this->num_v = V;
    adjs = new list<int>[V];
}

void DFS::AddEdge(int start, int next)
{
    adjs[start].push_back(next);
}

void DFS::DFSUtil(int s, vector<bool> &visited)
{
    stack<int> sk;
    sk.push(s);
    while(!sk.empty())
    {
        int current_v = sk.top();
        sk.pop();
        if(!visited[current_v])
        {
            cout << current_v << " ";
            visited[current_v] = true;
        }
        for(auto i = adjs[current_v].begin(); i != adjs[current_v].end(); i++)
        {
            if (!visited[*i])
            {
                sk.push(*i);
            }
        }
    }
}

void DFS::ShowRoute()
{
    vector<bool> visit(num_v, false);
    for(int i = 0; i<num_v; i++)
        DFSUtil(i, visit);
}

void DFS::DFSVstart(int start)
{
    vector<bool> visited(num_v, false);
    stack<int> sk;
    sk.push(start);
    while (!sk.empty())
    {
        int current_v = sk.top();
        sk.pop();
        if(!visited[current_v])
        {
            cout << current_v << " ";
            visited[current_v] = true;
        }
        for (auto i = adj[current_v].begin(); i != adj[current_v].end(); i++)
        {
            if (!visitied[*i])
            {
                sk.push[*i];
            }
        }
    }
}
#endif /* dfs_h */
