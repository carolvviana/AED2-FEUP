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

        //cout << *(node.airport) << '\n'; // show node order


        for (const auto& e : node.adj) {
            if(find(airlines.begin(), airlines.end(),e.airline)!= airlines.end()) { //passar para color
                string airportD = e.dest;

                if (!nodes[airportD].visited) { //o segundo switch vai ser tipo o 1o. chamamos a função flight depois dos 2 switches(e de perguntar pelo filtro)
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
/*
void Graph:: print(){
    auto it = nodes.begin();
    while (it != nodes.end()){
        if ((it->second.distance) == 2){
            cout << *(it->second.airport) <<'\n';
        }
        it++;
    }
}
 */

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
/*
void Graph::printPath(string origin, string destination){
    vector<string> path = makePath(origin, destination);
    printPath(path);
}
 */

void Graph::printPath(vector<string> path){
        for (int i = 0; i < path.size() - 1; i++) {
            cout << path[i] << " -> ";
        }
        cout << path.back() << endl;

}

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
/*
vector<string> Graph::dfs(const string& cAp, bool firstIteration, int& distance, vector<string> &path, vector<vector<string>> &paths) {
    if (firstIteration)
        this->unvisit();


    Node& cNode = nodes[cAp];
    std::cout << *(cNode.airport) << '\n'; // show node order
    cNode.visited = true;

    for (const auto& e : cNode.adj) {
        distance--;
        string dAp = e.dest;
        path.push_back(dAp);
        Node& dNode = nodes[dAp];

        if (!dNode.visited)
            dfs(dAp, false);
    }
}
*/
/*vector<string> Graph::dfs(const string& cAp, bool firstIteration, int& distance, vector<string>& path, vector<vector<string>>& paths, const string& destAp, int d) {
    if (firstIteration) { this->unvisit();}

    Node& cNode = nodes[cAp];
    std::cout << *(cNode.airport) << '\n'; // show node order
    cNode.visited = true;

    if (distance == 0){
        if (cAp == destAp){
            paths.push_back(path);
        }
        path.clear();
    }
    if (cNode.adj.empty()) distance++;
    for (const auto& e : cNode.adj) {
        distance--;
        string dAp = e.dest;
        Node& dNode = nodes[dAp];
        path.push_back(dAp);
        if (distance > 0 && !dNode.visited)
            dfs(dAp, false, distance, path, paths, destAp, d);
    }
}*/
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
void Graph:: undir(){
    hasDir = false;
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