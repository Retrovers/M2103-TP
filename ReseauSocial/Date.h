#ifndef DATE_H
#define DATE_H
#include <ctime>

    class Date : tm {
    public:
        Date(void);
        int getYear(void) const;
        int getMonth(void) const;
        int getDay(void) const;
        int getHour(void) const;
        int getMin(void) const;
        int getSec(void) const;
    };

#endif // DATE_H
