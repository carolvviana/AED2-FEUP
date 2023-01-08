#include "Airport.h"
#include "City.h"

Airport :: Airport(string code, string name, string city, double lati, double longi){
    code_ = code; name_ = name; city_ = city; coordinate_ = Coordinate(lati, longi);
}
string Airport :: getCode(){ return code_;}
string Airport :: getName(){return name_;}
string Airport :: getCity(){return city_;}
Coordinate Airport :: getCoordinate(){return coordinate_;}
void Airport :: setCode(string code){code_ = code;}
void Airport :: setName(string name){name_ = name;}
void Airport :: setCity(string city){city_ = city;}
void Airport :: setCoordinate(double lati, double longi){coordinate_ = Coordinate(lati, longi);}

std::ostream& operator <<(std::ostream& out , Airport& airport) {
    out << airport.getCode() << " | " << airport.getName();
    return out;
}