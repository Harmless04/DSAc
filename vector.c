#include <stdio.h>
int main ()
{
	
	int r1,c1;
	printf("enter the row and column of matrix");
	scanf("%d %d",&r1,&c1);
	int a[r1][c1],b[c1][1],c[r1][1];
	printf("enter the matrix\n");
	for(int i=0;i<r1;i++){
	
		for(int j=0;j<c1;j++){
	scanf("%d",&a[i][j]);
	}
}
printf("enter the vector");
	for(int i=0;i<c1;i++)
{
	for(int j=0;j<1;j++)
		{
			scanf("%d",&b[i][j]);
		}
}
printf("the product is\n");
for(int i=0; i<r1; i++){
		for(int j=0; j<1 ;j++)
{
	for(int k = 0; k<3;k++)
	c[i][j] += a[i][k] * b[k][j];
	}
	for(int i=0; i<3;i++)
{
	for(int j=0;j<3;j++);
	printf("%d\t",c[i][j]);

printf("\n");
}
}
return 0;
}




		

	
