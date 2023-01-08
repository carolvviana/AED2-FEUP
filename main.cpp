#include "Data.h"
#include "ApMethods.h"
#include "Interface.h"

using namespace std;

int main() {
    cout<< "Hello, user! :)\n";
    Data d= Data();
    d.readFile_airlines();
    d.readFile_airports();
    d.readFile_flights();
    Graph* g = d.getFlightG();

    ApMethods apm = ApMethods();
    apm.setData(d);
    apm.setGraph(g);

    Interface iFace = Interface();
    iFace.setData(d);
    iFace.setApm(apm);

    try {
        iFace.welcomePage();
    }
    catch (int exit) {
        return 0;
    }

    return 0;

     }
