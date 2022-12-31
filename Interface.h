//
// Created by carol on 13/12/2022.
//

#ifndef AEDP2_INTERFACE_H
#define AEDP2_INTERFACE_H

#include "Data.h"

using namespace std;
class Interface {

public:
    Data d_;

    void setData(Data d){d_ = d;}
    Interface();
    //Data getData(){return d;}
    //0
    void welcomePage();
    //1
    void getFlights();
    void credits() const;

    void exitProgram() const;
    void getStatistics();

    void globalStatistic();
    void countryStatistic();
    void cityStatistic();
    void airlineStatistic();
    void airportStatistic();
    /*
    //2
    void mainMenu();
    //3
    void studentsMenu() const;
    void timetablesMenu() const;
    void requestsMenu() ;
    //4-students
    void studentsInfo() const;
    void studentsList() const;
    //4-classes

    //4-timetables

    //4-requests
    void createRMenu() ;
    void processRMenu() ;
    //extra
    void lastPage() const;

    //sorter menu
    void sortMenuList(list<Student*> l) const;
    void sortMenuSet(set<Student*,studentComparatorAlpha1> s) const;
    //general
    void exitProgram() const;
    void quitMenu() const;
    //utils
    vector<UCClass*> createVec() const;
*/
};


#endif //AEDP2_INTERFACE_H
