#include <stdio.h>
#include <stdlib.h>

int compare(const void*a, const void*b)
{
	return(*(int*)a-*(int*)b);
}
double calculateMean(int arr[],int n){
		int sum=0;
		for(int i=0;i<n;i++){
			sum += arr[i];
				}
		return (double)sum/n;
}
 double calculateMedian(int arr[],int n)
{
	qsort(arr,n,sizeof(int),compare);

		if(n%2!=0){
				return arr[n/2];
			}
			else{
				return(double)(arr[(n-1)/2]+arr[n/2]/2.0);
	int calculateMode(int arr[],int n){
		int maxCount = 0;
		int mode = -1;
		for(int i=0;i<n;i++){
			int count=0;
			for(int j=0;j<n;j++);{
						if(arr[j]==arr[i]){
							count++;
								}
							}
					if (count>maxCount){
						maxCount = count;
						mode = arr[i];
						}
					}
					return mode;
				}
int calculateRange(int arr[],int n){
		qsort(arr,n,sizeof(int),compare);
		return arr[n-1]-arr[0];
		}
	int main(){
	
	int n;
		printf("enter the number of values:");
		scanf("%d",&arr[i]);
		}
 	double mean = calculateMean(arr,n);
	int mode= calculateMode(arr,n);
	int range = calculateRange(arr,n);
	printf("Mean: %.2lf\n",mean);
	printf("Median: %.2lf\n",median);
	printf("Mode: %d\n",mode);
	printf("Range: %d\n",range);

	return 0;
}
}



	
