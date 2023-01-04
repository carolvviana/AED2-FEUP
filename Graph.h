#ifndef AEDP2_GRAPH_H
#define AEDP2_GRAPH_H

#include <set>
#include <queue>
#include <list>
#include <unordered_map>
#include <limits>
#include "Airport.h"

using namespace std;

/**
 * A graph class.
 * In the context of this program this is going to represent the STCP network.
 *
 * Due to the design choices made throughout the project, this class is a mix of the theoretical classes' "abstract" graph and a context-aware graph tailored to the STCP network.
 */
class Graph {
    /**
     * An edge between 2 nodes on this graph.
     */
    struct Edge {
        string dest;
        string airline;
    };

    /**
     * A node on the graph.
     */
    struct Node {
        Airport* airport;
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited; // As the node been visited on a search?
        int distance;
        string parent;
    };

    int n;
    bool hasDir; // false: undirect; true: directed
    unordered_map<string, Node> nodes;
    vector<vector<string>> paths = {}; //caminhos para chegar ao destino

public:
    // Constructor: nr nodes and direction (default: directed)
    explicit Graph(int nodes, bool dir = true);
    ~Graph();


    /**
     * Adiciona um node a este grafo, usando o código de aeroporto como a key e o aeroporto como value.
     *
     * COMPLEXIDADE: O(1)
     *
     * @param airportCode string codigo do aeroporto a ser usado como key
     * @param airport pointer do aeroporto a ser adicionado
     */
    void addNode(const string& airportCode, Airport* airport);

    /**
     * Adiciona uma aresta conectando dois nós do grafo, a que está associado o codigo do aeroporto de origem, o codigo do aeroporto de destino e o codigo da companhia aerea de conexão dos dois.
     * @param airportCodeO string codigo do aeroporto de origem desta aresta
     * @param airportCodeD string codigo do aeroporto de destino desta aresta
     * @param airlineCode string codigo da companhia aerea associada a essa aresta de conexão
     */
    void addEdge(const string& airportCodeO, const string& airportCodeD, const string& airlineCode);
/*
    /**
     * Performs a Depth-First search on the entire graph. Uses a SSSP methodology
     *
     * Time complexity: O(|V| + |E|), with |V| being the number of nodes in the graph and |E| the collected number of edges in the graph
     *
     * @param cStop the single source from which to perform the DFS
     * @param firstIteration since this method is recursive, used to verify the first call

    void dfs(const std::string& cStop, bool firstIteration = true);*/

    /**
     * Performs a Breadth-First search on this graph. Uses a SSSP methodology.
     *
     * Time complexity: O(|V| + |E|), with |V| being the number of nodes in the graph and |E| the collected number of edges in the graph
     *
     * @param cStop the single source from which to perform the DFS
     */
    void bfs(const string& airportCode);

    /**
     * Returns the node associated to the given key.
     *
     * @param key the key of the node to retrieve.
     * @return the node associated to the given key
     */
    Node& nodeAt(const string& key);

    /**
     * Resets all the nodes to be unvisited.
     */
    void unvisit();
    void undistance();

    /**
     * Clears this graph.
     */
    void clear();
    void print();

    int distance(string origin, string dest);
    vector<string> makePath(string origin, string destination, vector<string>& airlines);
    void printPath(string origin, string destination);
    void printPath(vector<string> path);

    void bfsWithFilters(const string& airportCode, vector<string>& airlines);
    //void printShortestDistance(string src, string dest, int v);
    //bool BFS(string src, string dest, int v, unordered_map <string, vector<string>> predi, unordered_map <string, int> disti);
    //vector<string> dfs(const std::string& cStop, bool firstIteration);
    set<string> apMethodsHelper(int y);
    vector<string> dfs(const string& cAp, bool firstIteration, int& distance, vector<string>& path, vector<vector<string>>& paths, const string& destAp, int d);

};



#endif //AEDP2_GRAPH_H
