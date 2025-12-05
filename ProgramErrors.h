#pragma once
#include <exception>
#include <string>

#ifndef UNIVERSITY_PROGRAMERRORS_H
#define UNIVERSITY_PROGRAMERRORS_H

enum ErrorType {
    MonthError, DayError
};

class ProgramErrors final : public std::exception {
public:
    ProgramErrors(const ErrorType& error, const std::string& error_message)
        : m_error{error},
          m_error_message{error_message} {}

private:
    ErrorType m_error;
    std::string m_error_message;
};

#endif //UNIVERSITY_PROGRAMERRORS_H