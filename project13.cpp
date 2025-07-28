/*
    Author: Lydia Frame
    Date: July 25, 2025
    Description:
        Main application file. Prompts the user to input the number of nodes and their
        connectivity in a 2D matrix. Builds the graph, runs the unweighted shortest
        path algorithm, and displays the result from a selected start to end node.
*/

#include <iostream>
#include <vector>
#include "Graph.h"

int main() {
    int n;
    std::cout << "Enter number of nodes: ";
    std::cin >> n;

    std::vector<std::vector<int>> adjMatrix(n, std::vector<int>(n));

    std::cout << "Enter connectivity matrix (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            std::cin >> adjMatrix[i][j];

    Graph graph(n, adjMatrix);

    int start, end;
    std::cout << "Enter starting node: ";
    std::cin >> start;
    std::cout << "Enter ending node: ";
    std::cin >> end;

    graph.unweighted(start);
    graph.printPath(start, end);

    return 0;
}