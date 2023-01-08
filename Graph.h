#ifndef AEDP2_GRAPH_H
#define AEDP2_GRAPH_H

#include <set>
#include <queue>
#include <list>
#include <unordered_map>
#include <limits>
#include <stack>
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
        int num;
        int low;
        bool stacked;
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
     *
     * COMPLEXIDADE: O(n)
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
     * Realiza a Breadth-First search no grafo preenchido com os voos e destinos.
     *
     * COMPLEXIDADE: O(|V| + |E|),  |V| sendo o número de nós do grafo e |E| o número de arestas (edges) do grafo
     *
     * @param airportCode string código do aeroporto de partida
     */
    void bfs(const string& airportCode);

    /**
     * Retorna um nó associado a uma dada chave.
     *
     * COMPLEXIDADE: O(1)
     *
     * @param key string chave do node que retornará
     * @return o node associado à chave fornecida
     */
    Node& nodeAt(const string& key);

    /**
     * Coloca todos os nós como não visitados.
     *
     * COMPLEXIDADE: O(V) sendo V o numero de nós do grafo
     */
    void unvisit();

    /**
     * Coloca todos os nós com distancia igual a -1..
     *
     * COMPLEXIDADE: O(V) sendo V o numero de nós do grafo
     */
    void undistance();

    /**
     * Limpa o grafo.
     *
     * COMPLEXIDADE: O(V) sendo V o numero de nós do grafo
     */
    void clear();

    /**
    * Retorna a distancia entre uma origem e um destino.
    *
    * COMPLEXIDADE: O(V+E), sendo V o numero de nós do grafo e E o numero de arestas do grafo
    * @param dest string código do aeroporto de destino
    * @param origin string código do aeroporto de origem
     * @return distancia em valor inteiro entre os dois aeroportos
    */
    //int distance(string origin, string dest);

    /**
     * Retorna o vetor com o percurso mais adequado entre o aeroporto de origem e de destino
     *
     * COMPLEXIDADE: O(V+E), sendo V o numero de nós do grafo e E o numero de arestas do grafo
     */
    vector<string> makePath(string origin, string destination, vector<string>& airlines);


/**
     * Imprime o percurso entre o aeroporto de origem e de destino
     *
     * COMPLEXIDADE: O(n)
     */
    void printPath(vector<string> path);


    /**
     * Realiza a Breadth-First search no grafo preenchido com os voos e destinos, apenas com a restrição de só utilizar as compnhias aéreas escolhidas pelo utilizador.
     *
    * COMPLEXIDADE: O(V+E+N), sendo V o numero de nós do grafo e E o numero de arestas do grafo e N o numero de companhias aereas
     * @param airportCode string codigo do aeroporto de origem
     * @param airlines vector de string(s) de codigo(s) de companhias aereas a considerar na bfs
     */
    void bfsWithFilters(const string& airportCode, vector<string>& airlines); //ainda não faças disto, complexidade vai alterar
    //void printShortestDistance(string src, string dest, int v);
    //bool BFS(string src, string dest, int v, unordered_map <string, vector<string>> predi, unordered_map <string, int> disti);
    //vector<string> dfs(const std::string& cStop, bool firstIteration);

    /**
     * Retorna uma set de strings de codigos de aeroportos cuja distancia é menor ou igual do que y (e maior do que zero), em numero de voos. É uma funçao auxiliar às funções da classe ApMethods.
     *
    * COMPLEXIDADE: O(V), sendo V o numero de nós do grafo
     * @param y numero de voos a considerar na contagem
     * @return set de strings de codigos de aeroportos que se encontram a uma distancia maxima de Y voos do aeroporto de origem, definido anteriormente noutra função
     */
    set<string> apMethodsHelper(int y);

    /**
     * Realiza a Depth-First search no grafo preenchido com os voos e destinos.
     *
     * COMPLEXIDADE: O(|V| + |E|),  |V| sendo o número de nós do grafo e |E| o número de arestas (edges) do grafo
     *
     * @param cAp string codigo do aeroporto
     * @param firstIteration valor booleano que indica se é a primeira iteração ou não
     * @param distance valor inteiro
     * @param path
     * @param paths
     * @param destAp
     * @param d
     * @return
     */
    //vector<string> dfs(const string& cAp, bool firstIteration, int& distance, vector<string>& path, vector<vector<string>>& paths, const string& destAp, int d);

    /**
 * Realiza a Depth-First search no grafo preenchido com os voos e destinos, assinalando os Pontos de Articulação da Rede.
 *
 * COMPLEXIDADE: O(|V| + |E|),  |V| sendo o número de nós do grafo e |E| o número de arestas (edges) do grafo
 *
 * @param cAp string codigo do aeroporto de partida
 * @param firstIteration valor booleano que indica se é a primeira iteração ou não
 * @param artPoints pontos de articulação identificados
 * @param s stack auxiliar para o dfs
 * @param index ordem de visita dos nodes
 * @return vector de strings com os nomes dos pontos de articulação do grafo (Aeroportos)
 */
    vector<string> dfs_articulationPoints(const string& cAp, bool firstIteration, vector<string>& artPoints, stack<string>& s, int& index);

    /**
* Realiza a Depth-First search no grafo preenchido com os voos e destinos, assinalando os Pontos de Articulação da Rede considerando apenas um subconjunto de companhias.
*
* COMPLEXIDADE: O(|V| + |E|),  |V| sendo o número de nós do grafo e |E| o número de arestas (edges) do grafo
*
* @param cAp string codigo do aeroporto de partida
* @param firstIteration valor booleano que indica se é a primeira iteração ou não
* @param artPoints pontos de articulação identificados
* @param s stack auxiliar para o dfs
* @param index ordem de visita dos nodes
* @param airlines companhias selecionadas pelo utilizador
* @return vector de strings com os nomes dos pontos de articulação do grafo (Aeroportos)
*/
    vector<string> dfs_articulationPointsWithAirline(const string& cAp, bool firstIteration, vector<string>& artPoints, stack<string>& s, int& index, vector<string> airlines);

};



#endif //AEDP2_GRAPH_H
