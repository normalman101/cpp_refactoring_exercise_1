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
                throw ERROR_MONTH; //Test
            }

            switch (month) {
                case 1:
                    checkDay(day, DAYS::END_DAY_31);
                    break;
                case 2:
                    checkDay(day, DAYS::END_DAY_28);
                    break;
                case 3:
                    checkDay(day, DAYS::END_DAY_31);
                    break;
                case 4:
                    checkDay(day, DAYS::END_DAY_30);
                    break;
                case 5:
                    checkDay(day, DAYS::END_DAY_31);
                    break;
                case 6:
                    checkDay(day, DAYS::END_DAY_30);
                    break;
                case 7:
                    checkDay(day, DAYS::END_DAY_31);
                    break;
                case 8:
                    checkDay(day, DAYS::END_DAY_31);
                    break;
                case 9:
                    checkDay(day, DAYS::END_DAY_30);
                    break;
                case 10:
                    checkDay(day, DAYS::END_DAY_31);
                    break;
                case 11:
                    checkDay(day, DAYS::END_DAY_30);
                    break;
                case 12:
                    checkDay(day, DAYS::END_DAY_31);
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
