#include<stdio.h>

void get_data(int m1[][10], int m2[][10],int r1, int c1, int r2, int c2){
  	printf("\nEnter elements of matrix 1:\n");
	for(int i = 0; i < r1; i++)
	{for(int j = 0; j < c1; j++)
		{scanf("%d", &m1[i][j]);
		}
	}
	printf("\nEnter elements of matrix 2:\n");
	for(int i = 0; i < r2; i++)
	{for(int j = 0; j < c2; j++)
		{scanf("%d", &m2[i][j]);
		}
	}
}

void multmat(int m1[][10], int m2[][10],int mult[][10] ,int r1, int c1, int r2, int c2)
{
	int i, j, k;
	for(i = 0; i < r1; i++){
		for(j = 0; j < c2; j++){
			for(k=0; k<c1; k++){
				mult[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
}


void addmat(int m1[][10], int m2[][10],int add[][10] ,int r1, int c1, int r2, int c2){
for(int i = 0; i < r1; i++)
	{
		for(int j = 0; j < c2; j++)
		{
			add[i][j] = m1[i][j]+m2[i][j];
		}
	}
}
void print(int res[][10],int m,int n){
  for(int i = 0; i < m; i++)
	{for(int j = 0; j < n; j++)
		{printf("%d\t", res[i][j]);
		}printf("\n");
	}
}

int main(int argc, char const *argv[])
{
  int m1[10][10], m2[10][10], add[10][10], mult[10][10], r1, c1, r2, c2, i, j, k;
	printf("Enter rows and column for first matrix: ");
	scanf("%d %d", &r1, &c1);
	printf("Enter rows and column for second matrix: ");
	scanf("%d %d", &r2, &c2);
	
  while (c1 != r2)
	{
		printf("Can't Multiply or add.\n");
		printf("Enter rows and column for first matrix: ");
		scanf("%d%d", &r1, &c1);
		printf("Enter rows and column for second matrix: ");
		scanf("%d%d", &r2, &c2);
	}

  get_data(m1,m2,r1,c1,r2,c2);
  multmat(m1,m2,mult,r1,c1,r2,c2);
  addmat(m1,m2,add,r1,c1,r2,c2);
  printf("Multiplied Matrix is: \n ");
  print(mult,r1,c2);
  printf("Added Matrix is: \n ");
  print(add,r1,c1);
  
  return 0;
}
