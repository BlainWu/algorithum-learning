#include <iostream>
#include <ctime>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"

using namespace std;

int main() {

//    int N = 20;
//    int M = 100;
//
//    srand(time(NULL));
//
//    SparseGraph g1(N,false);
//    for(int i =0; i < M; i++){
//        int a = rand()%N;
//        int b = rand()%N;
//        g1.addEdge(a ,b );
//    }
//
//    for(int v = 0; v < N; v++){
//        cout << v << " : ";
//        SparseGraph::adjIterator adj(g1, v);
//        for(int w = adj.begin(); !adj.end(); w = adj.next())
//            cout<< w<<" ";
//        cout <<endl;
//    }

    string filename = "E:\\project\\AlgorithmCPP\\testG1.txt";

    SparseGraph g1(13, false);
    ReadGraph<SparseGraph> readGraph1(g1,filename);
    g1.show();
    return 0;

}
