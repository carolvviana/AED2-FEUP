//
// Created by User on 27/12/2022.
//

#ifndef AEDP2_APMETHODS_H
#define AEDP2_APMETHODS_H
#include "Airport.h"
#include "Graph.h"

using namespace std;


class ApMethods {

public:
    int nFlightsAirport(Airport* ap); //Quantos voos existem a partir de um dado aeroporto?
    int nAirlines (Airport* ap); // De quantas companhias aéreas diferentes?
    int nCities (Airport* ap); //Para quantos destinos diferentes?
    int nCountries (Airport *ap); //De quantos países diferentes?
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
