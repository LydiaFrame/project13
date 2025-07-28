/*
    Author: Lydia Frame
    Date: July 25, 2025
    Description:
        Implements the Graph class with a constructor that builds from a 2D adjacency matrix.
        Includes the unweighted shortest path algorithm and a method to display the path.
*/

#ifndef GRAPH_H
#define GRAPH_H

#include "GraphNode.h"
#include <vector>
#include <queue>
#include <iostream>

class Graph {
private:
    std::vector<GraphNode*> nodes;

public:
    Graph(int n, const std::vector<std::vector<int>>& adjMatrix) {
        for (int i = 0; i < n; ++i)
            nodes.push_back(new GraphNode(i));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (adjMatrix[i][j])
                    nodes[i]->addNeighbor(nodes[j]);
    }

    ~Graph() {
        for (auto node : nodes)
            delete node;
    }

    // Implements the unweighted shortest path algorithm (BFS)
    void unweighted(int startId) {
        for (auto node : nodes) {
            node->setDist(-1);
            node->setPath(nullptr);
        }

        GraphNode* start = nodes[startId];
        start->setDist(0);

        std::queue<GraphNode*> q;
        q.push(start);

        while (!q.empty()) {
            GraphNode* current = q.front();
            q.pop();

            for (auto neighbor : current->getAdj()) {
                if (neighbor->getDist() == -1) {
                    neighbor->setDist(current->getDist() + 1);
                    neighbor->setPath(current);
                    q.push(neighbor);
                }
            }
        }
    }

    // Prints the distance and path from start to end node
    void printPath(int startId, int endId) {
        GraphNode* end = nodes[endId];
        if (end->getDist() == -1) {
            std::cout << "No path from " << startId << " to " << endId << ".\n";
            return;
        }

        std::vector<int> path;
        for (GraphNode* node = end; node != nullptr; node = node->getPath())
            path.push_back(node->getId());

        std::cout << "Distance: " << end->getDist() << "\nPath: ";
        for (auto it = path.rbegin(); it != path.rend(); ++it)
            std::cout << *it << (it + 1 != path.rend() ? " -> " : "\n");
    }
};

#endif