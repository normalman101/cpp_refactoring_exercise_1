#include <iostream>

#include "Date.h"
#include "ProgramErrors.h"
#include "Teacher.h"

int main() {
    std::string name = "Donald";
    std::string surname = "Trump";
    std::string faculty = "C++ programming";
    Date date(12, 11, 1990);
    try {
        Person person(surname, name, &date, SEX::M);
        std::cout << person.getFullName();
    } catch (ProgramErrors &error) {
        std::cerr << error.what() << ". Exit code: " << error.getError();
    }
}
