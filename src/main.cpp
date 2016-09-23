/* 
 * Main function of Gradebook project: creates and modifies gradebook instance
 * File:   main.cpp
 * Author: Hunter Damron
 *
 * Created on September 5, 2016, 10:29 AM
 */

#include <iostream>

#include "gradebook.h"

using namespace std;

/* 
 * Main function calls user interface loop within gradebook
 * @return Returns the return value from gradebook::run()
 */
int main(int argc, char** argv) {
    
    return gradebook::run(argc, argv);
}
 