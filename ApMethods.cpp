//
// Created by sofia linda on 27/12/2022.
//

#include "ApMethods.h"

ApMethods:: ApMethods(){};
ApMethods:: ApMethods(Data d, Graph *g): g_(g), d_(d){};

void ApMethods::setGraph(Graph* g) { g_= g; }
void ApMethods::setData(Data d) {d_ = d;}

//Quantos voos existem a partir de um dado aeroporto?
int ApMethods::nFlightsAirport(string code/*Airport* ap*/){
    //Graph::Node& node = g_.nodeAt(code).adj.size()
    return g_->nodeAt(code).adj.size();
}

// De quantas companhias aéreas diferentes?
int ApMethods::nAirlines (string code){
    set<string> aux = {};
    for (auto e : g_->nodeAt(code).adj){
        aux.insert(e.airline);
    }
    return aux.size();
}

//Para quantos destinos diferentes?
int ApMethods::nCities (string code){
    set<string> aux = {};
    for (auto e : g_->nodeAt(code).adj){
        auto ap = this->d_.getAirports().at(e.dest); //ou usar .find(e.dest)
        aux.insert(ap->getCity());
    }
    return aux.size();
}

//De quantos países diferentes?
int ApMethods::nCountries (string code){
    set<string> aux = {};
    for (auto e : g_->nodeAt(code).adj){
        auto ap = this->d_.getAirports().at(e.dest); //ou usar .find(e.dest)
        auto c = this->d_.getCities().at(ap->getCity());
        aux.insert(c->getCountry());
    }
    return aux.size();}

//int ApMethods::nAirportsWithMaxFlights(Airport* ap, int y){} //Quantos aeroportos, cidades ou países são atingíveis usando um máximo de Y voos?

//int ApMethods::nCitiesWithMaxFlights(Airport* ap, int y){}

//int ApMethods::nCountriesWithMaxFlights(Airport *ap, int y){}

