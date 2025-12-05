#ifndef UNIVERSITY_TEACHER_H
#define UNIVERSITY_TEACHER_H

#include <string>
#include <vector>

#include "Person.h"

using std::string, std::vector;

class Teacher : public Person {
public:
    Teacher(string *last_name, string *first_name, Date *date_of_birth, Sex sex, string *faculty)
        : Person(last_name, first_name, date_of_birth, sex),
          _faculty(faculty) {
        _subjects = new vector<string>();
    }

    ~Teacher() {
        delete _subjects;
        ~Person();
    }

    void addSubject(const string &subject) {
        _subjects->push_back(subject);
    }

    vector<string> getSubjects() const {
        vector<string> subjects = *_subjects;
        return subjects;
    }

    string getFaculty() const {
        string faculty = *_faculty;
        return faculty;
    }

private:
    vector<string> *_subjects;
    string *_faculty;
};

#endif //UNIVERSITY_TEACHER_H