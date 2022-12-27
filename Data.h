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

    static unordered_map <string, Airline*> airlines_;
    static unordered_map <string, City*> cities_;
    static unordered_map <string, Airport*> airports_;
    static Graph *flightG; //= new Graph(1);

public:

    //Data();
    static unordered_map <string, Airport*> getAirports();
    static unordered_map <string, Airline*> getAirlines();
    static unordered_map <string, City*> getCities();
    static Graph* getFlightG();

    //file reading methods
    static void readFile_airlines();
    static void readFile_airports();
    static void readFile_flights();



};



#endif //AEDP2_DATA_H
