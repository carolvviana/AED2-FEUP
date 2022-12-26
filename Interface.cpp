//
// Created by carol on 13/12/2022.
//
#include "Interface.h"
#include <iostream>
#include <regex>

using namespace std;

Interface::Interface() = default;
//0

void Interface::welcomePage() {
    cout << endl << "=========WELCOME PAGE=========" << endl;
    cout << endl << "Options:\n\t1-Select files to read\n\t2-Credits\n\te-Exit"<<endl;
    char input;
    while (true){
        cout << "Choose option:";
        cin >> input;

        switch (input) {
            case ('1'):
                readFiles();
                return welcomePage();
            case ('2'):
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
 * Função imprime o menu de leitura dos ficheiros, permite ao utilizador escolher entre os ficheiros "default" ou os ficheiros já alterados.
 *
 * COMPLEXIDADE: O(n).
 */
void Interface::readFiles() {
    cout << endl << "=========READ FILES=========" << endl;
    cout << endl;
    cout << "Which files do you want to read?" << endl;
    cout << endl << "Options:\n\t1-Default files\n\tb-Back\n\te-Exit"<<endl;
    char input;
    while (true){
        cout << "Choose option:";
        cin >> input;
        switch (input) {
            case ('1'):
                d_.readFile_airlines("..\\csv\\airlines.csv");
                d_.readFile_airports("..\\csv\\airports.csv");
                d_.readFile_flights("..\\csv\\flights.csv");
                // mainMenu();
                return readFiles();

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