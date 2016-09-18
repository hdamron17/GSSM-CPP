/* 
 * Student class: models a student with multiple grades stored in a map
 * File:   student.cpp
 * Author: hdamron1594
 * 
 * Created on September 5, 2016, 10:30 AM
 */

#include <string>
#include "gradebook.h"

using namespace std;

student::student(string firstname, string lastname) {
    first_name = firstname;
    last_name = lastname;
}

student::~student() {
}

string student::get_name() const {
    return first_name + " " + last_name;
}

string student::get_first_name() const {
    return first_name;
}

string student::get_last_name() const {
    return last_name;
}

double student::get_grade(string key) const {
    auto grade = grades.find(key);
    if(grade != grades.end()) {
        return grade->second;
    } else {
        throw out_of_range("Cannot find grade \'" + key + "\'");
    }
}

void student::change_grade(string key, double new_grade) {
    grades[key] = new_grade;
}

void student::delete_grade(string key) {
    auto iter = grades.find(key);
    grades.erase(iter);
}

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

map<string, double> student::get_grades() const {
    return grades;
}

bool student::contains(string key) const{
    return grades.count(key) > 0;
}

vector<string> student::lookup(string keyword) const {
    vector<string> matches;
    for(auto iter : grades) {
        if(iter.first.find(keyword) != string::npos) {
            matches.push_back(iter.first);
        }
    }
    return matches;
}
