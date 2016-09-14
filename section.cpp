/* 
 * Section class: contains multiple students in a single lesson period
 * File:   section.cpp
 * Author: hdamron1594
 * 
 * Created on September 6, 2016, 8:55 PM
 */

#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "gradebook.h"

using namespace std;

section::section(string name) {
    
}

section::~section() {
}

void section::expell(string stu_name) {
    auto iter = students.find(stu_name);
    students.erase(iter);
}

vector<string> section::lookup(string keyword) const {
    vector<string> matches;
    for(auto iter : students) {
        if(iter.first.find(keyword) != string::npos) {
            matches.push_back(iter.first);
        }
    }
    return matches;
}

map<string, double> section::display(string stu_name) const {
    auto stu = students.find(stu_name);
    if(stu != students.end()) {
        return stu->second.get_grades();
    } else {
        throw out_of_range("Cannot find student \'" + stu_name + "\'");
    }
}

double section::get_grade(string stu_name, string grade_key) const {
    auto stu = students.find(stu_name);
    if(stu != students.end()) {
        return stu->second.get_grade(grade_key);
    } else {
        throw out_of_range("Cannot find student \'" + stu_name + "\'");
    }
}

void section::change_grade(string stu_name, string grade_key, double grade) {
    auto stu = students.find(stu_name);
    if(stu != students.end()) {
        stu->second.change_grade(grade_key, grade);
    }
}

void section::delete_grade(string stu_name, string grade_key) {
    auto stu = students.find(stu_name);
    if(stu != students.end()) {
        stu->second.delete_grade(grade_key);
    }
}

double section::average(string stu_name) const {
    auto stu = students.find(stu_name);
    if(stu != students.end()) {
        return stu->second.average();
    } else {
        throw out_of_range("Cannot find student \'" + stu_name + "\'");
    }
}

map<string, double> section::display_set(string grade_key) const {
    map<string, double> disp; //maps name to grade
    for(auto iter : students) {
        student stu = iter.second; 
        try {
            double grade = stu.get_grade(grade_key); //can throw out_of_range
            string stu_name = stu.get_name();
            disp[stu_name] = grade;
        } catch(out_of_range& e) { }; //Nothing to catch, just continue
    }
    return disp;
}

void section::add_student(string fname, string lname) {
    auto match = students.find(fname + " " + lname);
    if(match != students.end()) {
        return; //Does not modify student if he/she already exists
    }
    student temp(fname, lname);
    students.insert(make_pair(fname + " " + lname, temp));
}

void section::add_all(vector<array<string, 2> > new_students) {
    for(auto pair : new_students) {
        string key = pair[0] + " " + pair[1];
        student temp(pair[0], pair[1]);
        students.insert(make_pair(key, temp));
    }
}

map<string, double> section::all_averages() const {
    map<string, double> disp; //maps name to grade average
    for(auto iter : students) {
        student stu = iter.second; 
        double grade = stu.average(); //can throw out_of_range
        string stu_name = stu.get_name();
        disp[stu_name] = grade;
    }
    return disp;
}

map<string, map<string, double> > section::display_all() const {
    map<string, map<string, double> > disp;
    for(auto iter : students) {
        student stu = iter.second;
        disp[stu.get_name()] = stu.get_grades();
    }
    return disp;
}

bool section::contains(string key) const {
    return students.count(key) > 0;
}

student section::find(string key) const {
    return students.find(key)->second;
}

string section::to_string() const {
    stringstream ret;
    for(auto iter : students) {
        student stu = iter.second;
        ret << stu.get_name() << " {";
        map<string, double> grades = stu.get_grades();
        bool first = true;
        for(auto iter : grades) {
            ret << setprecision(5) << (first ? "" : " | ") << iter.first
                    << " = " << iter.second;
            first = false;
        } 
        ret << " ; average: " << stu.average() << "}\n";
    }
    return ret.str();
}

string section::to_string(string stu_name) const {
    stringstream ret;
    student stu = students.find(stu_name)->second;
    ret << stu.get_name() << " {";
    map<string, double> grades = stu.get_grades();
    bool first = true;
    for(auto iter : grades) {
        ret << std::setprecision(5) << (first ? "" : " | ") << iter.first
                << " = " << iter.second;
        first = false;
    } 
    ret << " || average: " << stu.average() << "}\n";
    return ret.str();
}

