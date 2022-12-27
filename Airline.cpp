#include "Airline.h"

Airline:: Airline(string code, string name, string callSign, string country) : code_(code), name_(name), callSign_(callSign), country_(country) {}

string Airline::getCode() {return code_;}
string Airline::getName() {return name_;}
string Airline::getCallSign() {return callSign_;}
string Airline::getCountry() {return country_;}

void Airline::setCode(string code){code_ = code;}
void Airline::setName(string name){name_ = name;}
void Airline::setCallSign(string callSign){callSign_ = callSign;}
void Airline::setCountry(string country){country_ = country;}



