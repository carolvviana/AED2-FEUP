
#include "Data.h"
#include "Graph.h"
//aux
//returns different airlines at an airport
    /**
     * Retorna um set de strings que são os codigos de companhias aéreas diferentes que partem do aeroporto dado.
     *
     * COMPLEXIDADE: O(n log(n))
     *
     * @param airport codigo do aeroporto que queremos contar o numero de companhias aereas
     * @return set de strings de codigos das diferentes companhias aereas nesse aeroporto
     */
set<string> Data::getDifAirlines(string airport){
    set<string> al = {};
    for (auto e : flightG->nodeAt(airport).adj){
        al.insert(e.airline);
    }
    return al;
}

//return different destinations from an airport
    /**
     * Retorna um set de strings que são os codigos dos aeroportos diferentes atingiveis pelo aeroporto dado.
     *
     * COMPLEXIDADE: O(n log(n))
     *
     * @param airport codigo do aeroporto que queremos contar o numero de companhias aereas
     * @return set de strings de codigos dos aeroportos diferentes atingiveis pelo aeroporto dado.
     */
set<string> Data::getDifDestinations(string airport){
    set<string> al = {};
    for (auto e : flightG->nodeAt(airport).adj){
        al.insert(e.dest);
    }
    return al;
}

//globais
/**
   * Retorna o numero de aeroportos presentes no grafo.
   *
   * COMPLEXIDADE: O(1)
   *
   * @return inteiro que indica o numero de aeroportos no grafo
   */
int Data::totalAirports(){return airports_.size();}

/**
   * Retorna o numero de cidades presentes no grafo.
   *
   * COMPLEXIDADE: O(1)
   *
   * @return inteiro que indica o numero de cidades presentes no grafo.
   */
int Data::totalCities(){return cities_.size();}

/**
   * Retorna o numero de paises presentes no grafo.
   *
   * COMPLEXIDADE: O(1)
   *
   * @return inteiro que indica o numero de paises presentes no grafo.
   */
int Data::totalCountries(){return countries_.size();}

/**
   * Retorna o numero de companhias aereas presentes no grafo.
   *
   * COMPLEXIDADE: O(1)
   *
   * @return inteiro que indica o numero de companhias aereas presentes no grafo.
   */
int Data::totalAirlines(){return airlines_.size();}

/**
   * Retorna o numero de voos presentes no grafo.
   *
   * COMPLEXIDADE: O(1)
   *
   * @return inteiro que indica o numero de voos presentes no grafo.
   */
int Data::totalFlights(){return nf;}

//airports
/**
   * Retorna o numero de voos presentes no aeroporto dado.
   *
   * COMPLEXIDADE: O(1)
   * @param airport codigo do aeroporto que será considerado na contagem
   * @return inteiro que indica o numero de voos presentes no aeroporto dado.
   */
int Data::nFlights3(string airport){return flightG->nodeAt(airport).adj.size();}

/**
   * Retorna o numero de companhias aereas presentes no aeroporto dado.
   *
   * COMPLEXIDADE: O(n log(n))
   * @param airport codigo do aeroporto que será considerado na contagem
   * @return inteiro que indica o numero de companhias aereas presentes no aeroporto dado.
   */
int Data::nAirlines3(string airport){return getDifAirlines(airport).size();}

/**
   * Retorna o numero de destinos (aeroportos) alcançaveis a partir do aeroporto dado.
   *
   * COMPLEXIDADE: O(n log(n))
   * @param airport codigo do aeroporto que será considerado na contagem
   * @return inteiro que indica o numero de destinos (aeroportos) alcançaveis a partir do aeroporto dado.
   */
int Data::nDestinations3(string airport){return getDifDestinations(airport).size();}

//city
/**
   * Retorna o numero de aeroportos presentes na cidade dada.
   *
   * COMPLEXIDADE: O(1)
   * @param city string nome da cidade a considerar na contagem
   * @return inteiro que indica o numero de aeroportos presentes na cidade dada.
   */
int Data::nAirports2(string city){return city2Airport(city).size();}

/**
   * Retorna o numero de voos a partir da cidade dada.
   *
   * COMPLEXIDADE: O(n)
   * @param city string nome da cidade a considerar na contagem
   * @return inteiro que indica o numero de voos a partir da cidade dada.
   */
int Data::nFlights2(string city){
    int counter = 0;
    for(auto a: city2Airport(city)){counter += nFlights3(a);}
    return counter;
}

/**
   * Retorna o numero de companhias aereas a partir da cidade dada.
   *
   * COMPLEXIDADE: O(n^2log(n))
   * @param city string nome da cidade a considerar na contagem
   * @return inteiro que indica o numero de companhias aereas a partir da cidade dada.
   */
int Data::nAirlines2(string city){
    set<string> s = {};
    for(auto a: city2Airport(city)){
        set<string> aux = getDifAirlines(a);
        s.insert(aux.begin(),aux.end());
    }
    return s.size();
}

