//
//  bfs.h
//  coding_pac
//  breath first search using queue(list)
//  Created by Edgar Wong on 02/09/2022.
//
#include "library.h"
#include <list>

#ifndef bfs_h
#define bfs_h

class BFS
{
    int num_v;
    list<int> *adj;
    
public:
    BFS(int V);
    void AddEdge(int Start, int Next);
    void RouteShower();
    void BFSUtils(int V, vector<bool> visited);
    void BFSVstart(int start);
};

BFS::BFS(int V)
{
    this->num_v = V;
    adj = new list<int>[V];
}

void BFS::AddEdge(int Start, int Next)
{
    adj[Start].push_back(Next);
}

void BFS::BFSUtils(int V, vector<bool> visited)
{
    list<int> q;
    q.push_back(V);
    while(!q.empty())
    {
        int current_node = q.front();
        q.pop_front();
        if(!visited[current_node])
        {
            cout<< current_node << " ";
            visited[current_node] = true;
        }
        
        for(auto i = adj[current_node].begin(); i!= adj[current_node].end(); i++)
        {
            if (!visited[*i])
            {
                q.push_back(*i);
            }
        }
    }
}

void BFS::RouteShower()
{
    vector<bool> visit(num_v, false);
    for (int i = 0; i < num_v; i++)
    {
        if (!visit[i])
        {
            BFSUtils(i, visit);
        }
    }
}

void BFS::BFSVstart(int start)
{
    vector<bool> visited(num_v, false);
    list<int> q;
    q.push_back(start);
    while (!q.empty())
    {
        int current_node = q.front();
        q.pop_front();
        if (!visited[current_node])
        {
            cout << current_node << " ";
            visited[current_node] = true;
        }
        for (auto i = adj[current_node].begin(); i!= adj[current_node].end(); i++)
        {
            if (!visited[*i])
            {
                q.push_back(*i);
            }
        }
    }
    
}
#endif /* bfs_h */
