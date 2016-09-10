/* 
 * File:   gradebook.h
 * Author: hdamron1594
 *
 * Created on September 5, 2016, 10:30 AM
 */

#include <string>
#include <vector>
#include <map>

using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

class student {
public:
    student(string, string); //Constructor with first and last name
    virtual ~student(); //Default destructor
    string get_name() const; //Gets full student name
    string get_first_name() const; //Gets first name
    string get_last_name() const; //Gets last name
    double get_grade(string); //Gets grade under specified key
    void change_grade(string, double); //Changes grade under specified key
    void delete_grade(string); //Deletes grade at specified key
    double average() const; //Gets average of all grades
    map<string, double> get_grades() const; //Gets map of all grades
    
private:
    string first_name;
    string last_name;
    map<string, double> grades;

};

#endif /* STUDENT_H */


#ifndef ROSTER_H
#define ROSTER_H

class section {
public:
    section(string); //Constructor with class name
    virtual ~section(); //Default constructor
    void expell(string); //Deletes student at specified key
    vector<string> lookup(string) const; //Finds student names
    map<string, double> display(string) const; //Gets grades map
    double get_grade(string, string); //Gets grade with specified key
    void change_grade(string, string, double);//Changes grade with specified key
    void delete_grade(string, string); //Deletes grade with specified key
    double average(string) const; //Gets average of all grades
    map<string, double> display_set(string) const;//Gets specified grade for all
    void add_student(string, string); //Adds student to roster
    void add_all(vector<array<string,2> >); //Adds multiple students
    map<string, double> all_averages() const; //Gets averages for all students
    map<string, map<string, double> > display_all() const; //Gets everything
    
private:
    map<string, student> students;
    string classname;

};

#endif /* ROSTER_H */

#ifndef GRADEBOOK_H
#define GRADEBOOK_H

class gradebook {
public:
    gradebook();
    virtual ~gradebook();
    void parse(string); //parses and executes string command
    bool term() const; //returns true if it is ready to terminate looping
    static vector<string> tokenize(string); //tokenizes string; delimiter=" "
    static vector<string> tokenize(string, string); //tokenizes string
    
private:
    map<string, section> books;
    string select_book;
    string select_student;
    bool terminate;
    
    string HELP; //Help msg
    string WELCOME; //Welcome msg

};

#endif /* GRADEBOOK_H */

