#ifndef AEDP2_AIRPORT_H
#define AEDP2_AIRPORT_H
#include <iostream>
#include "Coordinate.h"

using namespace std;

class Airport {
private:
    string code_;
    string name_;
    string city_;
    Coordinate coordinate_;

public:
    Airport(string code, string name, string city, double lati, double longi);
    string getCode();
    string getName();
    string getCity();
    Coordinate getCoordinate();
    void setCode(string code);
    void setName(string name);
    void setCity(string city);
    void setCoordinate(double lati, double longi);

    /**
     * Mostra ao utilizador informaçao relevante sobre o aeroporto (código e nome).
     *
     * COMPLEXIDADE: O(n)
     *
     * @param os ostream que recebe o output
     * @param airport Aeroporto constante que será utilizado para dispor informação
     * @return ostream que será o output para o utilizador
     */
    friend std::ostream& operator <<(std::ostream& out ,Airport& airport);

};

#endif //AEDP2_AIRPORT_H
