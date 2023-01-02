//
// Created by carol on 13/12/2022.
//

#ifndef AEDP2_INTERFACE_H
#define AEDP2_INTERFACE_H

#include "Data.h"

using namespace std;
class Interface {

public:
    Data d_;

    void setData(Data d){d_ = d;}
    Interface();
    //Data getData(){return d;}
    //0
    void welcomePage();
    //1
    void getFlights();
    void credits() const;

    void exitProgram() const;
    void getStatistics();

    void globalStatistic();
    void countryStatistic();
    void cityStatistic();
    void airlineStatistic();
    void airportStatistic();
    void lastPage() const;
    vector<string> createVec();

};


#endif //AEDP2_INTERFACE_H
