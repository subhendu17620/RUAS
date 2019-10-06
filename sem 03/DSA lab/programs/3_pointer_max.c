#include <stdio.h>

#define  MAX 5

void max(int *n,int l){
  int max_num = *n,i=0;
  while (i<l) {
    if (*n>max_num) {
      max_num = *n;
    }
    n++;
    i++;
  }
  printf("%d\n",max_num );
}

void read(int a[], int l){
  printf("\nEnter the numbers:");
  for(int i = 0; i < l; i++){
    scanf("%d", &a[i]);
  }
}

int main(int argc, char const *argv[]) {
  int a[MAX],l=MAX;
  read(a,l);
  max(&a,l);
  return 0;
}
