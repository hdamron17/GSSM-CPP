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

#include <iostream>
#include "gradebook.h"

string gradebook::HELP = 
    "Gradebook, version 1.0\n"
    "Usage:\n"
    "  help                       \tDisplays this message\n"
    "  select                     \tSelects defaults\n"
    "     section <section name>  \t  Selects section\n"
    "     student <student name>  \t  Selects student\n"
    "  delete                     \tDeletes an attribute\n"
    "     section                 \t  Deletes section\n"
    "        -a                   \t    Deletes all sections\n"
    "     student                 \t  Deletes student\n"
    "        -a                   \t    Deletes all students in selected section\n"
    "     grade <grade key>       \t  Deletes grade from student\n"
    "        -a                   \t    Deletes all grades in selected section and student\n"
    "  add                        \tAdds an attribute\n"
    "     section <section name>  \t  Adds section\n"
    "     student <student name>  \t  Adds student to section\n"
    "     grade <grade key>       \t  Adds grade to student\n"
    "  change                     \tChanges an attribute\n"
    "     grade <grade key>       \t  Changes grade for student\n"
    "  lookup                     \tSearches by keyword\n"
    "     section <keyword>       \t  Searches sections\n"
    "     student <keyword>       \t  Searches students\n"
    "     grade <grade key>       \t  Searches grades\n"
    "  display                    \tDisplays gradebook\n"
    "     portfolio               \t  displays all grades for single student\n"
    "     sections                \t  lists sections\n"
    "     students                \t  lists students in selected section\n"
    "     grades <gradekey>       \t  displays single grade for all students\n"
    "     section                 \t  displays everything about current section\n"
    "  quit                       \tQuits the program";

string gradebook::WELCOME = 
    "Welcome to Gradebook, version 1.0\n"
    "This program is designed to help teachers help students.\n"
    "Type help for usage instructions";

string gradebook::PROMPT = "GRADEBOOK> ";

/**
 * Default constructor
 */
gradebook::gradebook() {
    select_book = "";
    select_student = "";
    terminate = false;
    
    
}

gradebook::~gradebook() {
}

void gradebook::parse(string line) {
    vector<string> tokens = tokenize(line);
    if(tokens[0] == "help") {
        
    } else if(tokens[0] == "select") {
        if(tokens[1] == "section") {
            
        } else if(tokens[1] == "student") {
            
        } 
    } else if(tokens[0] == "delete") {
        
    } else if(tokens[0] == "add") {
        
    } else if(tokens[0] == "change") {
        
    } else if(tokens[0] == "lookup") {
        
    } else if(tokens[0] == "display") {
        
    } else if(tokens[0] == "quit") {
        terminate = true;
    } else {
        
    }
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

string gradebook::detokenize(vector<string> tokens, int begin) {
    if(begin > tokens.size() - 1) {
        throw out_of_range("Beginning index is not in vector");
    }
    //TODO finish putting string vector back together
}

void gradebook::run() {
    gradebook main_loop;
    string input;
        cout << gradebook::WELCOME << endl;
    do {
        cout << gradebook::PROMPT;
        cin >> input;
        main_loop.parse(input);
    } while(!main_loop.term());
}
