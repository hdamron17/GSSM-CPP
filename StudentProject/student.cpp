/* 
 * File:   student.cpp
 * Author: hdamron1594
 * 
 * Created on August 30, 2016, 7:50 PM
 */

#include <string>
#include "student.h"

using namespace std;

student::student() {
}

student::student(string first, string last, double grade) {
    first_name = first;
    last_name = last;
    grade = grade;
}

student::~student() {
}

void student::set_name(string first, string last) {
    first_name = first;
    last_name = last;
}

string student::get_first_name() const {
    return first_name;
}

string student::get_last_name() const {
    return last_name;
}

void student::set_grade(double student_grade) {
    grade = student_grade;
}

double student::get_grade() {
    return grade;
}