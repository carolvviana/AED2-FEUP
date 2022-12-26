#include "Interface.h"
#include "Data.h"
using namespace std;
int main() {
    cout<< "hello world";
    Data d = Data();
    d.readFile_airlines();
    d.readFile_airports();

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
