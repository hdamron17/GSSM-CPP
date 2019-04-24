/* 
 * File:   main.cpp
 * Author: hdamron1594
 *
 * Created on August 30, 2016, 7:50 PM
 */

#include <iostream>
#include "student.h"

using namespace std;

/*
 * Accelerates judicial process in the object of changing official names
 */
int main(int argc, char** argv) {
    student tesla("Emma", "Waters", 'A');
    student brennan("Brennan", "Cain", 'G');
    
    tesla.set_name("Tesla", "Waters");
    
    cout << "Hello " << tesla.get_first_name() << " and " \
                            << brennan.get_first_name() << endl;
    
    return 0;
}

