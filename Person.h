#ifndef UNIVERSITY_PERSON_H
#define UNIVERSITY_PERSON_H

#include <string>

#include "Date.h"

using std::string;

enum Sex { M, F };

class Person {
public:
    Person(string* last_name, string* first_name, Date* date_of_birth, const Sex& sex)
        : _last_name(last_name),
          _first_name(first_name),
          _date_of_birth(date_of_birth),
          _sex(sex) {
    }
    ~Person() {
        delete _last_name;
        delete _first_name;
        delete _date_of_birth;
    }

    string getLastname() const {
        string last_name = *_last_name;
        return last_name;
    }

    string getFirstName() const {
        string first_name = *_first_name;
        return first_name;
    }

    Date* getDateOfBirth() const {
        return _date_of_birth;
    }

    Sex getSex() const {
        return _sex;
    }

    string getFullName() const {
        return getLastname() + " " + getFirstName();
    }

private:
    string* _last_name;
    string* _first_name;
    Date* _date_of_birth;
    Sex _sex;
};

#endif //UNIVERSITY_PERSON_H