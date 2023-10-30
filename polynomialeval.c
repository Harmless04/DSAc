#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

void main()
{
  int a[MAXSIZE];
  int i, N, power;
  float x, polySum;
  printf("Enter the order of the polynomial\n");
  scanf("%d", & N);
  printf("Enter the value of x\n");
  scanf("%f", & x);
  printf("Enter %d coefficients\n", N + 1);
  for (i = 0; i <= N; i++) {
    scanf("%d", & a[i]);
  }
  polySum = a[0];
  for (i = 1; i <= N; i++) {
    polySum = polySum * x + a[i];
  }
power = N;
 
    printf("Given polynomial is: \n");
    for (i = 0; i <= N; i++)
    {
        if (power < 0)
        {
            break;
        }
        if (a[i] > 0 & i!=0)
            printf(" + ");
        else if (a[i] < 0)
            printf(" - ");
        else
            printf(" ");
        printf("%dx^%d  ", abs(a[i]), power--);
  }
  printf("\nSum of the polynomial = %f\n", polySum);
}
