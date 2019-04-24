/* 
 * File:   gradebook.h
 * Author: hdamron1594
 *
 * Created on August 29, 2016, 10:09 AM
 */

#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <string>

class gradebook
{
    public:
        gradebook();				// default constructor
        explicit gradebook(std::string);	// constructor passed param
        virtual ~gradebook();			// default destructor
        void set_name(std::string);	// mutator for course name
        std::string get_name() const;	// accessor for course name
        void set_grade(char);	// mutator for course grade
        char get_grade() const;	// accessor for course grade
        void display_message() const;		// display welcome message
        void display_data() const;		// display current field values

    private:
        std::string name;
        char grade;
};

#endif // GRADEBOOK_H

