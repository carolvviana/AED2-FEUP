//
// Created by User on 27/12/2022.
//

#ifndef AEDP2_APMETHODS_H
#define AEDP2_APMETHODS_H
#include "Airport.h"
#include "Graph.h"
#include "Data.h"

using namespace std;


class ApMethods {
private:
    static Data d_;
    static Graph g_;

public:
    static void setGraph(Graph g);
    static void setData(Data d);
    int nFlightsAirport(string code/*Airport* ap*/); //Quantos voos existem a partir de um dado aeroporto?
    int nAirlines (string code); // De quantas companhias aéreas diferentes?
    int nCities (string code); //Para quantos destinos diferentes?
    int nCountries (string code); //De quantos países diferentes?
    int nAirportsWithMaxFlights(Airport* ap, int y);//Quantos aeroportos, cidades ou países são atingíveis usando um máximo de Y voos?
    int nCitiesWithMaxFlights(Airport* ap, int y);
    int nCountriesWithMaxFlights(Airport *ap, int y);

};

/*
 * Quantos voos existem a partir de um dado aeroporto? De quantas companhias aéreas diferentes? Para
quantos destinos diferentes? De quantos países diferentes? Quantos aeroportos, cidades ou países são
atingíveis usando um máximo de Y voos?
 */

#endif //AEDP2_APMETHODS_H
