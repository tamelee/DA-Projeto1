#ifndef GRAPH_H
#define GRAPH_H

#include "iostream"
#include "map"
#include "../data_structures/Graph.h"
using namespace std;

class Network: public Graph {
    map<int, string> index;
    Graph standard;
    Graph alfa;
private:
    void indexGraph();
public:
    void createNetwork();
};


#endif //GRAPH_H
