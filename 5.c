static int day_tab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

struct date {
  int  day;
  int  month;
  int  year;
  int  yearday;
  char mon_name[4];
};

// insert day_of_year(pd) from p.122 here
day_of_year(pd)
struct date *pd;
{
  int i, day, leap;
  day = pd -> day;
  leap = pd -> year % 4 == 0 && pd -> year % 100 != 0 || pd -> year % 400 == 0;
  for(i = 1; i < pd -> month; i++)
    day += day_tab[leap][i];
  return day;
}




int main() {
  struct date first_day = { 9, 9, 2013, 0, "Sep" };
  first_day.yearday = day_of_year(&first_day);
  printf ("%s %d %d is day number %d\n",
          first_day.mon_name, first_day.day, 
          first_day.year, first_day.yearday);
}
