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
    
    HELP = 
            "Gradebook, version 1.0\n" + 
            "Usage:\n" +
            "help   \t Displays this message\n"
            "select \t Selects defaults\n"
            "delete \t Deletes an attribute\n"
            "add    \t Adds an attribute\n"
            "change \t Changes an attribute\n"
            "lookup \t Searches by keyword\n"
            "display\t Displays gradebook\n"
            "quit   \t Quits the program";
}

gradebook::~gradebook() {
}

void gradebook::parse(string line) {
    vector<string> tokens = tokenize(line);
//    switch(tokens[0])
//        case "help":
//            //TODO
//            break;
//        case "display":
//            //TODO
//            break;
//        case "lookup":
//            //TODO
//            break;
//        case "select":
//            //TODO
//            break;
//        default:
//            //TODO
//            break;
    
    // TODO Figure out switches with strings or use if else
}

bool gradebook::term() const {
    return terminate;
}

vector<string> gradebook::tokenize(string str) {
    return tokenize(str, " ");
}

vector<string> gradebook::tokenize(string str, string delimiter) {
    vector<string> tokens;
    int start = 0;
    int end = 0;
    while(end != string::npos) {
        end = str.find(delimiter, start);
        string sub = str.substr(start, end - start);
        if(sub.size() > 0) {
            tokens.push_back(sub);
        }
        start = end + delimiter.size();
    }
    return tokens;
}

