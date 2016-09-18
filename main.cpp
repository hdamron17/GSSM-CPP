/* 
 * Main function of Gradebook project: creates and modifies gradebook instance
 * File:   main.cpp
 * Author: hdamron1594
 *
 * Created on September 5, 2016, 10:29 AM
 */

#include <iostream>

//TODO remove
#include <iomanip>

#include "gradebook.h"

using namespace std;

/* 
 * 
 */
int main(int argc, char** argv) {
    /**
     * Fake User Interface
     */
//    section test_sect("C++ and occasionally Linux");
//    test_sect.add_student("Brennan", "Cain");
//    test_sect.add_student("Hunter", "Damron");
//    test_sect.add_student("Dennis", "Perea");
//    
//    test_sect.change_grade("Brennan Cain", "Test 1", 94);
//    test_sect.change_grade("Brennan Cain", "Test 2", 78); //oops
//    test_sect.change_grade("Hunter Damron", "Test 1", 99);
//    test_sect.change_grade("Hunter Damron", "Test 2", 98);
//    test_sect.change_grade("Dennis Perea", "Test 1", 89);
//    test_sect.change_grade("Dennis Perea", "Test 2", 93);
//    
//    cout << test_sect.to_string();
//    
//    cout << endl;
//    
//    test_sect.expell("Dennis Perea");
//    cout << "Haha can't get Dennis's stuff anymore. He gone." << endl;
//    
//    cout << "Brennan's average before change: " << 
//            test_sect.average("Brennan Cain") << endl;
//    test_sect.change_grade("Brennan Cain", "Test 2", 98);
//    cout << "Brennan's average after change: " << 
//            test_sect.average("Brennan Cain") << endl;
//    
//    cout << endl;
//    
//    cout << "Personal portfolio\n" << test_sect.to_string("Hunter Damron");
//    
//    cout << endl;
//    
//    cout << "Entire roster\n" << test_sect.to_string();
    
    /**
     * Real User Interface function
     */
    
//    cout << "------------------------------\n"
//            "Continuing to the REAL main\n"
//            "------------------------------\n\n";
    
    return gradebook::run();
}
 