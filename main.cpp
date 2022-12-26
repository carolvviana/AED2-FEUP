#include "Interface.h"
#include "Data.h"
using namespace std;
int main() {
    cout<< "hello world\n";
    Data d = Data();
    d.readFile_airlines();
    d.readFile_airports();

    d.readFile_flights();

    Graph* g = d.getFlightG();
    g->print();
    //g.~Graph();

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
