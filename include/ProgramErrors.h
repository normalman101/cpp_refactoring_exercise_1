#pragma once

#include <string>

enum class ERROR_TYPE {
    MONTH_ERROR, DAY_ERROR, NAME_ERROR, SURNAME_ERROR, NULLPTR_ERROR
};

class ProgramErrors final : public std::runtime_error {
public:
    explicit ProgramErrors(const ERROR_TYPE error, const std::string &error_message)
        : runtime_error(error_message),
          m_error(error) {
    }

    [[nodiscard]] int getError() const {
        return static_cast<int>(m_error);
    }

private:
    ERROR_TYPE m_error;
};
