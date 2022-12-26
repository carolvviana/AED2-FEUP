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

#define AIRLINES "../csv/airlines.csv"
#define AIRPORTS "../csv/airports.csv"
#define FLIGHTS "../csv/flights.csv"

using namespace std;

class Data{
private:

    unordered_map <string, Airline*> airlines_;
    unordered_map <string, City*> cities_;
    unordered_map <string, Airport*> airports_;
    Graph *flightG = new Graph(1);

public:

    Data();
    unordered_map <string, Airport*> getAirports();
    unordered_map <string, Airline*> getAirlines();
    unordered_map <string, City*> getCities();
    Graph* getFlightG();

    //file reading methods
    void readFile_airlines();
    void readFile_airports();
    void readFile_flights();



};



#endif //AEDP2_DATA_H
