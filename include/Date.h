#pragma once

#include "ProgramErrors.h"

enum class DAYS {
    BEGIN_DAY = 1, END_DAY_28 = 28, END_DAY_30 = 30, END_DAY_31 = 31
};

enum class MONTH {
    JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNY, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
};

class Date {
public:
    explicit Date(const int day, const int month, const int year)
        : _day(checkDayForRange(day, month)),
          _month(checkMonthForRange(month)),
          _year(year) {
    }

    [[nodiscard]] unsigned int getDay() const {
        return _day;
    }

    [[nodiscard]] unsigned int getMonth() const {
        return _month;
    }

    [[nodiscard]] int getYear() const {
        return _year;
    }

    ~Date() = default;

private:
    unsigned int _day;
    unsigned int _month;
    int _year;

    static void checkDay(const unsigned int day, const DAYS &end) {
        if (day > static_cast<int>(end) or day < static_cast<int>(DAYS::BEGIN_DAY)) {
            throw ProgramErrors(ERROR_TYPE::DAY_ERROR, "Day wasn't set correctly");
        }
    }

    [[nodiscard]] static unsigned int checkDayForRange(const unsigned int day, const unsigned month) {
        if (month == static_cast<int>(MONTH::FEBRUARY)) {
            checkDay(day, DAYS::END_DAY_28);
        } else if (month == static_cast<int>(MONTH::APRIL) or month == static_cast<int>(MONTH::JUNY)
                   or month == static_cast<int>(MONTH::SEPTEMBER) or month == static_cast<int>(MONTH::NOVEMBER)) {
            checkDay(day, DAYS::END_DAY_30);
        } else {
            checkDay(day, DAYS::END_DAY_31);
        }
        return day;
    }

    [[nodiscard]] static unsigned int checkMonthForRange(const unsigned int month) {
        if (month > static_cast<int>(MONTH::DECEMBER) or month < static_cast<int>(MONTH::JANUARY)) {
            throw ProgramErrors(ERROR_TYPE::MONTH_ERROR, "Month wasn't set correctly");
        }
        return month;
    }
};
