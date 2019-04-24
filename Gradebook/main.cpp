/* 
 * Main function of Gradebook project - contains class for gradebook and 
 *      a main function which creates two instances of the gradebook class
 * File:   main.cpp
 * Author: Hunter Damron
 * Honor Code: On my honor, I have neither given nor received any unauthorized
 *      help on this assignment.
 * Created on August 26, 2016, 11:30 PM
 */

#include <iostream>
#include <string>
#include "src/gradebook.h"

using namespace std;

int main() {
    string course1_name;
    string course2_name;
    string course1_letter;
    string course2_letter;
    gradebook book1;
    gradebook book2;
    
    cout << "Please enter the name of the first course \n>>> ";
    getline(cin, course1_name);
    book1.set_name(course1_name);
    book1.display_message();
    cout << "Enter the letter grade for " << course1_name << "\n>>> ";
    getline(cin, course1_letter);
    book1.set_grade(course1_letter[0]);
    cout << endl;
    
    cout << "Please enter the name of the second course \n>>> ";
    getline(cin, course2_name);
    book2.set_name(course2_name);
    book2.display_message();
    cout << "Enter the letter grade for " << course2_name << "\n>>> ";
    getline(cin, course2_letter);
    book2.set_grade(course2_letter[0]);
    cout << endl;
    
    book1.display_data();
    book2.display_data();
    
    return 0;
}