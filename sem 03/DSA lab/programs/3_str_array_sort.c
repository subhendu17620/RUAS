#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char c[10][10];
  for ( int i = 0; i < 5; i++) {
    printf("enter strings :");
    scanf("%s",&c[i]);
  }
  char temp[10];
  strcpy(temp," ");
  for (int i = 0; i < 5; i++) {
    for (int j = i+1; j < 5; j++) {
      if (strcmp(c[i],c[j])>0) {
        strcpy(temp,c[j]);
        strcpy(c[j],c[i]);
        strcpy(c[i],temp);
      }
    }
  }
  printf("\n\nsorted strings: ");
    for (int i = 0; i <5; i++) {
      printf("%s\n",c[i]);
    }
  return 0;
}
