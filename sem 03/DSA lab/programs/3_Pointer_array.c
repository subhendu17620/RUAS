#include <stdio.h>

void pointer_sum(int *p,int k);

int main(int argc, char const *argv[]) {
  int n;
  printf("input no. of element: ");
  scanf("%d",&n);
  int a[n];
  printf("Enter the numbers:");
  for(int i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
 
 pointer_sum(&a,n);
  return 0;
}
void pointer_sum(int *p,int k){
  int add=0;
  
  for ( int i = 0; i < k; i++){
    add+=(*p);
    p++;
  }
    printf("sum is %d ",add);
  

}

