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
            v.clear(); //O(n)
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
            City *c = new City(city, countryName);
            Airport *airport =new Airport(code, name, city, latitude, longitude);
            string key = city + ',' + countryName;
            cities_.insert({key, c});
            countries_.insert({countryName,new Country{countryName, {}}});
            cities_[key]->addAirport(code);
            countries_[countryName]->cities_.insert(key);
            airports_.insert({code, airport});
            airportCoord_.push_back({code, Coordinate(latitude, longitude)});
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
    bool operator()(pair<string, Coordinate> c1, pair<string, Coordinate> c2){
        if (c1.second.getLati() < c2.second.getLati())
            return true;
        return false;
    }
} compByLat;

struct {
    bool operator()(pair<string, Coordinate> c1, pair<string, Coordinate> c2){
        return c1.second.getLongi() < c2.second.getLongi();
    }
} compByLong;

int binarySearchLowBoundLati(const vector<pair<string,Coordinate>> &v, Coordinate key){
    int res = -1;
    int low = 0, high = (int)v.size() - 1;
    while (low <= high) {
        int middle = low + (high - low) / 2;

        if (v[middle].second.getLati() > key.getLati()) {
            high = middle - 1;
        }

        else if (v[middle].second.getLati() <= key.getLati()) {
            res = middle;
            low = middle + 1;
        }
    }

    if ( res == -1) return -1; // not found
    else return res;
}
int binarySearchLowBoundLongi(const vector<pair<string,Coordinate>> &v, Coordinate key){
    int res = -1;
    int low = 0, high = (int)v.size() - 1;
    while (low <= high) {
        int middle = low + (high - low) / 2;

        if (v[middle].second.getLongi() > key.getLongi()) {
            high = middle - 1;
        }

        else if (v[middle].second.getLongi() <= key.getLongi()) {
            res = middle;
            low = middle + 1;
        }
    }

    if ( res == -1) return -1; // not found
    else return res;
}

int binarySearchHighBoundLati(const vector<pair<string,Coordinate>> &v, Coordinate key) {
    int low = 0, high = v.size();
    int res = high;
    while (low <= high) {
        int middle = low + (high - low) / 2;
        if (key.getLati() <= v[middle].second.getLati()) { res = middle; high = middle -1 ;}
        else if (key.getLati() > v[middle].second.getLati()) low = middle + 1;
        // res = middle;
    }
    if (res == v.size()) return -1; // not found
    else return res;
}
int binarySearchHighBoundLongi(const vector<pair<string,Coordinate>> &v, Coordinate key) {
    int low = 0, high = v.size();
    int res = high;
    while (low <= high) {
        int middle = low + (high - low) / 2;
        if (key.getLongi() <= v[middle].second.getLongi()) { res = middle; high = middle -1 ;}
        else if (key.getLongi() > v[middle].second.getLongi()) low = middle + 1;
        // res = middle;
    }
    if (res == v.size()) return -1; // not found
    else return res;
}
/*
string Data :: coord2Airport(string c){
    vector<pair<string, Coordinate>> airportCoord(airportCoord_);
    string v = ",";
    size_t pos = c.find(v);
    Coordinate co = Coordinate(stod(c.substr(0, pos)), stod(c.substr(pos+1)));

    sort(airportCoord.begin(), airportCoord.end(), compByLat);

    int positionLowBoundLati = binarySearchLowBoundLati(airportCoord, co);
    int positionHighBoundLati = binarySearchHighBoundLati(airportCoord, co);
    airportCoord.erase(airportCoord.begin(), airportCoord.begin()+positionLowBoundLati);
    airportCoord.erase(airportCoord.begin()+positionHighBoundLati);

    sort(airportCoord.begin(), airportCoord.end(), compByLong);

    int positionLowBoundLongi = binarySearchLowBoundLongi(airportCoord, co);
    int positionHighBoundLongi = binarySearchHighBoundLongi(airportCoord, co);
    airportCoord.erase(airportCoord.begin(), airportCoord.begin()+positionLowBoundLongi);
    airportCoord.erase(airportCoord.begin()+positionHighBoundLongi);

    double dist_min = airportCoord[0].second.distance_between_coordinates(co);
    double dist_max = airportCoord[1].second.distance_between_coordinates(co);

    if (dist_min < dist_max){
        return airportCoord[0].first;
    }
    else return airportCoord[1].first;

}*/
string Data :: coord2Airport(string c){
    string v = ",";
    size_t pos = c.find(v);
    Coordinate co = Coordinate(stod(c.substr(0, pos)), stod(c.substr(pos+1)));
    pair<string, double> min_dist_airport = {airportCoord_[0].first, co.distance_between_coordinates(airportCoord_[0].second)};

    for (auto p: airportCoord_){
        if (p.second.distance_between_coordinates(co) <= min_dist_airport.second) min_dist_airport =  {p.first, co.distance_between_coordinates(p.second)};
    }
    return min_dist_airport.first;
}

