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
        "  help, h, ?                       Displays this message\n"
        "  select [option]                  Selects defaults\n"
        "     section <section name>          Selects section\n"
        "     student <student name>          Selects student\n"
        "  create [option]                  Adds an attribute\n"
        "     section <section name>          Adds section\n"
        "                                       -selects section if none has been already\n"
        "     student <lname> , <fname>       Adds student to section\n"
        "                                       -selects student if none has been already\n"
        "     grade <grade key> = <number>    Adds grade to student\n"
        "                                       -updates grade if it already exists\n"
        "  update [option]                  Changes an attribute\n"
        "     grade <grade key> = <number>    Changes grade for student\n"
        "                                       -adds grade if it does not yet exist\n"
        "  drop [option]                    Deletes an attribute\n"
        "     section                         Deletes section\n"
        "     student                         Deletes student\n"
        "     grade <grade key>               Deletes grade from student\n"
        "  lookup [option]                  Searches by keyword\n"
        "     section <keyword>               Searches sections\n"
        "     student <keyword>               Searches students\n"
        "     grade <grade key>               Searches grades\n"
        "  show [option]                    Displays gradebook\n"
        "     sections                        Lists sections\n"
        "                                       -Displays selected section in green\n"
        "     students                        Lists students in selected section\n"
        "                                       -Displays selected section in green\n"
        "     grades <grade key>              Displays single grade for all students\n"
        "     portfolio                       Displays all grades for single student\n"
        "     report                          Displays everything about current section\n"
        "  quit, exit                         Quits the program\n";

string gradebook::WELCOME =
        "Welcome to Gradebook, version 1.0\n"
        "This program is designed to help teachers help students.\n"
        "Type help for usage instructions\n";

string gradebook::PROMPT = "GRADEBOOK> ";

