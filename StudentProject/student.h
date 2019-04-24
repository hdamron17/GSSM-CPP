/* 
 * File:   student.h
 * Author: hdamron1594
 *
 * Created on August 30, 2016, 7:50 PM
 */

#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class student {
public:
    student();
    student(std::string, std::string, double);
    virtual ~student();
    void set_name(std::string, std::string);
    std::string get_first_name() const;
    std::string get_last_name() const;
    void set_grade(double);
    double get_grade();
private:
    std::string first_name;
    std::string last_name;
    double grade;
};

#endif /* STUDENT_H */

