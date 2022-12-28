#include <algorithm>
#include "Graph.h"

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num) {}

Graph::~Graph() {
    for (const auto& pair : nodes)
        delete pair.second.airport;
}

void Graph::addNode(const string& airportCode, Airport* airport) {
    nodes.insert({airportCode, {airport,{},false}});
}

// Add edge from originStop to destinationStop with the distance between them as the edge weigth
void Graph::addEdge(const string& airportCodeO, const string& airportCodeD, const string& airlineCode) {
    auto ito = nodes.find(airportCodeO);
    auto itd = nodes.find(airportCodeD);

    if (ito == nodes.end() || itd == nodes.end() || ito == itd) return;

    ito->second.adj.push_back({airportCodeD, airlineCode});
    if (!this->hasDir)
        itd->second.adj.push_back({airportCodeO, airlineCode});
}
/*
// Depth-First Search: example implementation
void Graph::dfs(const std::string& cStop, bool firstIteration) {
    if (firstIteration)
        this->visitedFalse();

    Node& cNode = nodes[cStop];
    std::cout << *(cNode.stop) << '\n'; // show node order
    cNode.visited = true;

    for (const auto& e : cNode.adj) {
        std::string dStop = e.dest;
        Node& dNode = nodes[dStop];

        if (!dNode.visited)
            dfs(dStop, false);
    }
}*/

// Breadth-First Search: example implementation
void Graph::bfs(const string& airportCode) {
    this->unvisit();

    queue<string> q; // queue of unvisited nodes
    q.push(airportCode);
    nodes[airportCode].visited = true;

    while (!q.empty()) { // while there are still unvisited nodes
        string u = q.front(); q.pop();

        auto node = nodes.at(u);

        cout << *(node.airport) << '\n'; // show node order

        for (const auto& e : node.adj) {
            string airportD = e.dest;

            if (!nodes[airportD].visited) {
                q.push(airportD);
                nodes[airportD].visited = true;
            }
        }
    }
}

Graph::Node& Graph::nodeAt(const string &key) {
    return this->nodes[key];
}

void Graph::unvisit() {
    for (auto& node : nodes) node.second.visited = false;
}

void Graph::clear() {
    this->nodes.clear();
}



