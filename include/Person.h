#pragma once

#include "Date.h"
#include "ProgramErrors.h"
#include <string>
#include <utility>
#include <memory>

enum class SEX { M, F };

class Person {
public:
    explicit Person(std::string &last_name, std::string &first_name, Date *date_of_birth, const SEX sex)
        : _last_name(std::move(checkSurname(last_name))),
          _first_name(std::move(checkName(first_name))),
          _date_of_birth(date_of_birth),
          _sex(sex) {
    }

    [[nodiscard]] std::string getLastname() const {
        return _last_name;
    }

    [[nodiscard]] std::string getFirstName() const {
        return _first_name;
    }

    [[nodiscard]] Date getDateOfBirth() const {
        if (_date_of_birth != nullptr) {
            return *_date_of_birth;
        }
        throw ProgramErrors(ERROR_TYPE::NULLPTR_ERROR, "Object 'date of birth' points to null pointer");
    }

    [[nodiscard]] SEX getSex() const {
        return _sex;
    }

    [[nodiscard]] std::string getFullName() const {
        return getLastname() + " " + getFirstName();
    }

    ~Person() = default;

private:
    std::string _last_name;
    std::string _first_name;
    std::unique_ptr<Date> _date_of_birth;
    SEX _sex;

    [[nodiscard]] static std::string checkName(const std::string &name) {
        if (!name.empty()) {
            return name;
        }
        throw ProgramErrors(ERROR_TYPE::NAME_ERROR, "Name is empty");
    }

    [[nodiscard]] static std::string checkSurname(const std::string &surname) {
        if (!surname.empty()) {
            return surname;
        }
        throw ProgramErrors(ERROR_TYPE::SURNAME_ERROR, "Surname is empty");
    }
};
