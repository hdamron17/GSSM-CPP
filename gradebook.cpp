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
        "Gradebook, version 1.0\n"
        "Usage:\n"
        "  help                                     \tDisplays this message\n"
        "  select                                   \tSelects defaults\n"
        "     section - <section name>              \t  Selects section\n"
        "     student [options] - <student name>    \t  Selects student\n"
        "        -sect <section name>               \t    Specifies section\n"
        "  delete                                   \tDeletes an attribute\n"
        "     section [options] - <section name>    \t  Deletes section\n"
        "        -a                                 \t    deletes all sections (replace \'- <section name>\')\n"
        "     student [options] - <student name>    \t  Deletes student\n"
        "        -sect <section name>               \t    Overrides student selection\n"
        "        -a                                 \t    deletes all students in selected section\n"
        "     grade [options] - <grade key>         \t  Deletes grade from student\n"
        "        -sect <section name>               \t    Overrides section selection\n"
        "        -stu <student name>                \t    Overrides student selection\n"
        "        -a                                 \t    Deletes all grades in selected section and student\n"
        "  add                                      \tAdds an attribute\n"
	"     section [options] - <section name>    \t  Adds section\n"
	"     student [options] - <student name>    \t  Adds student to section\n"
	"	 -sect <section name>               \t    Overrides section selection\n"
	"     grade [options] - <grade key>         \t  Adds grade to student\n"
        "        -sect <section name>               \t     Overrides section selection\n"
        "        -stu <student name>                \t     Overrides student selection\n"
        "  change                                   \tChanges an attribute\n"
	"     grade [options] - <grade key>         \t  Changes grade for student\n"
        "        -sect <section name>               \t    Overrides section selection\n"
        "        -stu <student name>                \t    Overrides student selection\n"
        "  lookup                                   \tSearches by keyword\n"
	"     section [options] - <keyword>         \t  Searches sections\n"
	"     student [options] - <keyword>         \t  Searches students\n"
        "        -sect <section name>               \t    Overrides section selection\n"
	"     grade [options] - <grade key>         \t  Searches grades\n"
        "        -sect <section name>               \t    Overrides section selection\n"
        "        -stu <student name>                \t    Overrides student selection\n"
        "  display                                  \tDisplays gradebook\n"
	"     portfolio [options] [- <student name>]\t  displays all grades for single student\n"
        "        -sect <section name>               \t     Overrides section selection\n"
	"     sections                              \t  lists sections\n"
	"     students                              \t  lists students in selected section\n"
        "        -sect <section name>               \t    Overrides section selection\n"
	"     grades [options] - <gradekey>         \t  displays single grade for all students\n"
        "        -sect <section name>               \t    Overrides section selection\n"
        "        -stu <student name>                \t    Overrides student selection\n"
	"     section [- <section name>]            \t  displays everything about current section\n"
        "        -a                                 \t    Displays all sections at once\n"
        "  quit                                     \tQuits the program\n"
        "* Note that -sect and -stu flags temporarily override defaults\n"
        "     If not included, selected defaults are used";
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

