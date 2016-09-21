/* 
 * Student class: models a student with multiple grades stored in a map
 * File:   student.cpp
 * Author: Hunter Damron
 * 
 * Created on September 5, 2016, 10:30 AM
 */

#include <string>
#include "gradebook.h"

using namespace std;

/**
 * Student constructor provides first and last names
 * @param firstname First name
 * @param lastname Last name
 */
student::student(string firstname, string lastname) {
    first_name = firstname;
    last_name = lastname;
}

/**
 * Default constructor
 */
student::~student() {
}

/**
 * Gets student name as a single string
 * @return  Returns string containing student name
 */
string student::get_name() const {
    return first_name + " " + last_name;
}

/**
 * Gets first name
 * @return Returns string containing student's first name
 */
string student::get_first_name() const {
    return first_name;
}

/**
 * Gets last name
 * @return Returns string containing student's last name
 */
string student::get_last_name() const {
    return last_name;
}

/**
 * Gets the student's grade mapped by string key
 * @param key Key mapped to the grade
 * @return Returns double containing student grade
 */
double student::get_grade(string key) const {
    auto grade = grades.find(key);
    if(grade != grades.end()) {
        return grade->second;
    } else {
        throw out_of_range("Cannot find grade \'" + key + "\'");
    }
}

/**
 * Changes the grade mapped by string key
 * @param key Key mapped to the grade to be changed
 * @param new_grade New grade to replace the old value
 */
void student::change_grade(string key, double new_grade) {
    if(grades.count(key) > 0) {
        grades[key] = new_grade;
    } else {
        grades.insert(make_pair(key, new_grade));
    }
}

/**
 * Deletes grade mapped by string key
 * @param key Key mapped to grade to be deleted
 */
void student::delete_grade(string key) {
    auto iter = grades.find(key);
    grades.erase(iter);
}

/**
 * Calculates the student average
 * @return Returns double containing student's grade average or -1 if student
 *      has no grades
 */
double student::average() const {
    double sum = 0;
    int n = 0;
    for(auto iterator : grades) {
        sum += iterator.second;
        n++;
    };
    if (n != 0) {
        return sum / n;
    } else {
        return -1;
    }
}

/**
 * Gets all of the student's grades
 * @return Returns a map of string to double containing all grades and keys
 */
map<string, double> student::get_grades() const {
    return grades;
}

/**
 * Tests if student has a grade mapped by a particular key
 * @param key Key to test for matches
 * @return Returns true if the student has the specified grade else false
 */
bool student::contains(string key) const{
    return grades.count(key) > 0;
}

/**
 * Looks up grades and finds all whose keys contain the keyword
 * @param keyword Keyword to search for in list of keys
 * @return Returns vector containing full names of all keys which contain the 
 *      keyword
 */
vector<string> student::lookup(string keyword) const {
    vector<string> matches;
    for(auto iter : grades) {
        if(iter.first.find(keyword) != string::npos) {
            matches.push_back(iter.first);
        }
    }
    return matches;
}
 