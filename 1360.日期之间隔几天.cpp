/*
 * @lc app=leetcode.cn id=1360 lang=cpp
 *
 * [1360] 日期之间隔几天
 */

// @lc code=start

#include <string>
#include <ctime>

#ifdef _DEBUG_
#include <iostream>
#endif


class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        struct tm t1 = toTM(date1);
        struct tm t2 = toTM(date2);
        std::time_t tt1 = mktime(&t1);
        std::time_t tt2 = mktime(&t2);
        std::time_t diff = abs(tt1 - tt2) / (24 * 60 * 60 * 1000);
        return diff;
    }

    struct tm toTM(const std::string& ymdStr) {
        struct tm t;
        sscanf(ymdStr.c_str(), "%d-%d-%d", &t.tm_year, &t.tm_mon, &t.tm_yday);
        t.tm_hour = 0;
        t.tm_min = 0;
        t.tm_sec = 0;
        t.tm_year -= 1900;
        t.tm_mon -= 1;
        t.tm_isdst = -1;
        return t;
    }
};
// @lc code=end

