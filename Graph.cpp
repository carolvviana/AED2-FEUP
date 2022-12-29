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

//vector<Node> Graph::makePath(string origin, string destination) {

    //vector<Node> path = {};
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
/*    bfs(origin);
    string dest = destination;
    path.push_back(nodes[dest]);
    while (dest != origin) {
        dest = nodes[dest].parent;
        path.push_back(nodes[dest]);
    }
    return path;
}*/
/*
 bool Graph :: BFS(string src, string dest, int v, unordered_map <string, vector<string>> predi, unordered_map <string, int> disti)
{
    // a queue to maintain queue of vertices whose
    // adjacency list is to be scanned as per normal
    // DFS algorithm
    list<string> queue;

    // boolean array visited[] which stores the
    // information whether ith vertex is reached
    // at least once in the Breadth first search
    //bool visited[v];
    unordered_map <string, bool> visited;

    // initially all vertices are unvisited
    // so v[i] for all i is false
    // and as no path is yet constructed
    // dist[i] for all i set to infinity
    /*for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }

    for (auto p: visited){
        p.second = false;
    }
    for (auto p: disti){
        p.second = INT_MAX;
    }

    // now source is first to be visited and
    // distance from source to itself should be 0
    visited[src] = true;
    disti[src] = 0;
    queue.push_back(src);

    // standard BFS algorithm
    while (!queue.empty()) {
        string u = queue.front();
        queue.pop_front();

        auto node = nodes.at(u);

        for (const auto& e : node.adj) {
            if (!visited[e.dest]) {
                visited[e.dest] = true;
                nodes[e.dest].distance = nodes[u].distance+1;
                predi[e.dest].push_back(u);
                queue.push_back(e.dest);

                // We stop BFS when we find
                // destination.
                if (e.dest == dest)
                    return true;
            }
        }
    }
    return false;
}*/
/*
// utility function to print the shortest distance
// between source vertex and destination vertex
void Graph :: printShortestDistance(string src, string dest, int v)
{
    // predecessor[i] array stores predecessor of
    // i and distance array stores distance of i
    // from s
    unordered_map <string, vector<string>> predi;
    unordered_map <string, int> disti;

    if (BFS(src, dest, v, predi, disti) == false) {
        cout << "Given source and destination"
             << " are not connected";
        return;
    }

    // vector path stores the shortest path
    vector<string> path;
    string crawl = dest;
    path.push_back(crawl);
    int i = 0;
    while (!predi[crawl].empty()) {
        path.push_back(predi[crawl][i]);
        crawl = predi[crawl][i];
        i++;
    }
    // printing path from source to destination
    cout << "\nPath is::\n";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
}*/
vector<string> Graph::dfs(const string& cAp, bool firstIteration) {
    if (firstIteration)
        this->unvisit();

    vector<vector<string>> paths ={};
    vector<string> path =  {};

    Node& cNode = nodes[cAp];
    std::cout << *(cNode.airport) << '\n'; // show node order
    cNode.visited = true;

    for (const auto& e : cNode.adj) {
        string dAp = e.dest;
        Node& dNode = nodes[dAp];

        if (!dNode.visited)
            dfs(dAp, false);
    }
}