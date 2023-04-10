#pragma once

#include "iostream"
#include "../data_structures/Graph.h"
#include "map"
#include "Station.h"
#include "Segment.h"
using namespace std;

class Network: public Graph {
protected:
    bool findAugmentingPath(Vertex *s, Vertex *t);
    double findMinResidualAlongPath(Vertex *s, Vertex *t);
    void augmentFlowAlongPath(Vertex *s, Vertex *t, double f);
    void testAndVisit(std::queue< Vertex*> &q, Edge *e, Vertex *w, double residual);
public:
    void createNetwork(vector<Station> stations, const vector<Segment>& segments);
    double maximum_flow(const string& source, const string& dest);
    void edmondsKarp(const string& source, const string& dest);
};

