/*
    Author: Lydia Frame
    Date: July 25, 2025
    Description:
        Defines the GraphNode class used to build the graph. Each node stores its ID, 
        neighbors, and the fields needed for shortest path: distance and path pointer.
*/

#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <vector>

class GraphNode {
private:
    int id;
    std::vector<GraphNode*> adj;
    int dist;
    GraphNode* path;

public:
    GraphNode(int id) : id(id), dist(-1), path(nullptr) {}

    int getId() const { return id; }
    int getDist() const { return dist; }
    GraphNode* getPath() const { return path; }

    void setDist(int d) { dist = d; }
    void setPath(GraphNode* p) { path = p; }

    void addNeighbor(GraphNode* neighbor) {
        adj.push_back(neighbor);
    }

    const std::vector<GraphNode*>& getAdj() const {
        return adj;
    }
};

#endif