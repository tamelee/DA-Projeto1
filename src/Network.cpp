#include "Network.h"

/**
 * Creates the railway network graph.
 * @param stations vector with all stations read from the file;
 * @param segments vector with all segments read from the file;
 */
void Network::createNetwork(vector<Station> stations, const vector<Segment>& segments){
    for(auto& station: stations){
        addVertex(station.getName());
    }
    for(auto& segment: segments){
        addEdge(segment.getStationA(), segment.getStationB(), segment.getCapacity(), segment.getService());
    }
}

/**
 * Finds the maximum flow in a flow network using the Edmonds-Karp Algorithm. Time complexity: O(V * E^2).
 * @param source source node;
 * @param dest destination node;
 * @return the maximum flow between the nodes;
 */
double Network::maximum_flow(const string &source, const string &dest) {
    double max_flow = 0;

    auto* s = findVertex(source);
    auto* t = findVertex(dest);
    if (s == nullptr || t == nullptr || s == t)
        return -1;


    for (auto v : vertexSet) {
        for (auto e: v->getAdj()) {
            e->setFlow(0);
        }
    }

    while( findAugmentingPath(s, t) ) {
        double f = findMinResidualAlongPath(s, t);
        augmentFlowAlongPath(s, t, f);
        max_flow += f;
    }
    return max_flow;
}

/**
 * Edmonds-Karp Algorithm to compute the maximum flow in a flow network. Time complexity: O(V * E^2).
 * @param source source node;
 * @param dest destination node;
 */
void Network::edmondsKarp(const string &source, const string &dest) {
    Vertex* s = findVertex(source);
    Vertex* t = findVertex(dest);

    for (auto v : vertexSet) {
        for (auto e: v->getAdj()) {
            e->setFlow(0);
        }
    }
    while( findAugmentingPath(s, t) ) {
        double f = findMinResidualAlongPath(s, t);
        augmentFlowAlongPath(s, t, f);
    }
}

bool Network::findAugmentingPath(Vertex *s, Vertex *t) {
    for(auto v : vertexSet) {
        v->setVisited(false);
    }
    s->setVisited(true);
    std::queue<Vertex *> q;
    q.push(s);
    while( ! q.empty() && ! t->isVisited()) {
        auto v = q.front();
        q.pop();
        for(auto e: v->getAdj()) {
            testAndVisit(q, e, e->getDest(), e->getWeight() - e->getFlow());
        }
        for(auto e: v->getIncoming()) {
            testAndVisit(q, e, e->getOrig(), e->getFlow());
        }
    }
    return t->isVisited();
}

void Network::testAndVisit(std::queue< Vertex*> &q, Edge *e, Vertex *w, double residual) {
    if (! w->isVisited() && residual > 0) {
        w->setVisited(true);
        w->setPath(e);
        q.push(w);
    }
}

double Network::findMinResidualAlongPath(Vertex *s, Vertex *t) {
    double f = INF;
    for (auto v = t; v != s; ) {
        auto e = v->getPath();
        if (e->getDest() == v) {
            f = std::min(f, e->getWeight() - e->getFlow());
            v = e->getOrig();
        }
        else {
            f = std::min(f, e->getFlow());
            v = e->getDest();
        }
    }
    return f;
}

void Network::augmentFlowAlongPath(Vertex *s, Vertex *t, double f) {
    for (auto v = t; v != s; ) {
        auto e = v->getPath();
        double flow = e->getFlow();
        if (e->getDest() == v) {
            e->setFlow(flow + f);
            v = e->getOrig();
        }
        else {
            e->setFlow(flow - f);
            v = e->getDest();
        }
    }
}