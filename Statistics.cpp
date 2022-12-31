//
// Created by Guilherme Monteiro on 30/12/2022.
//
#include "Data.h"
//aux
set<string> Data::getDifAirlines(string airport){
    set<string> al = {};
    for (auto e : flightG->nodeAt(airport).adj){
        al.insert(e.airline);
    }
    return al;
}
set<string> Data::getDifDestinations(string airport){
    set<string> al = {};
    for (auto e : flightG->nodeAt(airport).adj){
        al.insert(e.dest);
    }
    return al;
}

//globais
int Data::totalAirports(){return airports_.size();}
int Data::totalCities(){return cities_.size();}
int Data::totalCountries(){return countries_.size();}
int Data::totalAirlines(){return airlines_.size();}
int Data::totalFlights(){return nf;}
//airports
int Data::nFlights3(string airport){return flightG->nodeAt(airport).adj.size();}
int Data::nAirlines3(string airport){return getDifAirlines(airport).size();}
int Data::nDestinations3(string airport){return getDifDestinations(airport).size();}
//city
int Data::nAirports2(string city){return city2Airport(city).size();}
int Data::nFlights2(string city){
    int counter = 0;
    for(auto a: city2Airport(city)){counter += nFlights3(a);}
    return counter;
}
int Data::nAirlines2(string city){
    int counter = 0;
    for(auto a: city2Airport(city)){counter += nAirlines3(a);}
    return counter;
}
int Data::nDestinations2(string city){
    int counter = 0;
    for(auto a: city2Airport(city)){counter += nDestinations3(a);}
    return counter;
}
//country
int Data::nCities1(string country){return countries_[country]->cities_.size();}
int Data::nAirports1(string country){return country2Airport(country).size();}
int Data::nFlights1(string country){
    int counter = 0;
    for(auto a: country2Airport(country)){counter += nFlights3(a);}
    return counter;
}
int Data::nAirlines1(string country){
    //int counter = 0;
    //for(auto a: country2Airport(country)){counter += nAirlines3(a);}
    //return counter;
    set<string> s = {};
    for(auto a: country2Airport(country)){
        set<string> aux = getDifAirlines(a);
        s.insert(aux.begin(),aux.end());
    }
    return s.size();
}
int Data::nDestinations1(string country){
    //int counter = 0;
    //for(auto a: country2Airport(country)){counter += nDestinations3(a);}
    //return counter;
    set<string> s = {};
    for(auto a: country2Airport(country)){
        set<string> aux = getDifDestinations(a);
        s.insert(aux.begin(),aux.end());
    }
    return s.size();
}
//


