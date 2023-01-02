#include <cmath>
#include "Coordinate.h"


Coordinate::Coordinate(double lati, double longi) {
    this->lati = lati;
    this->longi  = longi;
}

Coordinate::Coordinate() {
    this->lati = 0.0;
    this->longi = 0.0;
}

double Coordinate::getLati() const {
    return lati;
}

double Coordinate::getLongi() const {
    return longi;
}

double Coordinate::distance_between_coordinates(Coordinate cord2 ) const{

    const double radius_earth = 6371000;

    double lat1 = this->lati * M_PI / 180.0;
    double lat2 = cord2.getLati() * M_PI / 180.0;

    double distLatRad = (cord2.getLati()* M_PI / 180.0 - this->lati* M_PI / 180.0) ;
    double distLonRad = (cord2.getLongi()* M_PI / 180.0 - this->longi* M_PI / 180.0) ;


    double a = pow(sin(distLatRad  / 2), 2) + pow(sin(distLonRad / 2), 2) * cos(lat1) * cos(lat2);
    double c = 2 * asin(sqrt(a));

    return c*radius_earth;
}

std::ostream &operator<<(std::ostream &os, const Coordinate &coordinate) {
    os << "lat: " << coordinate.lati << " lon: " << coordinate.longi;
    return os;
}