vector<string> Data :: coord2AirportWithDistance(string c, int x){
    vector<string> r;
    string v = ",";
    size_t pos = c.find(v);
    Coordinate co = Coordinate(stod(c.substr(0, pos)), stod(c.substr(pos+1)));

    for (pair<string, Coordinate> p : airportCoord_){
        if (p.second.distance_between_coordinates(co) <= x*10*10*10) r.push_back(p.first);
    }
    return r;
}

//ints
void Data::flight(string origin, string dest, int oType, int dType, vector<string>& filters , int oRadius = 0, int dRadius = 0){
    vector<string> oAp = {};
    vector<string> dAp = {};
    vector<vector<string>> paths = {};
    switch (oType) { //origem
        case 1: oAp.push_back(origin); break; //aeroporto
        case 2: oAp = city2Airport(origin); break; //cidade
        case 3: oAp = country2Airport(origin); break; // país
        case 4: oAp.push_back(coord2Airport(origin)); break; //coordenadas
        case 5: oAp = (coord2AirportWithDistance(origin,oRadius)); break;
    }

    switch (dType) { //destination
        case 1: dAp.push_back(dest); break; //aeroporto
        case 2: dAp = city2Airport(dest); break; //cidade
        case 3: dAp = country2Airport(dest); break; // país
        case 4: dAp.push_back(coord2Airport(dest)); break; //coordenadas
        case 5: dAp = (coord2AirportWithDistance(dest,dRadius)); break;
    }

    for (auto i = oAp.begin(); i !=  oAp.end(); i++) {
        //flightG->bfs(*i);
        for (auto j = dAp.begin(); j != dAp.end(); j++) {
            vector<string> a = flightG->makePath(*i, *j, filters);
            if (!a.empty()) { paths.push_back(a); }
        }
    }

    if (paths.empty()){
        cout << "There are no paths from " << origin << " to " << dest << "..." << endl;
    }

    else {
        sort(paths.begin(), paths.end(),
             [](vector<string> &a, vector<string> &b) { return a.size() < b.size(); }); // colocar menor à frente
        int min = paths[0].size();
        //auto aux = remove_if(paths.begin(), paths.end(), [min](vector<string> &a) {return a.size() > min;});
        auto aux = find_if(paths.begin(), paths.end(), [min](vector<string> &a) { return a.size() > min; });
        paths.erase(aux, paths.end());
        cout << "Best ways to travel from " << origin << " to " << dest << ": " << endl;

        for (auto it = paths.begin(); it != paths.end(); it++) {
            cout << "- ";
            flightG->printPath(*it);
        }
    }

}
int Data::diameter(){
    int max_distance = 0;
    for (auto a : airports_){
        flightG->bfs(a.first);
        for (auto b : airports_){
            if (flightG->nodeAt(b.first).distance > max_distance) max_distance = flightG->nodeAt(b.first).distance;
        }
    }
    return max_distance;
}

struct {
    bool operator()(pair<string, int> p1, pair<string, int> p2){
        return p1.second < p2.second;
    }
} compTopK;

vector<string> Data :: topKairports(int k){
    vector<string> res;
    vector<pair<string, int>> nAirports;
    for (auto p: airports_){
        nAirports.push_back({p.first, flightG->nodeAt(p.first).adj.size()});
    }
    sort(nAirports.begin(), nAirports.end(), compTopK);
    for (int i = 0; i<k; i++){
        res.push_back(nAirports[i].first);
    }
    return res;
}

void Data :: printArtPoints(vector<string> airlines){
    if (airlines.empty()){
        vector<string> artPoints;
        stack<string> s; int index = 1;
        for (auto p: airports_){
            if (!flightG->nodeAt(p.first).visited){
                flightG->dfs_articulationPoints(p.first, true, artPoints, s, index);
            }
        }
        cout << "Number of articulation points: " << artPoints.size() << endl;
        cout << "The articulation points are: ";
        for (int i = 0; i<artPoints.size(); i++){
            cout << artPoints[i] << " | ";
        }
    }
    else{
        vector<string> artPoints;
        stack<string> s; int index = 1;
        for (auto p: airports_){
            if (!flightG->nodeAt(p.first).visited){
                flightG->dfs_articulationPointsWithAirline(p.first, true, artPoints, s, index, airlines);
            }
        }
        cout << "Number of articulation points with airline filters: " << artPoints.size() << endl;
        cout << "The articulation points are: ";
        for (int i = 0; i<artPoints.size(); i++){
            cout << artPoints[i] << " | ";
        }
    }
}