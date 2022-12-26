#ifndef AEDP2_CITY_H
#define AEDP2_CITY_H
#include <iostream>
#include "Airport.h"
#include <vector>

using namespace std;

class City {
private:
    string name_;
    string country_;
    vector<Airport> airports_ = {};
public:
    City(string name, string country);

    string getName();
    string getCountry();
    vector<Airport> getAirports();

    void setName(string name);
    void setCountry(string country);
    void addAirport(Airport ap);
};

#endif //AEDP2_CITY_H
