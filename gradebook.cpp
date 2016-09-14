/* 
 * Gradebook class: holds multiple sections and has UI loop (unfinished)
 * File:   gradebook.cpp
 * Author: hdamron1594
 * 
 * Created on September 9, 2016, 10:18 PM
 */

#include <iostream>
#include "gradebook.h"

string gradebook::HELP =
        "Gradebook, version 1.0\n"
        "Usage:\n"
        "  help                            \tDisplays this message\n"
        "  h                               \tSame as help\n"
        "  select                          \tSelects defaults\n"
        "     section <section name>       \t  Selects section\n"
        "     student <student name>       \t  Selects student\n"
        "  add                             \tAdds an attribute\n"
        "     section <section name>       \t  Adds section\n"
        "     student <lname> , <fname>    \t  Adds student to section\n"
        "     grade <grade key> = <number> \t  Adds grade to student\n"
        "  change                          \tChanges an attribute\n"
        "     grade <grade key> = <number> \t  Changes grade for student\n"
        "  delete                          \tDeletes an attribute\n"
        "     section                      \t  Deletes section\n"
        "     student                      \t  Deletes student\n"
        "     grade <grade key>            \t  Deletes grade from student\n"
        "  lookup                          \tSearches by keyword\n"
        "     section <keyword>            \t  Searches sections\n"
        "     student <keyword>            \t  Searches students\n"
        "     grade <grade key>            \t  Searches grades\n"
        "  display                         \tDisplays gradebook\n"
        "     sections                     \t  lists sections\n"
        "     students                     \t  lists students in selected section\n"
        "     grades <gradekey>            \t  displays single grade for all students\n"
        "     portfolio                    \t  displays all grades for single student\n"
        "     section                      \t  displays everything about current section\n"
        "  quit                            \tQuits the program";

string gradebook::WELCOME =
        "Welcome to Gradebook, version 1.0\n"
        "This program is designed to help teachers help students.\n"
        "Type help for usage instructions";

string gradebook::PROMPT = "GRADEBOOK> ";

/**
 * Default constructor
 */
gradebook::gradebook() {
    select_book = "";
    select_student = "";
    terminate = false;
}

gradebook::~gradebook() {
}

int gradebook::parse(string line) {
    vector<string> tokens = tokenize(line);
    if (tokens[0] == "help" || tokens[0] == "h") {
        cout << gradebook::HELP;
    } else if (tokens[0] == "select") {
        if (tokens[1] == "section") {
            string key = gradebook::detokenize(tokens, 2);
            try {
                books.find(key);
                select_book = key;
            } catch (out_of_range& e) {
                cout << "Cannot find grade book titled \'" << key << "\'";
                return -1;
            }
        } else if (tokens[1] == "student") {
            string key = gradebook::detokenize(tokens, 2);
            try {
                section book = books.find(select_book)->second;
                if (book.contains(key)) {
                    select_book = key;
                } else {
                    cout << "Cannot find grade student named \'" << key << "\'";
                    return -1;
                }
            } catch (out_of_range& e) {
                cout << "You must select book first";
                return -1;
            }
        }
    } else if (tokens[0] == "add") {
        if (tokens[1] == "section") {
            string key = gradebook::detokenize(tokens, 2);
            section temp(key);
            books.insert({key, temp});
        } else if (tokens[1] == "student") {
            int comma = -1;
            for (int i = 2; i < tokens.size(); i++) {
                if (tokens[i] == ",") {
                    comma = i;
                }
            }
            if (comma == -1) {
                cout << "Error: format name as <first name> , <last name>";
                return -1;
            }
            string fname = gradebook::detokenize(tokens, 2, comma);
            string lname = gradebook::detokenize(tokens, comma + 1);
            try {
                section sect = books.find(select_book)->second;
                student temp(fname, lname);
            } catch (out_of_range& e) {
                cout << "You must select book first";
            }
        }
    } else if (tokens[1] == "grade") {
        int equals = -1;
        for (int i = 2; i < tokens.size(); i++) {
            if (tokens[i] == "=") {
                equals = i;
            }
        }
        if (equals == -1) {
            cout << "Error: format name as <key> = <number>";
            return -1;
        }
        string key = gradebook::detokenize(tokens, equals);
        string grade_str = gradebook::detokenize(tokens, equals);
        try {
            double grade = stod(grade_str);
            try {
                section sect = books.find(select_book)->second;
                try {
                    student stu = sect.find(select_student);
                    stu.change_grade(key, grade);
                } catch (out_of_range& e) {
                    cout << "You must select student first";
                }
            } catch (out_of_range& e) {
                cout << "You must select book first";
            }
        } catch (out_of_range& e) {
            cout << "Incorrect number formatting";
        }
    } else if (tokens[0] == "change") {
        if (tokens[1] == "grade") {
            string key = gradebook::detokenize(tokens, 2);
        }
    } else if (tokens[0] == "delete") {
        if (tokens[1] == "section") {

        } else if (tokens[1] == "student") {

        } else if (tokens[1] == "grade") {
            string key = gradebook::detokenize(tokens, 2);
        }
    } else if (tokens[0] == "lookup") {
        if (tokens[1] == "section") {
            string key = gradebook::detokenize(tokens, 2);
        } else if (tokens[1] == "student") {
            string key = gradebook::detokenize(tokens, 2);
        } else if (tokens[1] == "grade") {
            string key = gradebook::detokenize(tokens, 2);
        }
    } else if (tokens[0] == "display") {
        if (tokens[1] == "sections") {

        } else if (tokens[1] == "students") {

        } else if (tokens[1] == "grades") {
            string key = gradebook::detokenize(tokens, 2);
        } else if (tokens[1] == "averages") {

        } else if (tokens[1] == "portfolio") {

        } else if (tokens[1] == "section") {

        }
    } else if (tokens[0] == "quit") {
        terminate = true;
    } else {
        cout << "Invalid command. Type h to view help dialog.";
    }
    return 0;
}

bool gradebook::term() const {
    return terminate;
}

vector<string> gradebook::tokenize(string str) {
    return tokenize(str, " ");
}

vector<string> gradebook::tokenize(string str, string delimiter) {
    vector<string> tokens;
    int start = 0;
    int end = 0;
    while (end != string::npos) {
        end = str.find(delimiter, start);
        string sub = str.substr(start, end - start);
        if (sub.size() > 0) {
            tokens.push_back(sub);
        }
        start = end + delimiter.size();
    }
    return tokens;
}

string gradebook::detokenize(vector<string> tokens, int begin) {
    return gradebook::detokenize(tokens, begin, tokens.size());
}

string gradebook::detokenize(vector<string> tokens, int begin, int end) {
    if (begin > end - 1 || begin < 0) {
        throw out_of_range("Beginning index is not in vector");
    }
    string together = tokens[begin];
    for (int i = begin + 1; i < end; i++) {
        together = together + " " + tokens[i];
    }
    return together;
}

int gradebook::run() {
    gradebook main_loop;
    string input = "";
    cout << gradebook::WELCOME << endl;
    do {
        cout << gradebook::PROMPT;
        getline(cin, input);
        main_loop.parse(input);
        cout << endl;
    } while (!main_loop.term());
}