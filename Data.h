#ifndef AEDP2_DATA_H
#define AEDP2_DATA_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>


#include "Airline.h"
#include "Airport.h"
#include "City.h"
#include "Graph.h"
#include <unordered_map>
#include <map>

#define AIRLINES "../csv/airlines.csv"
#define AIRPORTS "../csv/airports.csv"
#define FLIGHTS "../csv/flights.csv"

using namespace std;

class Data{
private:
    int nf = 0;
    unordered_map <string, Airline*> airlines_ ;
    unordered_map <string, City*> cities_;
    unordered_map <string, Airport*> airports_;
    unordered_map <string, Country*> countries_;
    Graph *flightG = new Graph(1);
    vector<pair<string, Coordinate>> airportCoord_;

public:

    Data();
    unordered_map <string, Airport*> getAirports();
    unordered_map <string, Airline*> getAirlines();
    unordered_map <string, City*> getCities();
    unordered_map <string, Country*> getCountries();
    Graph* getFlightG();

    /**
     * Função lê o ficheiro "airlines.csv" e cria os objetos do tipo Airline, guardando-os no unordered_map.
     *
     * Complexidade: O(n^2)
     */
    void readFile_airlines();

    /**
     * Função lê o ficheiro "airports.csv" e cria os objetos do tipo Airport, City e Country, guardando-os nos respetivos unordered_maps.
     *
     * Complexidade: O(n^2)
     */
    void readFile_airports();

    /**
     * Função lê o ficheiro "flights.csv" e cria o grafo que guarda os voos, tendo como nós os aeroportos e as edges os voos.
     *
     * Complexidade: O(n^2)
     */
    void readFile_flights();

    /**
     * Retorna um vetor com os aeroportos presentes na cidade.
     *
     * Complexidade: O(1)
     * @param city string codigo da cidade
     * @return vetor com os codigos dos aeroportos presentes na cidade
     *
     */
    vector<string> city2Airport(string city);

    /**
     * Retorna um vetor com os códigos dos aeroportos presentes no país.
     *
     * Complexidade: O(n^2)
     * @param country string nome do país
     * @return vetor com os codigos dos aeroportos presentes no país
     */
    vector<string> country2Airport(string country);

    /**
     * Retorna os código do aeroporto mais próximo da coordenada dada.
     *
     * Complexidade: O(n)
     * @param c string coordenada
     * @return codigo do aeroporto mais próximo da coordenada dada
     */
    string coord2Airport(string c);
    /**
     * Retorna um vetor com os códigos dos aeroportos a menos de x quilómetros da coordenada dada.
     *
     * Complexidade: O(n)
     * @param c string coordenada
     * @param x int raio de quilómetros
     * @return vetor com os códigos dos aeroportos a menos de x quilómetros da coordenada dada
     */
    vector<string> coord2AirportWithDistance(string c, int x);

    /**
     * Dá print aos melhores voos disponíveis entre a origem/destino dados.
     *
     * Complexidade: O(n^2(n+e))
     * @param origin string origem (aeroporto, cidade, país, coordenada)
     * @param dest string destino (aeroporto, cidade, país, coordenada)
     * @param oType int tipo de origem
     * @param dType int tipo de destino
     * @param filters vector<string> com os códigos das airlines que pretendemos usar. Vazio se não houver restrições
     * @param oRadius int quilómetros de raio
     * @param dRadius int quilómetros de raio
     */
    void flight(string origin, string dest, int oType, int dType,vector<string>& filters,  int oRadius, int dRadius);


    /*STATISTICS*/
    //global
    int totalAirports();
    int totalCities();
    int totalCountries();
    int totalAirlines();
    int totalFlights();
    //country
    int nCities1(string country);
    int nAirports1(string country);
    int nFlights1(string country);
    int nAirlines1(string country);
    int nDestinations1(string country);
    //city
    int nAirports2(string city);
    int nFlights2(string city);
    int nAirlines2(string city);
    int nDestinations2(string city);
    //airports
    int nFlights3(string airport);
    int nAirlines3(string airport);
    int nDestinations3(string airport);
    //airline
    int nFlights4(string airline);
    int nDestinations4(string airline);
    //aux
    set<string> getDifAirlines(string airport);
    set<string> getDifDestinations(string airport);

    int nFlightsFromAirportWithAirlines(string airport, set<string> airline);


    /**
 * Calcula o diametro do grafo
 *
 * Complexidade: O(n^2(|V|+|E|))
 * @return diametro do grafo
 */
    int diameter();


    /**
 * Calcula o os K aeroportos com mais voos
 *
 * Complexidade: O(nlog(n))
 * @return vetor com K aeroportos com mais voos
 */
    vector<string> topKairports(int k);
    void printArtPoints(vector<string> airlines);
};



#endif //AEDP2_DATA_H
