#ifndef AEDP2_DATA_H
#define AEDP2_DATA_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>


#include "Airline.h"
#include "Airport.h"
#include "City.h"
#include "Graph.h"
#include <unordered_map>
#include <map>

#define AIRLINES "../csv/airlines.csv"
#define AIRPORTS "../csv/airports.csv"
#define FLIGHTS "../csv/flights.csv"

using namespace std;

class Data{
private:
    int nf = 0;
    unordered_map <string, Airline*> airlines_ ;
    unordered_map <string, City*> cities_;
    unordered_map <string, Airport*> airports_;
    unordered_map <string, Country*> countries_;
    Graph *flightG = new Graph(1);
    vector<pair<string, Coordinate>> airportCoord_;

public:

    Data();
    unordered_map <string, Airport*> getAirports();
    unordered_map <string, Airline*> getAirlines();
    unordered_map <string, City*> getCities();
    unordered_map <string, Country*> getCountries();
    Graph* getFlightG();

    //file reading methods
    void readFile_airlines();
    void readFile_airports();
    void readFile_flights();

    vector<string> city2Airport(string city);
    vector<string> country2Airport(string country);
    string coord2Airport(string c);
    void flight(string origin, string dest, int oType, int dType);


    /*STATISTICS*/
    //global
    int totalAirports();
    int totalCities();
    int totalCountries();
    int totalAirlines();
    int totalFlights();
    //country
    int nCities1(string country);
    int nAirports1(string country);
    int nFlights1(string country);
    int nAirlines1(string country);
    int nDestinations1(string country);
    //city
    int nAirports2(string city);
    int nFlights2(string city);
    int nAirlines2(string city);
    int nDestinations2(string country);
    //airports
    int nFlights3(string airport);
    int nAirlines3(string airport);
    int nDestinations3(string airport);
    //airline

    //aux
    set<string> getDifAirlines(string airport);
    set<string> getDifDestinations(string airport);

};



#endif //AEDP2_DATA_H
