/* 
 * File:   main.cpp
 * Author: hdamron1594
 *
 * Created on August 29, 2016, 10:20 AM
 */

#include <iostream>
#include <string>
#include "src/govie.h"

using namespace std;

int main(int argc, char** argv) {
    govie brennan("Brennan");
    govie hunter("Hunter");
    
    hunter.scream();
    hunter.set_name("Brennan #2");
    
    brennan.disp_welcome();
    hunter.disp_welcome();
    
    return 0;
}

