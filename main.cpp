#include <iostream>

#include "include/Date.h"
#include "include/ProgramErrors.h"
#include "include/Teacher.h"

int main() {
    std::string name = "Pidor";
    std::string surname = "Pidorasnia";
    std::string faculty = "C++ programming";
    Date date(12, 11, 1990);
    try {
        Person person(surname, name, &date, SEX::M);
        std::cout << person.getFullName();
    } catch (ProgramErrors& error) {
        std::cerr << error.what() << ". Exit code: " << error.getError();
    }
}