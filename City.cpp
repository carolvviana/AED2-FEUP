#include "City.h"


City::City(string name, string country): name_(name), country_(country){};

string City::getName() {return name_;}
string City::getCountry() {return country_;}
vector<Airport> City::getAirports() {return airports_;}

void City::setName(string name){name_ = name;}
void City::setCountry(string country) {country_ = country;}
void City::addAirport(Airport ap) {airports_.push_back(ap);}