string gradebook::GREEN = "\x1B[32m";
string gradebook::RESET = "\x1B[m";

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
    if (line.size() <= 0) {
        return 0;
    }
    vector<string> tokens = tokenize(line);
    if (tokens[0] == "help" || tokens[0] == "h") {
        cout << gradebook::HELP;
    } else if (tokens[0] == "quit" || tokens[0] == "exit") {
        terminate = true;
    } else {
        if (tokens.size() <= 1) {
            cout << "Not enough arguments\n";
            return -1;
        } else if (tokens[0] == "select") {
            if (tokens[1] == "section") {
                if (tokens.size() > 2) {
                    string key = gradebook::detokenize(tokens, 2);
                    if (books.count(key) > 0) {
                        select_book = key;
                    } else {
                        cout << "Cannot find section titled \'" << key << "\'\n";
                        return -1;
                    }
                } else {
                    cout << "Missing section name\n";
                    return -1;
                }
            } else if (tokens[1] == "student") {
                if (tokens.size() > 2) {
                    string key = gradebook::detokenize(tokens, 2);
                    if (books.count(select_book) > 0) {
                        section *book = &books.find(select_book)->second;
                        if (book->contains(key)) {
                            select_student = key;
                        } else {
                            cout << "Cannot find student named \'" << key << "\'\n";
                            return -1;
                        }
                    } else {
                        cout << "You must select section first\n";
                        return -1;
                    }
                } else {
                    cout << "Missing student name\n";
                    return -1;
                }
            } else {
                cout << "Invalid command. Type help to view help dialog.\n";
                return -1;
            }

        } else if ((tokens[0] == "create" || tokens[0] == "update")
                && tokens[1] == "grade") {
            int equals = -1;
            for (int i = 2; i < tokens.size(); i++) {
                if (tokens[i] == "=") {
                    equals = i;
                }
            }
            if (equals == -1) {
                cout << "Error: format name as <grade key> = <number>\n";
                return -1;
            }
            string key = gradebook::detokenize(tokens, 2, equals);
            if (tokens.size() > equals + 1) {
                string grade_str = gradebook::detokenize(tokens, equals + 1);
                try {
                    double grade = stod(grade_str);
                    if(grade > 100 || grade < 0) {
                        cout << "Grade must be between 0 and 100\n";
                    }
                    if (books.count(select_book) > 0) {
                        section *sect = &books.find(select_book)->second;
                        try {
                            sect->change_grade(select_student, key, grade);
                        } catch (out_of_range& e) {
                            cout << "You must select student first\n";
                            return -1;
                        }
                    } else {
                        cout << "You must select section first\n";
                        return -1;
                    }
                } catch (invalid_argument& e) {
                    cout << "Incorrect number formatting for " << grade_str << "\n";
                    return -1;
                }
            } else {
                cout << "Missing grade number\n";
                return -1;
            }

        } else if (tokens[0] == "create") {
            if (tokens[1] == "section") {
                if(tokens.size() > 2) {
                    string key = gradebook::detokenize(tokens, 2);
                    section temp(key);
                    books.insert({key, temp});
                    if(select_book == "") {
                        select_book = key;
                    }
                } else {
                    cout << "Missing gradebook name\n";
                    return -1;
                }
            } else if (tokens[1] == "student") {
                int comma = -1;
                for (int i = 2; i < tokens.size(); i++) {
                    if (tokens[i] == ",") {
                        comma = i;
                    }
                }
                if (comma == -1) {
                    cout << "Error: format name as <first name> , <last name>\n";
                    return -1;
                }
                string fname = gradebook::detokenize(tokens, 2, comma);
                if (tokens.size() > comma + 1) {
                    string lname = gradebook::detokenize(tokens, comma + 1);
                    if (books.count(select_book) > 0) {
                        section *sect = &books.find(select_book)->second;
                        sect->add_student(fname, lname);
                        if(select_student == "") {
                            select_student = fname + " " + lname;
                        }
                    } else {
                        cout << "You must select section first\n";
                        return -1;
                    }
                } else {
                    cout << "Missing last name\n";
                    return -1;
                }
            } else {
                cout << "Invalid command. Type help to view help dialog.\n";
                return -1;
            }

        } else if (tokens[0] == "drop") {
            if (tokens[1] == "section") {
                if (tokens.size() > 2) {
                    string key = gradebook::detokenize(tokens, 2);
                    if (books.count(key) > 0) {
                        books.erase(key);
                        select_book = "";
                    } else {
                        cout << "Cannot find section named " << key << endl;
                    }
                } else {
                    cout << "Missing section name\n";
                    return -1;
                }
            } else if (tokens[1] == "student") {
                if (tokens.size() > 2) {
                    string key = gradebook::detokenize(tokens, 2);
                    if (books.count(select_book) > 0) {
                        section *sect = &books.find(select_book)->second;
                        sect->expell(key);
                        select_student = "";
                    } else {
                        cout << "You must select section first\n";
                        return -1;
                    }
                } else {
                    cout << "Missing student name\n";
                    return -1;
                }
            } else if (tokens[1] == "grade") {
                if (tokens.size() > 2) {
                    string key = gradebook::detokenize(tokens, 2);
                    if (books.count(select_book) > 0) {
                        section *sect = &books.find(select_book)->second;
                        if (sect->contains(select_student)) {
                            if (sect->find(select_student).contains(key)) {
                                sect->delete_grade(select_student, key);
                            } else {
                                cout << "Cannot find grade called " << key << endl;
                                return -1;
                            }
                        } else {
                            cout << "You must select student first\n";
                            return -1;
                        }
                    } else {
                        cout << "You must select section first\n";
                        return -1;
                    }
                } else {
                    cout << "Missing student name\n";
                    return -1;
                }
            } else {
                cout << "Invalid command. Type help to view help dialog.\n";
                return -1;
            }

        } else if (tokens[0] == "lookup") {
            if (tokens[1] == "section") {
                if (tokens.size() > 2) {
                    string key = gradebook::detokenize(tokens, 2);
                    vector<string> matches = lookup(key);
                    for (string str : matches) {
                        cout << str << "    ";
                    }
                    cout << endl;
                } else {
                    cout << "Missing section keyword\n";
                    return -1;
                }
            } else if (tokens[1] == "student") {
                if (tokens.size() > 2) {
                    string key = gradebook::detokenize(tokens, 2);
                    if (books.count(select_book) > 0) {
                        section sect = books.find(select_book)->second;
                        vector<string> matches = sect.lookup(key);
                        for (string str : matches) {
                            cout << str << "    ";
                        }
                        cout << endl;
                    } else {
                        cout << "You must select section first\n";
                        return -1;
                    }
                } else {
                    cout << "Missing student keyword\n";
                    return -1;
                }
            } else if (tokens[1] == "grade") {
                if (tokens.size() > 2) {
                    string key = gradebook::detokenize(tokens, 2);
                    if (books.count(select_book) > 0) {
                        section sect = books.find(select_book)->second;
                        if (sect.contains(select_student)) {
                            student stu = sect.find(select_student);
                            vector<string> matches = stu.lookup(key);
                            for (string str : matches) {
                                cout << str << "    ";
                            }
                            cout << endl;
                        } else {
                            cout << "You must select student first\n";
                            return -1;
                        }
                    } else {
                        cout << "You must select section first\n";
                        return -1;
                    }
                } else {
                    cout << "Missing grade keyword\n";
                    return -1;
                }
            } else {
                cout << "Invalid command. Type help to view help dialog.\n";
                return -1;
            }

        } else if (tokens[0] == "show") {
            if (tokens[1] == "sections") {
                for (auto sect : books) {
                    if(tokens.size() > 2) {
                        cout << "Invalid parameters after command\n";
                        return -1;
                    }
                    if (sect.first == select_book) {
                        cout << gradebook::GREEN << sect.first <<
                                gradebook::RESET << "    ";
                    } else {
                        cout << sect.first << "    ";
                    }
                }
                cout << endl;
            } else if (tokens[1] == "students") {
                if(tokens.size() > 2) {
                    cout << "Invalid parameters after command\n";
                    return -1;
                }
                if (books.count(select_book) > 0) {
                    section *sect = &books.find(select_book)->second;
                    for (auto stu : sect->stu_map()) {
                        if (stu.first == select_student) {
                            cout << gradebook::GREEN << stu.first <<
                                    gradebook::RESET << "    ";
                        } else {
                            cout << stu.first << "    ";
                        }
                    }
                    cout << endl;
                } else {
                    cout << "You must select section first\n";
                    return -1;
                }
            } else if (tokens[1] == "grades") {
                if (tokens.size() > 2) {
                    string key = gradebook::detokenize(tokens, 2);
                    if (books.count(select_book) > 0) {
                        section *sect = &books.find(select_book)->second;
                        for (auto grade : sect->display_set(key)) {
                            cout << grade.first << " : " << grade.second << endl;
                        }
                    } else {
                        cout << "You must select section first\n";
                        return -1;
                    }
                } else {
                    cout << "Missing grade key\n";
                    return -1;
                }
            } else if (tokens[1] == "averages") {
                if(tokens.size() > 2) {
                    cout << "Invalid parameters after command\n";
                    return -1;
                }
                if (books.count(select_book) > 0) {
                    section *sect = &books.find(select_book)->second;
                    for (auto stu : sect->stu_map()) {
                        cout << stu.first << " : " << stu.second.average() << endl;
                    }
                } else {
                    cout << "You must select section first\n";
                    return -1;
                }
            } else if (tokens[1] == "portfolio") {
                if(tokens.size() > 2) {
                    cout << "Invalid parameters after command\n";
                    return -1;
                }
                if (books.count(select_book) > 0) {
                    section *sect = &books.find(select_book)->second;
                    if (sect->contains(select_student)) {
                        cout << sect->to_string(select_student);
                    } else {
                        cout << "You must select student first\n";
                        return -1;
                    }
                } else {
                    cout << "You must select section first\n";
                    return -1;
                }
            } else if (tokens[1] == "report") {
                if(tokens.size() > 2) {
                    cout << "Invalid parameters after command\n";
                    return -1;
                }
                if (books.count(select_book) > 0) {
                    section *sect = &books.find(select_book)->second;
                    cout << sect->to_string();
                } else {
                    cout << "You must select section first\n";
                    return -1;
                }
            } else {
                cout << "Invalid command. Type help to view help dialog.\n";
                return -1;
            }

        } else {
            cout << "Invalid command. Type help to view help dialog.\n";
            return -1;
        }
    }
    return 0;
}

bool gradebook::term() const {
    return terminate;
}

vector<string> gradebook::lookup(string keyword) const {
    vector<string> matches;
    for (auto iter : books) {
        if (iter.first.find(keyword) != string::npos) {
            matches.push_back(iter.first);
        }
    }
    return matches;
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
    } while (!main_loop.term());
}
