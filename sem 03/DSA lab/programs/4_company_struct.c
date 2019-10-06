#include <stdio.h>


struct company{
  char name[20];
  char address[50];
  long long int ph_num;
  int num_em;
};
struct company company_data;

void read_data();
void print_data();

int main(int argc, char const *argv[]) {
  fflush(stdin);
  read_data();
  print_data();
  return 0;
}

void read_data(){

  printf("Enter Name of Company : ");
  scanf("%s",&company_data.name);
  char c;
  scanf("%c",&c);
  
  printf("Enter address of Company : ");
  gets(company_data.address);

  printf("Enter phone number of Company : +91 ");
  scanf("%lld",&company_data.ph_num);

  printf("Enter Number of Employees in the Company : ");
  scanf("%d",&company_data.num_em);
}

void print_data(){
  printf("\n\n Company Data:\n\n");
  printf("Name of Company : %s \n",company_data.name);

  printf("Address of Company : %s\n",company_data.address);

  printf("Phone number of Company : +91 %lld\n",company_data.ph_num);

  printf("Number of Employees in the Company %d\n",company_data.num_em);
}
