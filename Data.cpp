//
// Created by carol on 13/12/2022.
//
#include "Data.h"
#include <algorithm>

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

unordered_map <string, Country*> Data::getCountries() {
    return countries_;
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
            countries_.insert({countryName,new Country{countryName, {}}});
            cities_[city]->addAirport(code);
            countries_[countryName]->cities_.push_back(city);
            airports_.insert({code, airport});
            airportCoord_.push_back(Coordinate(latitude, longitude));
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
    //ifstream input("../csv/flightsv2.csv");
    ifstream input(FLIGHTS);

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
            nf++;


        }
    }
    else cout<<"Could not open the file\n";
}

vector<string> Data::city2Airport(string city){
    return cities_[city]->getAirports();
}

vector<string> Data::country2Airport(string country){
    Country * c = countries_[country];
    vector<string> aps = {};
    for ( auto city: c->cities_){
        for (auto ap : city2Airport(city))
            aps.push_back(ap);
    }
    return aps;
}
struct {
    bool operator()(Coordinate c1, Coordinate c2){
        return c1.getLati() < c2.getLati();
    }
} compByLat;

struct {
    bool operator()(Coordinate c1, Coordinate c2){
        return c1.getLongi() < c2.getLongi();
    }
} compByLong;

int binarySearchLowBoundLati(vector<Coordinate>& c, const Coordinate& co){
    int low = 0, high = c.size() -1;
    while (low <= high){
        int mid = low + (high - low)/2;
        if (co.getLati() < c[mid].getLati()) low = mid;
        else if (co.getLati() > c[mid].getLati()) high = mid-1;
    }
}

int binarySearchHighBoundLati(const vector<Coordinate> &v, Coordinate key) {
    int low = 0, high = v.size();
    int res = high;
    while (low <= high) {
        int middle = low + (high - low) / 2;
        if (key.getLati() <= v[middle].getLati()) { res = middle; high = middle -1 ;}
        else if (key.getLati() > v[middle].getLati()) low = middle + 1;
        // res = middle;
    }
    if (res == v.size()) return -1; // not found
    else return res;
}
int binarySearchLowBoundLongi(vector<Coordinate>& c, const Coordinate& co){
    int low = 0, high = c.size() -1;
    while (low <= high){
        int mid = low + (high - low)/2;
        if (co.getLati() < c[mid].getLati()) low = mid;
        else if (co.getLati() > c[mid].getLati()) high = mid-1;
    }
}

int binarySearchHighBoundLongi(const vector<Coordinate> &v, Coordinate key) {
    int low = 0, high = v.size();
    int res = high;
    while (low <= high) {
        int middle = low + (high - low) / 2;
        if (key.getLati() <= v[middle].getLati()) { res = middle; high = middle -1 ;}
        else if (key.getLati() > v[middle].getLati()) low = middle + 1;
        // res = middle;
    }
    if (res == v.size()) return -1; // not found
    else return res;
}

string Data :: coord2Airport(string c){
    string v = ",";
    size_t pos = c.find(v);
    Coordinate co = Coordinate(stod(c.substr(0, pos)), stod(c.substr(pos+1)));

    sort(airportCoord_.begin(), airportCoord_.end(), compByLat);

    int positionLowBoundLati = binarySearchLowBoundLati(airportCoord_, co);
    int positionHighBoundLati = binarySearchHighBoundLati(airportCoord_, co);
    airportCoord_.erase(airportCoord_.begin(), airportCoord_.begin()+positionLowBoundLati);
    airportCoord_.erase(airportCoord_.begin()+positionHighBoundLati);

    sort(airportCoord_.begin(), airportCoord_.end(), compByLong);

    int positionLowBoundLongi = binarySearchLowBoundLongi(airportCoord_, co);
    int positionHighBoundLongi = binarySearchHighBoundLongi(airportCoord_, co);
    airportCoord_.erase(airportCoord_.begin(), airportCoord_.begin()+positionLowBoundLongi);
    airportCoord_.erase(airportCoord_.begin()+positionHighBoundLongi);

    double dist_min = airportCoord_[0].distance_between_coordinates(co);
    double dist_max = airportCoord_[1].distance_between_coordinates(co);

    Coordinate coord_min = airportCoord_[0];

    if (dist_min < dist_max){
        auto it = find_if(airports_.begin(), airports_.end(), [coord_min]() {return this.coo;});
    }

    //STD::LOWERBOUND NO MAP({coord, codigo aero})
}

//ints
void Data::flight(string origin, string dest, int oType, int dType){
    vector<string> oAp = {};
    vector<string> dAp = {};
    string o,d;
    vector<vector<string>> paths = {};
    switch (oType) { //origem
        case 1: oAp.push_back(origin); o = "Airport"; break; //aeroporto
        case 2: oAp = city2Airport(origin); o = "City"; break; //cidade
        case 3: oAp = country2Airport(origin); o = "Country"; break; // país
        case 4: break; //coordenadas
    }

    switch (dType) { //origem
        case 1: dAp.push_back(dest); break; //aeroporto
        case 2: dAp = city2Airport(dest); break; //cidade
        case 3: dAp = country2Airport(dest); break; // país
        case 4: break; //coordenadas
    }

    for (auto i = oAp.begin(); i !=  oAp.end(); i++){
        flightG->bfs(*i);
        for (auto j = dAp.begin(); j != dAp.end(); j++){
            paths.push_back(flightG->makePath(*i,*j));
        }
    }

    sort(paths.begin(), paths.end(), [](vector<string> &a, vector<string> &b){return a.size() < b.size();}); // colocar menor à frente
    int min  = paths[0].size();
    //auto aux = remove_if(paths.begin(), paths.end(), [min](vector<string> &a) {return a.size() > min;});
    auto aux = find_if(paths.begin(), paths.end(), [min](vector<string> &a) {return a.size() > min;});
    paths.erase(aux,paths.end());
    cout << "Best ways to travel from " << origin << " to " << dest << ": " << endl;

    for (auto it = paths.begin(); it != paths.end(); it++){
        cout << "- ";
        flightG->printPath(*it);
        //cout << "------" << endl;
    }



}