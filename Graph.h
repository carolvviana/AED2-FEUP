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

class Graph {

    struct Edge {
        string dest;
        string airline;
    };

    struct Node {
        Airport* airport;
        list<Edge> adj;
        bool visited; // --> o node foi visitado ou não no grafo?
        int distance;
        string parent;
        int num;
        int low;
        bool stacked;
    };
    int n;
    bool hasDir; // false: undirect; true: directed
    unordered_map<string, Node> nodes;

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
    void unlow();
    void unnum();
    void unstack();

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
    int distance(string origin, string dest);

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
    void bfsWithFilters(const string& airportCode, vector<string>& airlines);
    /**
     * Retorna uma set de strings de codigos de aeroportos cuja distancia é menor ou igual do que y (e maior do que zero), em numero de voos. É uma funçao auxiliar às funções da classe ApMethods.
     *
    * COMPLEXIDADE: O(V), sendo V o numero de nós do grafo
     * @param y numero de voos a considerar na contagem
     * @return set de strings de codigos de aeroportos que se encontram a uma distancia maxima de Y voos do aeroporto de origem, definido anteriormente noutra função
     */
    set<string> apMethodsHelper(int y);


    /**
 * Realiza a Depth-First search no grafo preenchido com os voos e destinos, assinalando os Pontos de Articulação da Rede.
 *
 * COMPLEXIDADE: O(|V| + |E|),  |V| sendo o número de nós do grafo e |E| o número de arestas (edges) do grafo
 *
 * @param cAp Node de partida
 * @param artPoints pontos de articulação identificados
 * @param s stack auxiliar para o dfs
 * @param index ordem de visita dos nodes
 */
    void dfs_articulationPoints(Node& cAp, vector<string>& artPoints, stack<Node>& s, int& index);

    /**
* Realiza a Depth-First search no grafo preenchido com os voos e destinos, assinalando os Pontos de Articulação da Rede considerando apenas um subconjunto de companhias.
*
* COMPLEXIDADE: O(|V| + |E|),  |V| sendo o número de nós do grafo e |E| o número de arestas (edges) do grafo
*
* @param cAp string codigo do aeroporto de partida
* @param artPoints pontos de articulação identificados
* @param s stack auxiliar para o dfs
* @param index ordem de visita dos nodes
* @param airlines companhias selecionadas pelo utilizador
*/
    void dfs_articulationPointsWithAirline(const string& cAp, vector<string>& artPoints, stack<string>& s, int& index, vector<string> airlines);

    /**
* Identifica os pontos de articulação do grafo, quer com filtros de airlines, quer sem filtros.
*
* COMPLEXIDADE: O(|V|*(|V| + |E|)),  |V| sendo o número de nós do grafo e |E| o número de arestas (edges) do grafo
*
* @param airlines companhias selecionadas pelo utilizador; vetor vazio caso não haja filtros
*/
    void printArtPoints(vector<string> airlines);
};



#endif //AEDP2_GRAPH_H
