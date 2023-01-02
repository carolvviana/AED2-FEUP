#include "Interface.h"
#include <iostream>
#include <regex>
//FAZER COUTS PARA CADA FUNÇÃO

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
    cout << endl << "Options:\n\t1-Airport\n\t2-City\n\t3-Country\n\t4-Coordinates\n\t5-Coordinate & Radius\n\tb-Back\n\te-Exit"<<endl;
    int flag = 1;
    char inputTypeO;
    string inputOrigin;
    int inputRadiusO = 0;
    while (flag){
        cout << "Choose option:";
        cin >> inputTypeO;
        switch (inputTypeO) {
            case ('1'):
                cout << endl << "Insert origin airport:" << endl;
                cin >> inputOrigin;
                flag = 0;
                break;
            case ('2'):
                cout << endl << "Insert origin city:" << endl;
                cin >> inputOrigin;
                flag = 0;
                break;

            case ('3'):
                cout << endl << "Insert origin country:" << endl;
                cin >> inputOrigin;
                flag = 0;
                break;

            case ('4'):
                cout << endl << "Insert origin coordinates: [Format: x.(...),y.(...)]" << endl;
                cin >> inputOrigin;
                flag = 0;
                break;

            case ('5'):
                cout << endl << "Insert origin coordinates: [Format: x.(...),y.(...)]" << endl;
                cin >> inputOrigin;
                cout << endl << "Insert radius:" << endl;
                cin >> inputRadiusO;
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
    cout << endl << "Options:\n\t1-Airport\n\t2-City\n\t3-Country\n\t4-Coordinates\n\t5-Coordinates & radius\n\tb-Back\n\te-Exit"<<endl;

    char inputTypeD;
    string inputDestination;
    int inputRadiusD = 0;
    while (true){
        cout << "Choose option:";
        cin >> inputTypeD;
        switch (inputTypeD) {
            case ('1'):
                cout << endl << "Insert destination airport:" << endl;
                cin >> inputDestination;
                d_.flight(inputOrigin, inputDestination, inputTypeO-48, inputTypeD-48, inputRadiusO ,inputRadiusD);
                lastPage();
                return welcomePage();
            case ('2'):
                cout << endl << "Insert destination city:" << endl;
                cin >> inputDestination;
                d_.flight(inputOrigin, inputDestination, inputTypeO-48, inputTypeD-48,inputRadiusO ,inputRadiusD);
                lastPage();
                return welcomePage();
            case ('3'):
                cout << endl << "Insert destination country:" << endl;
                cin >> inputDestination;
                d_.flight(inputOrigin, inputDestination, inputTypeO-48, inputTypeD-48,inputRadiusO ,inputRadiusD);
                lastPage();
                return welcomePage();
            case ('4'):
                cout << endl << "Insert destination coordinates: [Format: x.(...),y.(...)]" << endl;
                cin >> inputDestination;
                d_.flight(inputOrigin, inputDestination, inputTypeO-48, inputTypeD-48,inputRadiusO ,inputRadiusD);
                lastPage();
                return welcomePage();
            case ('5'):
                cout << endl << "Insert destination coordinates: [Format: x.(...),y.(...)]" << endl;
                cin >> inputDestination;
                cout << endl << "Insert radius:" << endl;
                cin >> inputRadiusD;
                d_.flight(inputOrigin, inputDestination, inputTypeO-48, inputTypeD-48, inputRadiusO,inputRadiusD);
                lastPage();
                return welcomePage();
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
                return getStatistics();
            case ('2'):
                countryStatistic();
                return getStatistics();
            case ('3'):
                cityStatistic();
                return getStatistics();
            case ('4'):
                //airlineStatistic();
                return getStatistics();
                break;
            case ('5'):
                airportStatistic();
                return getStatistics();
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
    cout << "Insert the name of the country:" << endl;
    string c;
    cin >> c;
    cout << "Choose the statistic:" << endl;
    cout << endl << "Options:\n\t1-Total airports\n\t2-Total flights\n\t3-Total airlines\n\t4-Total destinations\n\t5-Total cities\n\tb-Back\n\te-Exit"<<endl;

    char option;
    while (true){
        cout << "Choose option:";
        cin >> option;
        switch (option) {
            case ('1'):
                d_.nAirports1(c);
            case ('2'):
                d_.nFlights1(c);
            case ('3'):
                d_.nAirlines1(c);
            case ('4'):
                d_.nDestinations1(c);
            case ('5'):
                d_.nCities1(c);
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
void Interface::cityStatistic(){ //DONE
    cout << endl << "=========CITY STATISTICS=========" << endl;
    cout << endl;
    cout << "Insert the name of the city:" << endl;
    string c;
    cin >> c;
    cout << "Choose the statistic:" << endl;
    cout << endl << "Options:\n\t1-Total airports\n\t2-Total flights\n\t3-Total airlines\n\t4-Total destinations\n\tb-Back\n\te-Exit"<<endl;

    char option;
    while (true){
        cout << "Choose option:";
        cin >> option;
        switch (option) {
            case ('1'):
                d_.nAirports2(c);
            case ('2'):
                d_.nFlights2(c);
            case ('3'):
                d_.nAirlines2(c);
            case ('4'):
                d_.nDestinations2(c);
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
/*void Interface::airlineStatistic(){ //AINDA NAO ESTA FEITO
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
}*/


/**
 * Função imprime o menu das estatísticas a nível de Aeroporto que permite ao utilizador escolher a estatística que quer obter e o respetivo aeroporto ou voltar atrás no programa.
 *
 * COMPLEXIDADE: O(n).
 */
void Interface::airportStatistic(){ //DONE
    cout << endl << "=========AIRPORT STATISTICS=========" << endl;
    cout << endl;
    string ap;
    cout << "Insert the airport code:" << endl;
    cin >> ap;
    cout << endl << "Choose the statistic:" << endl;
    cout << endl << "Options:\n\t1-Total flights\n\t2-Total airlines\n\t3-Total destinations\n\tb-Back\n\te-Exit"<<endl;

    char option;

    while (true){
        cout << "Choose option:";
        cin >> option;

        switch (option) {
            case ('1'):
                cout << "Number of flights:" << d_.nFlights3(ap) << endl;
            case ('2'):
                cout << "Number of airlines:" << d_.nAirlines3(ap) << endl;
            case ('3'):
                cout << "Number of destinations:" << d_.nDestinations3(ap) << endl;
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

//extra
/**
 * Função que representa a ultima pagina do menu. Dispoe de duas ultimas opções - voltar atrás e fechar o programa.
 *
 * COMPLEXIDADE: O(n).
 */
void Interface::lastPage() const {
    cout << endl << endl;
    cout << endl << "Options:\n\tb-Back\n\te-Exit"<<endl;
    char input;
    while (true){
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