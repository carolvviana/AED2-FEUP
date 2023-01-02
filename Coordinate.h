//
// Created by carol on 13/12/2022.
//

#ifndef AEDP2_COORDINATE_H
#define AEDP2_COORDINATE_H

#include <ostream>

class Coordinate {
    double lati;
    double longi;
public:

    Coordinate(double lati, double longi);

    Coordinate();

    double getLati() const;
    double getLongi() const;

    double distance_between_coordinates(Coordinate cord2) const;

    friend std::ostream &operator<<(std::ostream &os, const Coordinate &coordinate);

};

#endif //AEDP2_COORDINATE_H
