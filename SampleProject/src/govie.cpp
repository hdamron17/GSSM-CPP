/* 
 * File:   govie.cpp
 * Author: hdamron1594
 * 
 * Created on August 29, 2016, 10:21 AM
 */

#include "govie.h"

#include <iostream>
#include <string>

using namespace std;

govie::govie() {
}

govie::govie(string govie_name) {
    name = govie_name;
}

govie::~govie() {
}

void govie::scream() const {
    cout << "\"AAAAHHHHHHHHHHHHHH! GODWIN HOMEWORK!!!\" -" << name << endl;
}

void govie::set_name(string govie_name) {
    name = govie_name;
}

string govie::get_name() const {
    return name;
}

void govie::disp_welcome() const {
    cout << "\"Wake up " << name << "! You can talk to me after class\" " \
            "-Dr. Godwin" << endl;
}

