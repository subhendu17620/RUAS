#include <stdio.h>

struct student{
  int rl;
  char name[10];
  char address[20];
  int age;
  float marks;
};

struct student s[20];

void get_data(int n);
void print_data(int n);
void elder_older(int n);

int main(int argc, char const *argv[]) {
  printf("Enter number of students: ");
  int count;
  scanf("%d",&count);
  get_data(count);
  print_data(count);
  elder_older(count);
  return 0;
}
void get_data(int n){
  for (int i = 0; i < n; i++) {
    printf("Enter student %d data :",i+1 );
    scanf("%d %s %s %d %f",&s[i].rl,&s[i].name,&s[i].address,&s[i].age,&s[i].marks);
  }
}
void print_data(int n){
  for (int i = 0; i < n; i++) {
    printf("\nDetails of student %d",i+1);
    printf("\nRoll no: %d name: %s address: %s age: %d marks: %f",s[i].rl,s[i].name,s[i].address,s[i].age,s[i].marks);
  }

}

void elder_older(int n){
  int old=s[0].age;
  int o;
  int eld=s[0].age;
  int e;
  for ( int i = 1; i < n ; i++)
  { 
    if (s[i].age > old){
      old=s[i].age;
      o=i;
    }
    
    if (s[i].age < eld){
      eld=s[i].age;
      e=i;
    }
  }
  printf("\nEldest student:  ");
  printf("\nRoll no: %d name: %s address: %s age: %d marks: %f",s[e].rl,s[e].name,s[e].address,s[e].age,s[e].marks);
  printf("\nOldest student:  ");
  printf("\nRoll no: %d name: %s address: %s age: %d marks: %f",s[o].rl,s[o].name,s[o].address,s[o].age,s[o].marks);
  
}