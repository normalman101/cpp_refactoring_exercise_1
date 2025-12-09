#pragma once

#include <string>
#include <vector>

#include "Person.h"
#include "Date.h"

class Teacher : public Person {
public:
    explicit Teacher(std::string &last_name, std::string &first_name, Date *date_of_birth, const SEX sex, std::string &faculty)
        : Person(last_name, first_name, date_of_birth, sex),
          _faculty(std::move(faculty)),
          _subjects(std::make_unique<std::vector<std::string> >()) {
    }

    void addSubject(const std::string &subject) const {
        _subjects->push_back(subject);
    }

    [[nodiscard]] std::vector<std::string> getSubjects() const {
        if (_subjects != nullptr) {
            return *_subjects;
        }
        throw ProgramErrors(ERROR_TYPE::NULLPTR_ERROR, "Object 'subjects' points to null pointer");
    }

    [[nodiscard]] std::string getFaculty() const {
        return _faculty;
    }

    ~Teacher() = default;

private:
    std::unique_ptr<std::vector<std::string> > _subjects;
    std::string _faculty;
};
