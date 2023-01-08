#ifndef AEDP2_APMETHODS_H
#define AEDP2_APMETHODS_H
#include "Airport.h"
#include "Graph.h"
#include "Data.h"

using namespace std;


class ApMethods {
private:
    Data d_ ;
    Graph* g_ = new Graph(1);

public:
    ApMethods();
    ApMethods(Data d, Graph* g);
    void setGraph(Graph* g);
    void setData(Data d);

    /**
     * Indica quantos voos existem a partir de um dado aeroporto.
     *
     * COMPLEXIDADE: O(1)
     *
     * @param code string código do aeroporto
     * @return inteiro que indica o numero de voos
     */
    int nFlightsAirport(string code);

    /**
     * Indica quantas companhias aéreas existem num dado aeroporto.
     *
     * COMPLEXIDADE: O(n)
     *
     *
     * @param code string código do aeroporto
     * @return inteiro que indica o numero de companhias aereas
     */
    int nAirlines (string code);

    /**
     * Indica quantas cidades (destinos) se atingem a partir de um dado aeroporto.
     *
     * COMPLEXIDADE: O(n)
     *
     * @param code string código do aeroporto
     * @return inteiro que indica o numero de cidades (destinos) que se atingem a partir de um dado aeroporto.
     */
    int nCities (string code);

    /**
     * Indica quantos paises se atingem a partir de um dado aeroporto.
     *
     * COMPLEXIDADE: O(n)
     *
     * @param code string código do aeroporto
     * @return inteiro que indica o numero de paises que se atingem a partir de um dado aeroporto.
     */
    int nCountries (string code);

    /**
     * Indica quantos aeroportos são alcançaveis com um máximo de Y voos a partir de um dado aeroporto.
     *
     * COMPLEXIDADE: O(|V|+|E|), sendo V o numero de nodes e E o numero de arestas do grafo
     *
     * @param code string código do aeroporto
     * @param y inteiro que indica o valor maximo de voos
     * @return inteiro que indica o numero de aeroportos alcançaveis com um máximo de Y voos a partir de um dado aeroporto.
     */
    int nAirportsWithMaxFlights(string code, int y);

    /**
     * Indica quantas cidades (destinos) são alcançaveis com um máximo de Y voos a partir de um dado aeroporto.
     *
     * COMPLEXIDADE: O(|V|+|E|), sendo V o numero de nodes e E o numero de arestas do grafo
     *
     * @param code string código do aeroporto
     * @param y inteiro que indica o valor maximo de voos
     * @return inteiro que indica o numero de cidades (destinos) alcançaveis com um máximo de Y voos a partir de um dado aeroporto.
     */
    int nCitiesWithMaxFlights(string code, int y);

    /**
     * Indica quantos países são alcançaveis com um máximo de Y voos a partir de um dado aeroporto.
     *
     * COMPLEXIDADE: O(|V|+|E|), sendo V o numero de nodes e E o numero de arestas do grafo
     *
     *
     * @param code string código do aeroporto
     * @param y inteiro que indica o valor maximo de voos
     * @return inteiro que indica o numero de paises alcançaveis com um máximo de Y voos a partir de um dado aeroporto.
     */
    int nCountriesWithMaxFlights(string code, int y);

};


#endif //AEDP2_APMETHODS_H
