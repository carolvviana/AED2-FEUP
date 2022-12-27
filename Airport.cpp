#include "Airport.h"
#include "City.h"
/*
Airport :: Airport(string code, string name, City city, double lati, double longi, int index){
    code_ = code; name_ = name; city_ = city; coordinate_ = Coordinate(lati, longi); index_ = index;
}
*/
Airport :: Airport(string code, string name, string city, double lati, double longi){
    code_ = code; name_ = name; city_ = city; coordinate_ = Coordinate(lati, longi);
}
string Airport :: getCode(){ return code_;}
string Airport :: getName(){return name_;}
//City Airport :: getCity(){return city_;}
string Airport :: getCity(){return city_;}
Coordinate Airport :: getCoordinate(){return coordinate_;}
//int Airport :: getIndex(){return index_;}
void Airport :: setCode(string code){code_ = code;}
void Airport :: setName(string name){name_ = name;}
//void Airport :: setCity(City city){city_ = city;}
void Airport :: setCity(string city){city_ = city;}
void Airport :: setCoordinate(double lati, double longi){coordinate_ = Coordinate(lati, longi);}
//void Airport :: setIndex(int index){index_= index;}

std::ostream& operator <<(std::ostream& out , Airport& airport) {
    out << airport.getCode() << " | " << airport.getName();
    return out;
}