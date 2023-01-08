#include "ApMethods.h"

ApMethods:: ApMethods(){};
ApMethods:: ApMethods(Data d, Graph *g): g_(g), d_(d){};

void ApMethods::setGraph(Graph* g) { g_= g; }
void ApMethods::setData(Data d) {d_ = d;}


int ApMethods::nFlightsAirport(string code){
    return g_->nodeAt(code).adj.size();
}

int ApMethods::nAirlines (string code){
    set<string> aux = {};
    for (auto e : g_->nodeAt(code).adj){
        aux.insert(e.airline);
    }
    return aux.size();
}


int ApMethods::nCities (string code){
    set<string> aux = {};
    for (auto e : g_->nodeAt(code).adj){
        auto ap = this->d_.getAirports().at(e.dest); //ou usar .find(e.dest)
        aux.insert(ap->getCity());
    }
    return aux.size();
}


int ApMethods::nCountries (string code){
    set<string> aux = {};
    for (auto e : g_->nodeAt(code).adj){
        auto ap = this->d_.getAirports().at(e.dest); //ou usar .find(e.dest)
        auto c = this->d_.getCities().at(ap->getCity());
        aux.insert(c->getCountry());
    }
    return aux.size();}


int ApMethods::nAirportsWithMaxFlights(string code, int y){
    g_->bfs(code);
    set<string> aux = g_->apMethodsHelper(y);
    return aux.size();
}

int ApMethods::nCitiesWithMaxFlights(string code, int y){
    set<string> auxCity = {};
    g_->bfs(code);
    set<string> auxAP = g_->apMethodsHelper(y);
    for (auto ap : auxAP){
        auxCity.insert(this->d_.getAirports().at(ap)->getCity());
    }
    return auxCity.size();
}


int ApMethods::nCountriesWithMaxFlights(string code, int y){
    set<string> auxCountry = {};
    g_->bfs(code);
    set<string> auxAP = g_->apMethodsHelper(y);
    for (auto ap : auxAP){
        auxCountry.insert(this->d_.getCities().at(this->d_.getAirports().at(ap)->getCity())->getCountry());
    }
    return auxCountry.size();
}

