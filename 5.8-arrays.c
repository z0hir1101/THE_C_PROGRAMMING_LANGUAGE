#include <stdio.h>

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main()
{
  int month, day, day_of_year(int, int, int);
  void month_day(int, int, int *, int *);
  month_day(1980, 343, &month, &day);

  printf("%d\n", day_of_year(2024, 14, 32));
  printf("%d.%d\n", month, day); 

}

int day_of_year(int year, int month, int day)
{
  int i, leap;

  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  if (year < 0 || month > 12 || day > daytab[leap][month])
    return -1;
  for (i = 1; i < month; i++)
    day += daytab[leap][i];
  return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i, leap;

  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  if (year < 0 || yearday > ((leap) ? 366 : 365))
    return ;
  for (i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];
  *pmonth = i;
  *pday = yearday;
}
