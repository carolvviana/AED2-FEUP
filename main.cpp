//#include "Interface.h"
#include "Data.h"
#include "ApMethods.h"

using namespace std;

int main() {
    cout<< "hello world\n";
    Data d= Data();
    d.readFile_airlines();
    d.readFile_airports();
    d.readFile_flights();

    Graph* g = d.getFlightG();
    g->bfs("OPO");
    //cout << g->distance("CDG", "OPO") << endl;
    //g->print();
    //g->printShortestDistance("CDG", "OPO", 3019);
    //g.~Graph();

    ApMethods ap;
    ap.setData(d);
    ap.setGraph(g);
    string apc ="OPO";
    int y = 3;

    //cout << "Nr of flights: " << ap.nFlightsAirport(apc) << endl;
    //cout << "Nr of airlines: " << ap.nAirlines(apc) << endl;
    //cout << "Nr of cities: " << ap.nCities(apc) << endl;
    //cout << "Nr of countries: " << ap.nCountries(apc) << endl;

    cout << endl;
    //cout << "Nr of airport with " << y <<" flights: " << ap.nAirportsWithMaxFlights(apc,y) << endl;
    //cout << "Nr of cities with " << y <<" flights: " << ap.nCitiesWithMaxFlights(apc,y) << endl;
    //cout << "Nr of countries with " << y <<" flights: " << ap.nCountriesWithMaxFlights(apc,y) << endl;
    //cout << d.getAirports().size();

    return 0;

    /*
    Data d = Data();
    Interface iFace = Interface();
    iFace.setData(d);

    try {
        iFace.welcomePage();
    }
    catch (int exit) {
        return 0;
    }

    return 0;
    */
     }
