//
// Created by carol on 13/12/2022.
//

#ifndef AEDP2_INTERFACE_H
#define AEDP2_INTERFACE_H

#include "Data.h"
#include "ApMethods.h"

using namespace std;
class Interface {

public:
    Data d_;
    ApMethods apm_;

    void setData(Data d){d_ = d;}
    void setApm(ApMethods apm){apm_=apm;}
    Interface();
    //Data getData(){return d;}
    //0
    void welcomePage();
    //1
    void getFlights();
    void credits() const;

    void exitProgram() const;
    void getStatistics();
    void getApMethods();

    void globalStatistic();
    void countryStatistic();
    void cityStatistic();
    void airlineStatistic();
    void airportStatistic();
    void lastPage() const;
    vector<string> createVec();
    void otherInfo();

};


#endif //AEDP2_INTERFACE_H
