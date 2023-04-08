#ifndef DA_PROJECT1_GRAPH_H
#define DA_PROJECT1_GRAPH_H


#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include "../data_structures/MutablePriorityQueue.h"

#include "VertexEdge.h"

class Graph {
public:
    ~Graph();
    /*
    * Auxiliary function to find a vertex with a given ID.
    */
    Vertex *findVertex(const int &id) const;
    Vertex *findVertex(const std::string &name) const;
    /*
     *  Adds a vertex with a given content or info (in) to a graph (this).
     *  Returns true if successful, and false if a vertex with that content already exists.
     */
    bool addVertex(const int &id);
    bool addVertex(const std::string &name);

    /*
     * Adds an edge to a graph (this), given the contents of the source and
     * destination vertices and the edge weight (w).
     * Returns true if successful, and false if the source or destination vertex does not exist.
     */
    bool addEdge(const int &sourc, const int &dest, double w);
    bool addEdge(const std::string &sourc, const std::string &dest, double w, const std::string& serv);
    bool addBidirectionalEdge(const int &sourc, const int &dest, double w);
    bool addBidirectionalEdge(const std::string &sourc, const std::string &dest, double w, const std::string& serv);

    int getNumVertex() const;
    std::vector<Vertex *> getVertexSet() const;
protected:
    std::vector<Vertex *> vertexSet;    // vertex set

    double ** distMatrix = nullptr;   // dist matrix for Floyd-Warshall
    int **pathMatrix = nullptr;   // path matrix for Floyd-Warshall

    /*
     * Finds the index of the vertex with a given content.
     */
    int findVertexIdx(const int &id) const;
    int findVertexIdx(const std::string &name) const;
};

void deleteMatrix(int **m, int n);
void deleteMatrix(double **m, int n);


#endif //DA_PROJECT1_GRAPH_H
