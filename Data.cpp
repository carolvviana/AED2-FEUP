//
// Created by carol on 13/12/2022.
//
#include "Data.h"

Data::Data(){};

unordered_map <string, Airport*> Data::getAirports() {
    return airports_;
}

unordered_map<string, Airline*> Data::getAirlines(){
    return airlines_;
}

unordered_map<string, City*> Data::getCities() {
    return cities_;
}

Graph* Data::getFlightG(){
    return flightG;
}

void Data :: readFile_airlines() {

    //variables
    string code, name, callSign, countryName;
    vector <string> v;
    //open file
    ifstream input(AIRLINES);
    if (input.is_open()) {

        string line;
        getline(input, line); //skips first line
        while (getline(input, line)) {
            stringstream iss(line);

            //divide line in tokens;
            string token;
            while (getline(iss, token, ',')) { v.push_back(token); }

            //assign tokens to the correct variables
            code = v[0];
            name = v[1];
            callSign = v[2];
            countryName = v[3];
            v.clear();
            Airline *airline = new Airline(code, name, callSign, countryName);
            airlines_.insert({code,airline});

        }
    } else cout << "Could not open the file\n";
}

void Data :: readFile_airports(){
    //variables
    double latitude, longitude;
    string code, name, city, countryName;
    vector<string> v;

    //open file
    ifstream input(AIRPORTS);
    //ifstream input("../csv/airportsv2.csv");
    if(input.is_open()) {
        string line;
        getline(input, line); //skips first line
        while ( getline(input, line)) {
            stringstream iss(line);

            //divide line in tokens;
            string token;
            while (getline(iss, token, ',')) { v.push_back(token); }

            code = v[0]; name = v[1]; city = v[2]; countryName = v[3];
            latitude = stod(v[4]); longitude = stod(v[5]);
            v.clear();
            City *c =new  City(city, countryName);
            Airport *airport =new Airport(code, name, city, latitude, longitude);
            cities_.insert({city, c});
            c->addAirport(*airport);
            airports_.insert({code, airport});

        }

    }
    else cout<<"Could not open the file\n";
}
void Data :: readFile_flights() {
    //variables
    string sourceCode, targetCode, airlineCode;
    vector<string> v;
    flightG = new Graph(airports_.size());

    for (auto it = airports_.begin(); it != airports_.end(); it++){
        flightG->addNode(it->first, it->second);
    }
    //open file
    ifstream input("../csv/flightsv2.csv");
    //ifstream input(FLIGHTS);

    if(input.is_open()) {
        string line;
        getline(input, line); //skips first line
        while ( getline(input, line)) {
            stringstream iss(line);

            //divide line in tokens;
            string token;
            while (getline(iss, token, ',')) { v.push_back(token); }

            sourceCode = v[0]; targetCode = v[1]; airlineCode = v[2];
            v.clear();
            flightG->addEdge(sourceCode, targetCode, airlineCode);


        }
    }
    else cout<<"Could not open the file\n";
}