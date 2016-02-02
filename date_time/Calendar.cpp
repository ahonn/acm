// Calendar

// Description
// A calendar is a system for measuring time, from hours and minutes, to months and days, and finally to years and centuries. The terms of hour, day, month, year and century are all units of time measurements of a calender system. 
// According to the Gregorian calendar, which is the civil calendar in use today, years evenly divisible by 4 are leap years, with the exception of centurial years that are not evenly divisible by 400. Therefore, the years 1700, 1800, 1900 and 2100 are not leap years, but 1600, 2000, and 2400 are leap years. 
// Given the number of days that have elapsed since January 1, 2000 A.D, your mission is to find the date and the day of the week.

// Input
// The input consists of lines each containing a positive integer, which is the number of days that have elapsed since January 1, 2000 A.D. The last line contains an integer −1, which should not be processed. 
// You may assume that the resulting date won’t be after the year 9999.

// Output
// For each test case, output one line containing the date and the day of the week in the format of "YYYY-MM-DD DayOfWeek", where "DayOfWeek" must be one of "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" and "Saturday".

// Sample Input
// 1730
// 1740
// 1750
// 1751
// -1

// Sample Output
// 2004-09-26 Sunday
// 2004-10-06 Wednesday
// 2004-10-16 Saturday
// 2004-10-17 Sunday

#include <iostream>
#include <cstdio>
using namespace std;

int year[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char dow[7][10] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

int isLeap(int y) {
	if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
		return 1;
	}
	return 0;
}

int main() {
	// freopen("../input.txt", "rt", stdin);
	long n;
	int i, y, m, d;
	while(scanf("%ld", &n) != EOF && n != -1) {
		y = 2000;
		m = 1;
		d = n;
		for(; y <= 9999; y++) {
			if(isLeap(y)) {
				if(d >= 366) {
					d -= 366;
				}
				else{
					break;
				}
			}
			else {
				if(d >= 365) {
					d -= 365;
				}
				else {
					break;
				}
			}
		}

		d ++;
		if(isLeap(y)) {
			year[1] = 29;
		}
		else{
			year[1] = 28;
		}
		for(i = 0;i < 12; ++i) {
			if(d > year[i]) {
				d -= year[i];
				m++;
			}
			else {
				break;
			}
		}

		
		i = n % 7;
		printf("%d-%02d-%02d %s\n", y, m, d, dow[i]);
	}
    return 0;
}

// 测试数据
// 输入    输出
// 59 2000-02-29 Tuesday
// 60 2000-03-01 Wednesday
// 365 2000-12-31 Sunday
// 366 2001-01-01 Monday
// 1460 2003-12-31 Wednesday
// 1461 2004-01-01 Thursday
// 1520 2004-02-29 Sunday
// 1521 2004-03-01 Monday
// 1826 2004-12-31 Friday
// 1827 2005-01-01 Saturday
// 36524 2099-12-31 Thursday
// 36525 2100-01-01 Friday
// 36583 2100-02-28 Sunday
// 36584 2100-03-01 Monday
// 36889 2100-12-31 Friday
// 36890 2101-01-01 Saturday
// 146096 2399-12-31 Friday
// 146097 2400-01-01 Saturday
// 146156 2400-02-29 Tuesday
// 146157 2400-03-01 Wednesday