//
// Created by peilin on 2021/8/3.
//

#ifndef ALGORITHMCPP_DENSEGRAPH_H
#define ALGORITHMCPP_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class DenseGraph{

private:
    int n,m;
    bool directed;
    vector<vector<bool>> g;

public:
    DenseGraph(int n, bool directed){
        this->n = n;
        this->m = 0;
        this->directed = directed;

        for(int i = 0 ; i<n; i++)
            g.push_back(vector<bool>(n, false));
    }
    ~DenseGraph(){

    }

    int V(){ return n;}
    int E(){ return m;}

    void addEdge(int v, int w){

        assert(v >= 0 && v<n);
        assert(w >= 0 && w<n);

        if(hasEdge(v,w))
            return;

        g[v][w] = true;
        if(!directed)
            g[w][v] = true;
        m ++;

    }

    bool hasEdge(int v, int w){
        assert(v>=0 && v<n);
        assert(w >=0 && w<n);
        return g[v][w];
    }

};


#endif //ALGORITHMCPP_DENSEGRAPH_H