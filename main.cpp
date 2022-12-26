#include "Interface.h"
using namespace std;
int main() {
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
}
