#include <stdio.h>

int BSR(int a[],int low,int high,int tar){
  int mid = (low+high)/2;
  if (low>high || high<low){
    printf("Not found!!");
    return 0;
  }
  if (tar > a[mid]) {
    low = mid+1;
    BSR(a,low,high,tar);
  }
  if (tar < a[mid]) {
    high = mid-1;
    BSR(a,low,high,tar);
  }
  if (tar == a[mid]) {
    printf("%d was found at position %d\n",tar,mid );
    return 1;
  }
}

int main(int argc, char const *argv[]) {
  printf("Enter size : ");
  int n;
  scanf("%d",&n );
  int a[n];
  printf("Enter numbers : ");
  for (int i = 0; i < n; i++) {
    scanf("%d",&a[i]);
  }
  int tar,flag=0;
  printf("Enter the target : ");
  scanf("%d",&tar );

  BSR(a,0,(n-1),tar);
  return 0;
}
