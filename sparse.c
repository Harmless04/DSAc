#include<stdio.h>
void main()
{
	int a[100][100],i,j,p,q,c=0;
	printf("enter the order p:");
	scanf("%d",&p);
	printf("enter the order q");
	scanf("%d",&q);
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++);
		{
			printf("enter the element:");
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{
			if(a[i][j]!=0)
			{
				c++;
				printf("index:%d%d",i,j);
			}
	}
}
printf("count=%d\n",c);
}

	
	
	
