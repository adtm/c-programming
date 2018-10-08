//
//  Exercise 5-9. Rewrite the routines day_of_year and month_day with pointers instead of
//  indexing.
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
    
    int leap = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    int *p = &year_mapping[leap][1];
    
    int i;
    for (i = 1; i < month; ++i) {
        day += *p;
        ++p;
    }
    
    return day;
}

void month_day(int year, int year_day, int *m, int *d) {
    
    int leap = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    int *p = &year_mapping[leap][1];
    
    int i;
    for (i = 1; year_day > *p; ++i) {
        year_day -= *p;
        ++p;
    }
    
    *m = i;
    *d = year_day;
}
