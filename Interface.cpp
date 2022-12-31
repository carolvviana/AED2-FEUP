//
// Created by carol on 13/12/2022.
//
#include "Interface.h"
#include <iostream>
#include <regex>

using namespace std;

Interface::Interface() = default;

/**
 * Função imprime o menu inicial que permite ao utilizador escolher entre as opções: obter voos, obter estatísticas, ver créditos ou sair do programa.
 *
 * COMPLEXIDADE: O(n).
 */
void Interface::welcomePage() {
    cout << endl << "=========WELCOME PAGE=========" << endl;
    cout << endl << "Options:\n\t1-Get flights\n\t2-Get statistics\n\t3-Credits\n\te-Exit"<<endl;
    char input;
    while (true){
        cout << "Choose option:";
        cin >> input;

        switch (input) {
            case ('1'):
                getFlights();
                return welcomePage();
            case ('2'):
                getStatistics();
            case ('3'):
                credits();
                return welcomePage();
            case ('e'):
                return exitProgram();
            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}

//1

/**
 * Função imprime o menu principal que permite ao utilizador escolher o tipo de origem e de destino dos voos e inseri-los. Também pode voltar atrás no programa.
 *
 * COMPLEXIDADE: O(n).
 */
void Interface::getFlights() {
    cout << endl << "=========GET FLIGHTS=========" << endl;
    cout << endl;
    cout << "Choose the type of origin:" << endl;
    cout << endl << "Options:\n\t1-Airport\n\t2-City\n\t3-Country\n\t4-Coordinates\n\tb-Back\n\te-Exit"<<endl;
    int flag = 1;
    char inputTypeO;
    string inputOrigin;
    while (flag){
        cout << "Choose option:";
        cin >> inputTypeO;
        switch (inputTypeO) {
            case ('1'||'2'||'3'||'4'):
                cout << endl << "Insert origin:" << endl;
                cin >> inputOrigin;
                flag = 0;
                break;

            case ('b'):
                return;

            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option" << endl;
        }
    }

    cout << endl;
    cout << "Choose the type of destination:" << endl;
    cout << endl << "Options:\n\t1-Airport\n\t2-City\n\t3-Country\n\t4-Coordinates\n\tb-Back\n\te-Exit"<<endl;

    char inputTypeD;
    string inputDestination;
    while (true){
        cout << "Choose option:";
        cin >> inputTypeD;
        switch (inputTypeD) {
            case ('1'||'2'||'3'||'4'):
                cout << endl << "Insert destination:" << endl;
                cin >> inputDestination;
                d_.flight(inputOrigin, inputDestination, inputTypeO, inputTypeD);

            case ('b'):
                return;

            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option" << endl;
        }
    }

}

/**
 * Função imprime o menu das estatísticas que permite ao utilizador escolher o tipo de estatística que quer obter ou voltar atrás no programa.
 *
 * COMPLEXIDADE: O(n).
 */
void Interface::getStatistics(){
    cout << endl << "=========GET STATISTICS=========" << endl;
    cout << endl;
    cout << "Choose the type of statistics:" << endl;
    cout << endl << "Options:\n\t1-Global\n\t2-Country\n\t3-City\n\t4-Airline\n\t5-Airport\n\tb-Back\n\te-Exit"<<endl;
    char inputType;
    string inputDestination;
    while (true){
        cout << "Choose option:";
        cin >> inputType;
        switch (inputType) {
            case ('1'):
                globalStatistic();
            case ('2'):
                countryStatistic();
            case ('3'):
                cityStatistic();
            case ('4'):
                airlineStatistic();
            case ('5'):
                airportStatistic();
            case ('b'):
                return;
            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}


/**
 * Função imprime o menu das estatísticas globais que permite ao utilizador escolher a estatística que quer obter ou voltar atrás no programa.
 *
 * COMPLEXIDADE: O(n).
 */
void Interface::globalStatistic(){
    cout << endl << "=========GLOBAL STATISTICS=========" << endl;
    cout << endl;
    cout << "Choose the statistic:" << endl;
    cout << endl << "Options:\n\t1-Total airports\n\t2-Total cities\n\t3-Total countries\n\t4-Total airlines\n\t5-Total flights\n\tb-Back\n\te-Exit"<<endl;

    char option;
    while (true){
        cout << "Choose option:";
        cin >> option;
        switch (option) {
            case ('1'):
                d_.totalAirports();
            case ('2'):
                d_.totalCities();
            case ('3'):
                d_.totalCountries();
            case ('4'):
                d_.totalAirlines();
            case ('5'):
                d_.totalFlights();
            case ('b'):
                return;
            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}


/**
 * Função imprime o menu das estatísticas a nível de país que permite ao utilizador escolher a estatística que quer obter ou voltar atrás no programa.
 *
 * COMPLEXIDADE: O(n).
 */
void Interface::countryStatistic(){
    cout << endl << "=========COUNTRY STATISTICS=========" << endl;
    cout << endl;
    cout << "Choose the statistic:" << endl;
    cout << endl << "Options:\n\t1-Total airports\n\t2-Total cities\n\t3-Total countries\n\t4-Total airlines\n\t5-Total flights\n\tb-Back\n\te-Exit"<<endl;

    char option;
    while (true){
        cout << "Choose option:";
        cin >> option;
        switch (option) {
            case ('1'):
                d_.totalAirports();
            case ('2'):
                d_.totalCities();
            case ('3'):
                d_.totalCountries();
            case ('4'):
                d_.totalAirlines();
            case ('5'):
                d_.totalFlights();
            case ('b'):
                return;
            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}


/**
 * Função imprime o menu das estatísticas a nível de cidade que permite ao utilizador escolher a estatística que quer obter ou voltar atrás no programa.
 *
 * COMPLEXIDADE: O(n).
 */
void Interface::cityStatistic(){
    cout << endl << "=========CITY STATISTICS=========" << endl;
    cout << endl;
    cout << "Choose the statistic:" << endl;
    cout << endl << "Options:\n\t1-Total airports\n\t2-Total countries\n\t3-Total airlines\n\t4-Total flights\n\tb-Back\n\te-Exit"<<endl;

    char option;
    while (true){
        cout << "Choose option:";
        cin >> option;
        switch (option) {
            case ('1'):
                d_.totalAirports();
            case ('2'):
                d_.totalCountries();
            case ('3'):
                d_.totalAirlines();
            case ('4'):
                d_.totalFlights();
            case ('b'):
                return;
            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}


/**
 * Função imprime o menu das estatísticas a nível de companhia aérea que permite ao utilizador escolher a estatística que quer obter ou voltar atrás no programa.
 *
 * COMPLEXIDADE: O(n).
 */
void Interface::airlineStatistic(){
    cout << endl << "=========AIRLINE STATISTICS=========" << endl;
    cout << endl;
    cout << "Choose the statistic:" << endl;
    cout << endl << "Options:\n\t1-Total airports\n\t2-Total cities\n\t3-Total countries\n\t4-Total airlines\n\t5-Total flights\n\tb-Back\n\te-Exit"<<endl;

    char option;
    while (true){
        cout << "Choose option:";
        cin >> option;
        switch (option) {
            case ('1'):
                d_.totalAirports();
            case ('2'):
                d_.totalCities();
            case ('3'):
                d_.totalCountries();
            case ('4'):
                d_.totalAirlines();
            case ('5'):
                d_.totalFlights();
            case ('b'):
                return;
            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}


/**
 * Função imprime o menu das estatísticas a nível de Aeroporto que permite ao utilizador escolher a estatística que quer obter ou voltar atrás no programa.
 *
 * COMPLEXIDADE: O(n).
 */
void Interface::airportStatistic(){
    cout << endl << "=========AIRPORT STATISTICS=========" << endl;
    cout << endl;
    cout << "Choose the statistic:" << endl;
    cout << endl << "Options:\n\t1-Total airports\n\t2-Total cities\n\t3-Total countries\n\t4-Total airlines\n\t5-Total flights\n\tb-Back\n\te-Exit"<<endl;

    char option;
    while (true){
        cout << "Choose option:";
        cin >> option;
        switch (option) {
            case ('1'):
                d_.totalAirports();
            case ('2'):
                d_.totalCities();
            case ('3'):
                d_.totalCountries();
            case ('4'):
                d_.totalAirlines();
            case ('5'):
                d_.totalFlights();
            case ('b'):
                return;
            case ('e'):
                return exitProgram();

            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}


/**
 * Função mostra os autores do programa.
 *
 * COMPLEXIDADE: O(n).
 */
void Interface::credits() const {
    cout << endl << "=========CREDITS=========" << endl;
    cout << endl;
    cout << "Made by:" << endl;
    cout << "Carolina Viana, up202108802" << endl;
    cout << "Guilherme Monteiro, up202108668" << endl;
    cout << "Sofia Sa, up202108676" << endl;

    cout << endl << endl << "Options:\n\tb-Back\n\te-Exit"<< endl;
    char input;
    while (true) {
        cout << "Choose option:";
        cin >> input;

        switch (input) {
            case ('b'):
                return;
            case ('e'):
                return exitProgram();
            default:
                cout << endl << "Not a valid option" << endl;
        }
    }
}

void Interface::exitProgram() const {
    cout << endl << "Exiting program..." << endl;
    throw 200;
}