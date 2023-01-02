//
// Created by Guilherme Monteiro on 30/12/2022.
//
#include "Data.h"
#include "Graph.h"
//aux
//returns different airlines at an airport
set<string> Data::getDifAirlines(string airport){
    set<string> al = {};
    for (auto e : flightG->nodeAt(airport).adj){
        al.insert(e.airline);
    }
    return al;
}
//return different destinations from an airport
set<string> Data::getDifDestinations(string airport){
    set<string> al = {};
    for (auto e : flightG->nodeAt(airport).adj){
        al.insert(e.dest);
    }
    return al;
}

//globais
//doc
int Data::totalAirports(){return airports_.size();}
int Data::totalCities(){return cities_.size();}
int Data::totalCountries(){return countries_.size();}
int Data::totalAirlines(){return airlines_.size();}
int Data::totalFlights(){return nf;}

//airports
//doc
int Data::nFlights3(string airport){return flightG->nodeAt(airport).adj.size();}
int Data::nAirlines3(string airport){return getDifAirlines(airport).size();}
int Data::nDestinations3(string airport){return getDifDestinations(airport).size();}

//city
//doc
int Data::nAirports2(string city){return city2Airport(city).size();}
int Data::nFlights2(string city){
    int counter = 0;
    for(auto a: city2Airport(city)){counter += nFlights3(a);}
    return counter;
}
int Data::nAirlines2(string city){
    set<string> s = {};
    for(auto a: city2Airport(city)){
        set<string> aux = getDifAirlines(a);
        s.insert(aux.begin(),aux.end());
    }
    return s.size();
}
int Data::nDestinations2(string city){
    set<string> s = {};
    for(auto a: city2Airport(city)){
        set<string> aux = getDifDestinations(a);
        s.insert(aux.begin(),aux.end());
    }
    return s.size();
}
//country
//doc
int Data::nCities1(string country){return countries_[country]->cities_.size();}
int Data::nAirports1(string country){return country2Airport(country).size();}
int Data::nFlights1(string country){
    int counter = 0;
    for(auto a: country2Airport(country)){counter += nFlights3(a);}
    return counter;
}
int Data::nAirlines1(string country){
    set<string> s = {};
    for(auto a: country2Airport(country)){
        set<string> aux = getDifAirlines(a);
        s.insert(aux.begin(),aux.end());
    }
    return s.size();
}
int Data::nDestinations1(string country){
    set<string> s = {};
    for(auto a: country2Airport(country)){
        set<string> aux = getDifDestinations(a);
        s.insert(aux.begin(),aux.end());
    }
    return s.size();
}

//airline
int Data::nFlights4(std::string airline) { //quantos voos existem de uma determinada airline
    int counter = 0;
    //open file
    //ifstream input("../csv/flightsv2.csv");
    ifstream input(FLIGHTS);
    if(input.is_open()) {
        string line;
        getline(input, line); //skips first line
        while ( getline(input, line)) {
            if ((line.substr(8)) == airline) counter++;
        }
        return counter;
    }
    else cout<<"Could not open the file\n";
}
int Data::nDestinations4(std::string airline) { // quantos destinos diferentes tem uma determinada airline
    set<string> destinations;
    //open file
    //ifstream input("../csv/flightsv2.csv");
    ifstream input(FLIGHTS);

    if(input.is_open()) {
        string line;
        getline(input, line); //skips first line
        while ( getline(input, line)) {
            if ((line.substr(8)) == airline) {
                destinations.insert(line.substr(4,3));
            }
        }
        return destinations.size();
    }
    else cout<<"Could not open the file\n";
}

int Data::nFlightsFromAirportWithAirlines(string airport, set<string> airlines){
    int count = 0;
    for (string airline : airlines) {
        for (auto e: flightG->nodeAt(airport).adj) {
            if (e.airline == airline) count++;
        }
    }
    return count;
}

