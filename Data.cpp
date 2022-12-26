//
// Created by carol on 13/12/2022.
//
#include "Data.h"

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
            Airline airline = Airline(code, name, callSign, countryName);
            airlines_.insert({code,airline});

        }
    } else cout << "Could not open the file\n";
}

void Data :: readFile_airports(){
    //variables
    int counter;
    double latitude, longitude;
    string code, name, city, countryName;
    vector<string> v;

    //open file
    ifstream input(AIRPORTS);
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
            City c = City(city, countryName);
            Airport airport = Airport(code, name, city, latitude, longitude);
            cities_.insert({city, c});
            c.addAirport(airport);
            airports_.insert({code, airport});
            counter++;

        }
        nAirports = counter;
    }
    else cout<<"Could not open the file\n";
}
void Data :: readFile_flights(){
    //variables
    string source_code, target_code, airline_code;
    vector<string> v;

    //open file
    ifstream input(FLIGHTS);
    if(input.is_open()) {
        string line;
        getline(input, line); //skips first line
        while ( getline(input, line)) {
            stringstream iss(line);

            //divide line in tokens;
            string token;
            while (getline(iss, token, ',')) { v.push_back(token); }

            source_code = v[0]; target_code = v[1]; airline_code = v[2];
            v.clear();

            /*
             * CRIAR AQUI OS OBJETOS
             */

        }
    }
    else cout<<"Could not open the file\n";
}

