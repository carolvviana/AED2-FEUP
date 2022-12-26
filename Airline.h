#ifndef AEDP2_AIRLINE_H
#define AEDP2_AIRLINE_H
#include <iostream>

using namespace std;

class Airline{

private:
    string code_;
    string name_;
    string callSign_;
    string country_;

public:
    Airline(string code, string name, string callsign, string country);

    string getCode();
    string getName();
    string getCallSign();
    string getCountry();

    void setCode(string code);
    void setName(string name);
    void setCallSign(string callsign);
    void setCountry(string country);
};

#endif //AEDP2_AIRLINE_H
