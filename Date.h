#include "ProgramErrors.h"

#ifndef UNIVERSITY_DATE_H
#define UNIVERSITY_DATE_H

const ProgramErrors ERROR_DAY(DayError, "Day wasn't set correctly");
const ProgramErrors ERROR_MONTH(MonthError, "Month wasn't set correctly");

enum class DAYS {
    BEGIN_DAY = 1, END_DAY_28 = 28, END_DAY_30 = 30, END_DAY_31 = 31
};

class Date {
public:
    Date(const int &day, const int &month, const int &year)
        : _day{0},
          _month{0},
          _year{year} {
        {
            if (month > 12 || month < 1) {
                throw ERROR_MONTH;
            }

            switch (month) {
                case 2:
                    checkDay(day, DAYS::END_DAY_28);
                    break;
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    checkDay(day, DAYS::END_DAY_31);
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    checkDay(day, DAYS::END_DAY_30);
                    break;
                default:
                    break;
            }
        }

        _day = day;
        _month = month;
        _year = year;
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

private:
    unsigned int _day;
    unsigned int _month;
    int _year;

    void checkDay(const int &day, const DAYS &end) {
        int begin_day = static_cast<int>(DAYS::BEGIN_DAY);
        int end_day = static_cast<int>(end);
        if (day > end_day || day < begin_day) {
            throw ERROR_DAY;
        }
    }
};

#endif //UNIVERSITY_DATE_H
