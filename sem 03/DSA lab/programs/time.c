#include <stdio.h>
#include <stdlib.h>
struct time
{
  int s,m,h;
};
struct time T1, T2;
void add(struct time T1, struct time T2)
 {
  int min, sec, hr;
  sec = T1.s + T2.s;
  min = T1.m + T2.m + sec/60;
  sec = sec%60;
  hr = T1.h + T2.h + min/60;
  min = min%60;
  printf("Hours = %d, min = %d, sec = %d\n", hr,min,sec);
}

int main(int argc, char const *argv[])
{
  printf("Enter the 1st time object\n");
  scanf("%d%d%d",&T1.h,&T1.m,&T1.s);
  printf("Enter the 2nd time object\n");
  scanf("%d%d%d",&T2.h,&T2.m,&T2.s);
  add (T1,T2);
  return 0;
}