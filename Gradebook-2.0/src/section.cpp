/* 
 * Section class: contains multiple students in a single lesson period
 * File:   section.cpp
 * Author: Hunter Damron
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

/**
 * Section constructor provides section name
 * @param name Name of section
 */
section::section(string name) {
    
}

/**
 * Default destructor
 */
section::~section() {
}

/**
 * Deletes the student with the specified name if possible
 * @param stu_name Full name of student to be deleted
 */
void section::expell(string stu_name) {
    auto iter = students.find(stu_name);
    students.erase(iter);
}

/**
 * Looks up students whose names contain the keyword
 * @param keyword Keyword to be matched in student names
 * @return Returns vector of valid student names which contain the keyword
 */
vector<string> section::lookup(string keyword) const {
    vector<string> matches;
    for(auto iter : students) {
        if(iter.first.find(keyword) != string::npos) {
            matches.push_back(iter.first);
        }
    }
    return matches;
}

/**
 * Gets a map containing everything about a particular student
 * @param stu_name Name of student to be displayed
 * @return Returns map of string to double containing a student's grades mapped
 *      by grade keys
 */
map<string, double> section::display(string stu_name) const {
    auto stu = students.find(stu_name);
    if(stu != students.end()) {
        return stu->second.get_grades();
    } else {
        throw out_of_range("Cannot find student \'" + stu_name + "\'");
    }
}

/**
 * Gets a single grade for a single student
 * @param stu_name Name of student to get grade from
 * @param grade_key Key mapped to grade
 * @return Returns the specified grade of the specified student
 */
double section::get_grade(string stu_name, string grade_key) const {
    auto stu = students.find(stu_name);
    if(stu != students.end()) {
        return stu->second.get_grade(grade_key);
    } else {
        throw out_of_range("Cannot find student \'" + stu_name + "\'");
    }
}

/**
 * Changes a single grade for a single student
 * @param stu_name Name of student to get grade from
 * @param grade_key Key mapped to grade
 * @param grade New grade to replace old value
 */
void section::change_grade(string stu_name, string grade_key, double grade) {
    auto stu = students.find(stu_name);
    if(stu != students.end()) {
        (&stu->second)->change_grade(grade_key, grade);
    }
}

/**
 * Deletes single grade from single student
 * @param stu_name Name of student to delete grade from
 * @param grade_key Key mapped to grade to be deleted
 */
void section::delete_grade(string stu_name, string grade_key) {
    auto stu = students.find(stu_name);
    if(stu != students.end()) {
        stu->second.delete_grade(grade_key);
    }
}

/**
 * Calculates student's grade average
 * @param stu_name Name of student to get average for
 * @return Returns double containing student's grade average (or -1 if student
 *      has no grades)
 */
double section::average(string stu_name) const {
    auto stu = students.find(stu_name);
    if(stu != students.end()) {
        return stu->second.average();
    } else {
        throw out_of_range("Cannot find student \'" + stu_name + "\'");
    }
}

/**
 * Gets a particular grade for all students in the section only includes 
 *      students who have the particular grade
 * @param grade_key Key mapped to grade in each student
 * @return Returns a map of string to double with student name mapped to grade
 */
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

/**
 * Creates new student and adds it to section map
 * @param fname New student's first name
 * @param lname New student's last name
 */
void section::add_student(string fname, string lname) {
    auto match = students.find(fname + " " + lname);
    if(match != students.end()) {
        return; //Does not modify student if he/she already exists
    }
    student temp(fname, lname);
    students.insert(make_pair(fname + " " + lname, temp));
}

/**
 * Calculates averages for all students in section
 * @return Returns map of string to double containing student names mapped to 
 *      grade averages
 */
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

/**
 * Gets everything about the section for display
 * @return Returns a map of student name mapped to a map for each student 
 *      containing grade key mapped to double precision grade value
 */
map<string, map<string, double> > section::display_all() const {
    map<string, map<string, double> > disp;
    for(auto iter : students) {
        student stu = iter.second;
        disp[stu.get_name()] = stu.get_grades();
    }
    return disp;
}

/**
 * Tests if section contains a student with specified name
 * @param key Name of student to test for
 * @return Returns true if section contains particular student else false
 */
bool section::contains(string key) const {
    return students.count(key) > 0;
}

/**
 * Gets a student in the section by name
 * @param key Name of student to find
 * @return Returns instance of student class for the specified student
 */
student section::find(string key) const {
    return students.find(key)->second;
}

/**
 * Generates string representation of section
 * @return Returns multi-line string containing information about all students
 */
string section::to_string() const {
    stringstream ret;
    for(auto iter : students) {
        student stu = iter.second;
        ret << stu.get_name() << " {";
        map<string, double> grades = stu.get_grades();
        bool first = true;
        for(auto iter : grades) {
            ret.precision(5);
            ret << (first ? "" : " | ") << iter.first
                    << " = " << iter.second;
            first = false;
        } 
        if(grades.size() > 0) {
            ret << " ; average: " << stu.average() << "}\n";
        } else {
            ret << "average: N/A}\n";
        }
    }
    if(students.size() <= 0) {
        cout << endl;
    }
    return ret.str();
}

/**
 * Generates string representation of one student in section
 * @param stu_name Name of student for which string should be produced
 * @return Returns single-line string containing information for one student
 */
string section::to_string(string stu_name) const {
    stringstream ret;
    student stu = students.find(stu_name)->second;
    ret << stu.get_name() << " {";
    map<string, double> grades = stu.get_grades();
    bool first = true;
    for(auto iter : grades) {
        ret.precision(5);
        ret << (first ? "" : " | ") << iter.first
                << " = " << iter.second;
        first = false;
    } 
    if(grades.size() > 0) {
        ret << " ; average: " << stu.average() << "}\n";
    } else {
        ret << "average: N/A}\n";
    }
    return ret.str();
}

/**
 * Gets a map of students to reveal all of the section's students
 * @return Returns map of string to student containing name mapped to 
 *      student instance
 */
map<string, student> section::stu_map() const {
    return students;
}
