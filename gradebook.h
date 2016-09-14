/* 
 * Header for Gradebook project: Organizes gradebook, section, and student
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
    //constructors and destructors
    explicit student(string, string); //Constructor with first and last name
    virtual ~student(); //Default destructor
    
    //accessors
    string get_name() const; //Gets full student name
    string get_first_name() const; //Gets first name
    string get_last_name() const; //Gets last name
    double average() const; //Gets average of all grades
    map<string, double> get_grades() const; //Gets map of all grades
    double get_grade(string) const; //Gets grade under specified key
    bool contains(string) const; //tests if contains key
    
    //mutators
    void change_grade(string, double); //Changes grade under specified key
    void delete_grade(string); //Deletes grade at specified key
    
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
    //constructors and destructors
    explicit section(string); //Constructor with class name
    virtual ~section(); //Default constructor
    
    //accessors
    vector<string> lookup(string) const; //Finds student names
    map<string, double> display(string) const; //Gets grades map
    double get_grade(string, string) const; //Gets grade with specified key
    double average(string) const; //Gets average of all grades
    map<string, double> display_set(string) const;//Gets specified grade for all
    map<string, double> all_averages() const; //Gets averages for all students
    map<string, map<string, double> > display_all() const; //Gets everything
    bool contains(string) const; //tests if contains key
    student find(string) const; //gets student or gives out_of_range
    string to_string() const; // toString function for entire roster
    string to_string(string) const; // toString function for one student
    
    //mutators
    void expell(string); //Deletes student at specified key
    void change_grade(string, string, double);//Changes grade with specified key
    void delete_grade(string, string); //Deletes grade with specified key
    void add_student(string, string); //Adds student to roster
    void add_all(vector<array<string,2> >); //Adds multiple students
    
private:
    map<string, student> students;
    string classname;

};

#endif /* ROSTER_H */

#ifndef GRADEBOOK_H
#define GRADEBOOK_H

class gradebook {
public:
    //constructors and destructors
    explicit gradebook();
    virtual ~gradebook();
     
    //accessors
    bool term() const; //returns true if it is ready to terminate looping
    vector<string> lookup(string) const; //looks up books
    
    //mutators
    int parse(string); //parses and executes string command
    
    //static methods and variables
    static vector<string> tokenize(string); //tokenizes string; delimiter=" "
    static vector<string> tokenize(string, string); //tokenizes string
    static string detokenize(vector<string>, int); //puts vector back together
    static string detokenize(vector<string>, int, int); //uses end = tokens.size())
    
    static int run(); //static main for gradebook class
    
    static string HELP;
    static string WELCOME;
    static string PROMPT;
    
private:
    map<string, section> books;
    string select_book;
    string select_student;
    bool terminate;
};

#endif /* GRADEBOOK_H */

