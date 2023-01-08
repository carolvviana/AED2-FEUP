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

void Graph::addEdge(const string& airportCodeO, const string& airportCodeD, const string& airlineCode) {
    auto ito = nodes.find(airportCodeO);
    auto itd = nodes.find(airportCodeD);

    if (ito == nodes.end() || itd == nodes.end() || ito == itd) return;

    ito->second.adj.push_back({airportCodeD, airlineCode});
    if (!this->hasDir)
        itd->second.adj.push_back({airportCodeO, airlineCode});
}


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


        for (const auto& e : node.adj) {
            string airportD = e.dest;

            if (!nodes[airportD].visited) {
                q.push(airportD);
                nodes[airportD].visited = true;
                nodes[airportD].parent = u;
                nodes[airportD].distance = nodes[u].distance+1;
            }
        }
    }
}

void Graph::bfsWithFilters(const string& airportCode, vector<string>& airlines) {
    this->unvisit();
    this->undistance();

    queue<string> q; // queue of unvisited nodes
    q.push(airportCode);
    nodes[airportCode].visited = true;
    nodes[airportCode].distance = 0;

    while (!q.empty()) { // while there are still unvisited nodes

        string u = q.front(); q.pop();

        auto node = nodes.at(u);

        for (const auto& e : node.adj) {
            if(find(airlines.begin(), airlines.end(),e.airline)!= airlines.end()) {
                string airportD = e.dest;

                if (!nodes[airportD].visited) {
                    q.push(airportD);
                    nodes[airportD].visited = true;
                    nodes[airportD].parent = u;
                    nodes[airportD].distance = nodes[u].distance + 1;
                }
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


int Graph::distance(string origin, string dest) {
    if (origin==dest) return 0;
    bfs(origin);
    return nodes[dest].distance;
}


vector<string> Graph::makePath(string origin, string destination, vector<string>& airlines) {
    vector<string> path = {};

    if (airlines.size() == 0) bfs(origin);
    else bfsWithFilters(origin, airlines);

    string dest = destination;
    path.push_back(dest);
    while (dest != origin) {
        dest = nodes[dest].parent;
        if (dest == "") return {};
        path.push_back(dest);
    }
    reverse(path.begin(), path.end());
    return path;
}

void Graph::printPath(vector<string> path){
        for (int i = 0; i < path.size() - 1; i++) {
            cout << path[i] << " -> ";
        }
        cout << path.back() << endl;

}

void Graph::dfs_articulationPoints(Node& cNode, vector<string>& artPoints, stack<Node>& s, int& index) {
    cNode.visited = true; cNode.num = cNode.low = index; s.push(cNode); cNode.stacked = true; index++;

    int children = 0;
    bool art_point = false;

    for (auto& e : cNode.adj) {
        string dAp = e.dest;
        Node& dNode = nodes[dAp];
        if (!dNode.visited){
            children++;
            dfs_articulationPoints(dNode,artPoints, s, index);
            cNode.low = min(cNode.low, dNode.low);
            if (dNode.low >= cNode.num){
                art_point = true;
            }
        }
        else if (dNode.stacked){ cNode.low = min(cNode.low, dNode.num);}
    }
    if ((cNode.num == cNode.low && children > 1) || (cNode.num != cNode.low && art_point)){
        Node t;
        do {
            t = s.top();
            s.pop();
            cNode.stacked = false;
        } while (t.airport->getName() != cNode.airport->getName());
        artPoints.push_back(t.airport->getName());
    }
}
void Graph::dfs_articulationPointsWithAirline(const string& cAp, vector<string>& artPoints, stack<string>& s, int& index, vector<string> airlines) {
    bool art_point = false;

    Node& cNode = nodes[cAp];
    cNode.visited = true; cNode.num = index; cNode.low = index; s.push(cAp); cNode.stacked = true; index++;

    int children = 0;

    for (const auto& e : cNode.adj) {
        if (find(airlines.begin(), airlines.end(), e.airline) != airlines.end())
        {
            string dAp = e.dest;
            Node &dNode = nodes[dAp];
            if (!dNode.visited) {
                children++;
                dfs_articulationPointsWithAirline(dAp, artPoints, s, index, airlines);
                cNode.low = min(cNode.low, dNode.low);
                if (dNode.low >= cNode.num) {
                    art_point = true;
                }
            } else if (dNode.stacked) { cNode.low = min(cNode.low, dNode.num); }
        }
    }
    if ((cNode.num == cNode.low && children > 1) || (cNode.num != cNode.low && art_point)){
        artPoints.push_back(cNode.airport->getName());
    }
}

set<string> Graph:: apMethodsHelper(int y) {
    set<string> aux = {};

    for (auto a: nodes) {
        if (a.second.distance <= y && a.second.distance > 0) {
            aux.insert(a.first);
        }
    }
    return aux;
}

void Graph:: unlow(){
    for (auto& node : nodes) node.second.low = 0;
}
void Graph:: unnum(){
    for (auto& node : nodes) node.second.num = 0;
}
void Graph:: unstack(){
    for (auto& node : nodes) node.second.stacked = false;
}

void Graph :: printArtPoints(vector<string> airlines){
    if (airlines.empty()){
        vector<string> artPoints;
        stack<Node> s; int index = 1;

        unvisit();
        unlow(); unnum(); unstack();
        for (auto p: nodes){
            if (!p.second.visited){
                dfs_articulationPoints(p.second, artPoints, s, index);
            }
        }
        cout << "Number of articulation points: " << artPoints.size() << endl;
        cout << "The articulation points are: ";
        for (int i = 0; i<artPoints.size(); i++){
            cout << artPoints[i] << " | ";
        }
    }
    else{
        vector<string> artPoints;
        stack<string> s; int index = 1;

        unvisit();
        unlow(); unnum(); unstack();

        for (auto p: nodes){
            if (!p.second.visited){
                dfs_articulationPointsWithAirline(p.first, artPoints, s, index, airlines);
            }
        }
        cout << "Number of articulation points with airline filters: " << artPoints.size() << endl;
        cout << "The articulation points are: ";
        for (int i = 0; i<artPoints.size(); i++){
            cout << artPoints[i] << " | ";
        }
    }
}