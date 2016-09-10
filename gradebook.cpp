/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   gradebook.cpp
 * Author: hdamron1594
 * 
 * Created on September 9, 2016, 10:18 PM
 */

#include "gradebook.h"

gradebook::gradebook() {
    select_book = "";
    select_student = "";
    terminate = false;
}

gradebook::~gradebook() {
}

void gradebook::parse(string line) {
    
}

bool gradebook::term() const {
    return terminate;
}

vector<string> gradebook::tokenize(string str) {
    string delimiter = " ";
    vector<string> tokens;
    int start = 0;
    int end = 0;
    while(end != string::npos) {
        end = str.find(delimiter, start);
        tokens.push_back(str.substr(start, end));
        start = end;
    }
    return tokens;
}

vector<string> gradebook::tokenize(string str, string delimiter=" ") {
    vector<string> tokens;
    int start = 0;
    int end = 0;
    while(end != string::npos) {
        end = str.find(delimiter, start);
        tokens.push_back(str.substr(start, end));
        start = end;
    }
    return tokens;
}
