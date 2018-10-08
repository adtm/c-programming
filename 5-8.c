//
//  Exercise 5-8. There is no error checking in day_of_year or month_day. Remedy this defect.
//
#include <stdio.h>

void month_day(int year, int year_day, int *m, int *d);
int day_of_year(int year, int month, int day);

static int year_mapping[2][13] =  {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main () {
    int dayOfYear = day_of_year(2018, 8, 12);
    printf("%d, dayOfYear \n", dayOfYear);
    
    int month, day;
    month_day(2018, 224, &month, &day);
    printf("%d month, %d day \n", month, day);
    
}

int day_of_year(int year, int month, int day) {
    
    // month check
    if (month < 0 || month > 12)
        return -1;
    
    // day check
    if ((year_mapping[year][month] < day || day < 0))
        return -1;
    
    
    int leap = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    
    int i;
    for (i = 1; i < month; ++i) {
        day += year_mapping[leap][i];
    }
    
    return day;
}

void month_day(int year, int year_day, int *m, int *d) {
    
    int leap = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    
    int i;
    for (i = 1; year_day > year_mapping[leap][i]; ++i)
        year_day -= year_mapping[leap][i];
    
    
    *m = i;
    *d = year_day;
}
