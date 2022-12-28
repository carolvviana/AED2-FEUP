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
    this->undistance();

    queue<string> q; // queue of unvisited nodes
    q.push(airportCode);
    nodes[airportCode].visited = true;
    nodes[airportCode].distance = 0;

    while (!q.empty()) { // while there are still unvisited nodes
        string u = q.front(); q.pop();

        auto node = nodes.at(u);

        //cout << *(node.airport) << '\n'; // show node order

        for (const auto& e : node.adj) {
            string airportD = e.dest;

            if (!nodes[airportD].visited) {
                q.push(airportD);
                nodes[airportD].visited = true;
                nodes[airportD].distance = nodes[u].distance+1;
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
void Graph:: undistance(){
    for (auto& node : nodes) node.second.distance = -1;
}

void Graph::clear() {
    this->nodes.clear();
}
void Graph:: print(){
    auto it = nodes.begin();
    while (it != nodes.end()){
        if ((it->second.distance) == 2){
            cout << *(it->second.airport) <<'\n';
        }
        it++;
    }
}
int Graph::distance(string origin, string dest) {
    if (origin==dest) return 0;
    bfs(origin);
    return nodes[dest].distance;
}

vector<Node> Graph::makePath(string origin, string destination) {

    vector<Node> path = {};
    /*
    if (!nodes[origin].available || !nodes[destination].available) {
        cout << "Origem/Destino nao disponivel" << endl;
        return path;
    }
     */
    /*
    switch (type) {
        case 1: BFS(origin); break;
        case 2: dijkstraMeters(origin); break;
        case 3: dijkstraLines(origin); break;
        case 4: dijkstraZones(origin); break;
    }
    */
    //if (nodes[destination].customWeight.meters == INF) return path;
    bfs(origin);
    string dest = destination;
    path.push_back(nodes[dest]);
    while (dest != origin) {
        dest = nodes[dest].parent;
        path.push_back(nodes[dest]);
    }
    return path;
}



