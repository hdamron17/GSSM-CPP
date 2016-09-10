/* 
 * File:   main.cpp
 * Author: hdamron1594
 *
 * Created on September 5, 2016, 10:29 AM
 */

#include <iostream>

//TODO remove extra libs
#include <map>

#include "gradebook.h"

using namespace std;

/* 
 * 
 */
int main(int argc, char** argv) {
    student brennan("Brennan", "Cain");
    brennan.change_grade("Test 1", 93);
    brennan.change_grade("Test 2", 68);
    cout << "Average is " << brennan.average() << endl;
    brennan.delete_grade("Test 2");
    cout << "Average is " << brennan.average() << endl;
    
    section sect("Physics");
    sect.add_student("Tesla", "Waters");
    sect.change_grade("Tesla Waters", "Test 1", 89);
    sect.change_grade("Tesla Waters", "Test 2", 97);
    sect.change_grade("Tesla Waters", "Test 3", 69);
    
    vector<array<string,2> > new_stus = 
    {{"Brennan", "Cain"}, {"Hunter", "Damron"}};
    sect.add_all(new_stus);
    
    sect.change_grade("Brennan Cain", "Test 2", 93);
    sect.change_grade("Hunter Damron", "Test 2", 96);
    sect.change_grade("Hunter Damron", "Test 3", 86);
    
    cout << endl << "Tesla" << endl;
    for(auto iter : sect.display("Tesla Waters")) {
        cout << iter.first << " = " << iter.second << endl;
    }
    
    cout << endl << "Test 2" << endl;
    for(auto iter : sect.display_set("Test 2")) {
        cout << iter.first << " = " << iter.second << endl;
    }
    
    cout << endl << "Test 3" << endl;
    for(auto iter : sect.display_set("Test 3")) {
        cout << iter.first << " = " << iter.second << endl;
    }
    
    cout << endl << "Averages" << endl;
    for(auto iter : sect.all_averages()) {
        cout << iter.first << " = " << iter.second << endl;
    }
    
    sect.add_student("Brennan #2", "Cain");
    for(string match : sect.lookup("Bren")) {
        cout << match + " ; ";
    } cout << endl;
    
    cout << "Brennan #2 has a " << sect.average("Brennan #2 Cain") << endl;

    vector<string> tokenized = gradebook::tokenize("I love beans");
    for(string item : tokenized) {
        cout << item << " | "; 
    } cout << endl;
    
    gradebook* test = new gradebook();
    bool randbool = test->term();
}
