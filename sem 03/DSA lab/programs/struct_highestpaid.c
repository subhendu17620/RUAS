#include <stdio.h>
#include <stdlib.h>
struct employee // structure tag or structure definition
{
  int employ_no;
  char name[20];
  float salary;
};

struct employee E[20];
int main(int argc, char const *argv[]) {
  int n,i,a,large = 0,pos = 0;
  printf("How many employees? \n");
  scanf("%d", &n);
  for (i=0;i<n;i++)
  {
      printf("Enter employee number, name and salary \n");
  for (i= 0;i < n;i++)
  {
    scanf("%d%s%f",&E[i].employ_no,&E[i].name,&E[i].salary);

    {if (E[i].salary> large)
     {
      large = E[i].salary;
      pos = i;
    }
  }
  }
  printf("Highest paid is \n employee number:%d \n Employee name: %s \n salary: %f \n",E[pos].employ_no,E[pos].name, E[pos].salary );
  return 0;
}
}