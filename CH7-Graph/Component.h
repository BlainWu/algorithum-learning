//
// Created by peilin on 2021/8/10.
//

#ifndef ALGORITHMCPP_COMPONENT_H
#define ALGORITHMCPP_COMPONENT_H

#include <iostream>
#include <cassert>

using namespace std;

template <typename Graph>
class Component{
private:
    Graph &G;
    bool *visited;
    int ccount;

    void dfs(int v){
        visited[v] = true;

        Graph::adjIterator adj(G,v);
    }

public:
    Component(Graph &graph): G(graph){
        visited = new bool[G.V()];
        ccount = 0;
        for(int i = 0; i < G.V() ; i++)
            visited[i] = false;
        for(int i = 0; i < G.V() ; i++)
            if(!visited[i]){
                dfs(i);
                ccount ++;
            }
    }

    ~Component(){

    }
};

#endif //ALGORITHMCPP_COMPONENT_H
