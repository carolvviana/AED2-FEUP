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


    /**
     * Calcula a distancia entre duas coordenadas.
     *
     * COMPLEXIDADE: O(1)
     *
     * @param cord2 coodenada com a qual a funçao calcula a distancia
     * @return valor double que indica a distancia entre as coordenadas
     */
    double distance_between_coordinates(Coordinate cord2) const;


    /**
     * Mostra ao utilizador informaçao relevante sobre a coordenada.
     *
     * COMPLEXIDADE: O(1)
     *
     * @param os ostream que recebe o output
     * @param coordinate Coordenada constante que será utilizada para dispor informação
     * @return ostream que será o output para o utilizador
     * */
    friend std::ostream &operator<<(std::ostream &os, const Coordinate &coordinate);

};

#endif //AEDP2_COORDINATE_H
