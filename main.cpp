//#include "Interface.h"
#include "Data.h"
#include "ApMethods.h"
#include "Interface.h"

using namespace std;

int main() {

    cout<< "hello world\n";
    Data d= Data();
    d.readFile_airlines();
    d.readFile_airports();
    d.readFile_flights();
    Graph* g = d.getFlightG();

    ApMethods apm = ApMethods();
    apm.setData(d);
    /*
    string airline = "TAP";
    cout << "Flights: " << d.nFlights2(airline) << endl;
    cout << "Destinations: " << d.nDestinations2(airline) << endl;
*//*
    auto f =  d.getCountries()["Australia"];
    for (string city : f->cities_ ){
        if(d.getCities()[city]->getAirports().size() > 1){
            cout << city << endl;
        }
    }

    auto c = d.getCities()["Albany"];*/

    Interface iFace = Interface();
    iFace.setData(d);
    iFace.setApm(apm);

    try {
        iFace.welcomePage();
    }
    catch (int exit) {
        return 0;
    }

/*
    //g->bfs("OPO");
    //cout << g->distance("CDG", "OPO") << endl;
    //g->print();
    //g->printShortestDistance("CDG", "OPO", 3019);
    //g.~Graph();
    //g->printPath("OPO", "YYZ");
    //vector<string> path  = g->makePath("OPO", "YYZ");
    //auto a = d.getCities()["Toquio"];
    //cout << d.getCities()["Toquio"]->getName();
    //cout << d.getCountries()["Portugal"]->cities_.size() << endl;
    //cout << d.getCountries()["United States"]->cities_.size() << endl;
    auto b = d.country2Airport("Portugal");
    //d.flight("49,2.5","66,-23",4, 4);
    string s = "Porto";
    cout << "Aiports: " << d.nAirports2(s) << endl;
    //cout << "Cities: " << d.nCities1(s) << endl;
    //cout << "Countries: " << d.nCountries1() << endl;
    cout << "Airlines: " << d.nAirlines2(s) << endl;
    cout << "Flights: " << d.nFlights2(s) << endl;
    cout << "Destinations: " << d.nDestinations2(s) << endl;

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
*/
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
