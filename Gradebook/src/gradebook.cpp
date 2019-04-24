/* 
 * File:   gradebook.cpp
 * Author: hdamron1594
 * 
 * Created on August 29, 2016, 10:09 AM
 */

#include <iostream>
#include <string>
#include "gradebook.h"

using namespace std;

gradebook::gradebook()  // default constructor
{
}

gradebook::~gradebook()  // default destructor
{
}

void gradebook::set_name(string course_name) // sets name of course
{
    name = course_name;
}

string gradebook::get_name() const // returns name of course
{
    return name;
}

void gradebook::display_message( ) const // welcome message
{
    cout << "Welcome to the grade book for course: " << get_name() << endl;
}

void gradebook::set_grade(char course_grade)  // changes course name
{
    grade = course_grade;
}

char gradebook::get_grade() const    // returns current course grade
{
    return grade;
}

void gradebook::display_data() const // displays all info we have
{
    cout << "Name of course: " << get_name() << "  Grade: "  <<  get_grade() \
            << endl;
}
