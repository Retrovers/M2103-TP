#include "Date.h"
#include <ctime>

using namespace std;

    Date::Date(): tm (){
        time_t t;
        time (&t);
        tm local =*localtime (&t);
        this->tm_min = local.tm_min;
        this->tm_mon = local.tm_mon;
        this->tm_sec = local.tm_sec;
        this->tm_hour = local.tm_hour;
        this->tm_year = local.tm_year;
    }

    int Date::getMonth(void) const {
        return this->tm_mon + 1;
    }

    int Date::getYear(void) const {
        return this->tm_year + 1900;
    }

    int Date::getDay(void) const {
         return this->tm_mday;
    }

    int Date::getHour(void) const {
        return this->tm_hour;
    }

    int Date::getMin(void) const {
        return this->tm_min;
    }

    int Date::getSec(void) const {
        return this->tm_sec;
    }


