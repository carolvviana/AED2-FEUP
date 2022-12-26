//
// Created by carol on 13/12/2022.
//
#include "Data.h"

void Data :: readFile_airlines(string fname) {
    //variables
    string code, name, callsign, country_name;
    vector <string> v;

    //open file
    ifstream input(fname);
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
            callsign = v[2];
            country_name = v[3];
            v.clear();


            /*
             CRIAR AQUI OS OBJETOS
             */


        }
    } else cout << "Could not open the file\n";
}

void Data :: readFile_airports(string fname){
    //variables
    double latitude, longitude;
    string code, name, city, country_name;
    vector<string> v;

    //open file
    ifstream input(fname);
    if(input.is_open()) {
        string line;
        getline(input, line); //skips first line
        while ( getline(input, line)) {
            stringstream iss(line);

            //divide line in tokens;
            string token;
            while (getline(iss, token, ',')) { v.push_back(token); }

            code = v[0]; name = v[1]; city = v[2]; country_name = v[3];
            latitude = stod(v[4]); longitude = stod(v[5]);
            v.clear();

            /*
             * CRIAR AQUI OS OBJETOS
             */

        }
    }
    else cout<<"Could not open the file\n";
}
void Data :: readFile_flights(string fname){
    //variables
    string source_code, target_code, airline_code;
    vector<string> v;

    //open file
    ifstream input(fname);
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