/**
   * Retorna o numero de destinos alcancaveis(aeroportos) a partir da cidade dada.
   *
   * COMPLEXIDADE: O(n^2log(n))
   * @param city string nome da cidade a considerar na contagem
   * @return inteiro que indica o numero de destinos alcancaveis a partir da cidade dada.
   */
int Data::nDestinations2(string city){
    set<string> s = {};
    for(auto a: city2Airport(city)){
        set<string> aux = getDifDestinations(a);
        s.insert(aux.begin(),aux.end());
    }
    return s.size();
}

//country
/**
   * Retorna o numero de cidades presentes no país dado.
   *
   * COMPLEXIDADE: O(1)
   * @param country string nome do país a considerar na contagem
   * @return inteiro que indica o numero de cidades presentes no país dado.
   */
int Data::nCities1(string country){return countries_[country]->cities_.size();}

/**
   * Retorna o numero de aeroportos presentes no país dado.
   *
   * COMPLEXIDADE: O(n^2)
   * @param country string nome do país a considerar na contagem
   * @return inteiro que indica o numero de aeroportos presentes no país dado.
   */
int Data::nAirports1(string country){return country2Airport(country).size();}

/**
   * Retorna o numero de voos a partir do país dado.
   *
   * COMPLEXIDADE: O(n^2)
   * @param country string nome do país a considerar na contagem
   * @return inteiro que indica o numero de voos a partir do país dado.
   */
int Data::nFlights1(string country){
    int counter = 0;
    for(auto a: country2Airport(country)){counter += nFlights3(a);}
    return counter;
}

/**
   * Retorna o numero de companhias aereas a partir do país dado.
   *
   * COMPLEXIDADE: O(n^2log(n))
   * @param country string nome do país a considerar na contagem
   * @return inteiro que indica o numero de companhias aereas a partir do país dado.
   */
int Data::nAirlines1(string country){
    set<string> s = {};
    for(auto a: country2Airport(country)){
        set<string> aux = getDifAirlines(a);
        s.insert(aux.begin(),aux.end());
    }
    return s.size();
}

/**
   * Retorna o numero de destinos alcançaveis (aeroportos) a partir do país dado.
   *
   * COMPLEXIDADE: O(n^2log(n))
   * @param country string nome do país a considerar na contagem
   * @return inteiro que indica o numero de destinos alcançaveis (aeroportos) a partir do país dado.
   */
int Data::nDestinations1(string country){
    set<string> s = {};
    for(auto a: country2Airport(country)){
        set<string> aux = getDifDestinations(a);
        s.insert(aux.begin(),aux.end());
    }
    return s.size();
}

//airline
/**
   * Retorna o numero de voos que a companhia dada tem.
   *
   * COMPLEXIDADE: O(n^2)
   * @param airline string codigo da companhia aerea a considerar na contagem
   * @return inteiro que indica o nnumero de voos que a companhia dada tem.
   */
int Data::nFlights4(std::string airline) { //quantos voos existem de uma determinada airline
    int counter = 0;
    //open file
    //ifstream input("../csv/flightsv2.csv");
    ifstream input(FLIGHTS);
    if(input.is_open()) {
        string line;
        getline(input, line); //skips first line
        while ( getline(input, line)) {
            if ((line.substr(8)) == airline) counter++;
        }
        return counter;
    }
    else cout<<"Could not open the file\n";
}

/**
   * Retorna o numero de destinos alcançaveis (aeroportos) utilizando companhia dada.
   *
   * COMPLEXIDADE: O(n^2)
   * @param airline string codigo da companhia aerea a considerar na contagem
   * @return inteiro que indica o numero de destinos alcançaveis (aeroportos) utilizando companhia dada.
   */
int Data::nDestinations4(std::string airline) { // quantos destinos diferentes tem uma determinada airline
    set<string> destinations;
    //open file
    //ifstream input("../csv/flightsv2.csv");
    ifstream input(FLIGHTS);

    if(input.is_open()) {
        string line;
        getline(input, line); //skips first line
        while ( getline(input, line)) {
            if ((line.substr(8)) == airline) {
                destinations.insert(line.substr(4,3));
            }
        }
        return destinations.size();
    }
    else cout<<"Could not open the file\n";
}

/**
   * Retorna o numero de voos a partir de um dado aeroporto de uma ou mais companhias aéreas.
   *
   * COMPLEXIDADE: O(n^2)
   * @param airport string codigo do aeroporto a considerar na contagem
   * @param airlines set de strings de codigos de companhia(s) aerea(s) a utilizar na contagem como filtros
   * @return inteiro que indica o numero de voos a partir de um dado aeroporto de uma ou mais companhias aéreas.
   */
int Data::nFlightsFromAirportWithAirlines(string airport, set<string> airlines){
    int count = 0;
    for (string airline : airlines) {
        for (auto e: flightG->nodeAt(airport).adj) {
            if (e.airline == airline) count++;
        }
    }
    return count;
}

