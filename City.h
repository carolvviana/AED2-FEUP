#ifndef AEDP2_CITY_H
#define AEDP2_CITY_H
#include <iostream>
#include "Airport.h"
#include <vector>
#include <set>

using namespace std;
struct Country {
    string name_;
    set<string> cities_;
};

class City {
private:
    string name_;
    string country_;
    vector<string> airports_ = {};
public:
    City(string name, string country);

    string getName();
    string getCountry();
    vector<string> getAirports();

    void setName(string name);
    void setCountry(string country);


    /**
     * Adiciona um aeroporto ao vector de strings de códigos de aeroportos da classe.
     * COMPLEXIDADE: O(1)
     * @param ap string que indica o código do aeroporto a ser acrescentado
     */
    void addAirport(string ap);
};

#endif //AEDP2_CITY_H
