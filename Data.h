//
// Created by carol on 13/12/2022.
//

#ifndef AEDP2_DATA_H
#define AEDP2_DATA_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Coordinate.h"
using namespace std;

class Data{
private:


public:

    //file reading methods
    void readFile_airlines(string fname);
    void readFile_airports(string fname);
    void readFile_flights(string fname);

};



#endif //AEDP2_DATA_H
