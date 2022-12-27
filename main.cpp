#include "Interface.h"
#include "Data.h"
#include "ApMethods.h"

using namespace std;

int main() {
    cout<< "hello world\n";
    Data d; //= Data();
    ApMethods ap;
    ap.setData(d);


    d.readFile_airlines();
    d.readFile_airports();

    d.readFile_flights();

    Graph* g = d.getFlightG();
    cout << g->distance("CDG", "OPO") << endl;
    g->print();
    //g.~Graph();

    ap.setGraph(*g); //é isto? assin. sofia

    cout << d.getAirports().size();

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
