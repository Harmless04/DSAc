#include <stdio.h>
void main(){
	int arr[3][3]={
		      {3,4,1},
		      {5,1,0},
		      {1,0,0}};
int index[2][2];
int i,j,k;
int min=0;
int max=0;

	for(i=0;i<3;i++){
		min=arr[i][0];
		for(j=0;j<3;j++){
			if(min >= arr[i][j]){
				min=arr[i][j];
				index[0][0]=i;
				index[0][1]=j;
			}
		}
		
		j= index[0][1];
		max=arr[0][j];
		for(k=0;k<3;k++){
			if(max <= arr[k][j]){
				max=arr[k][j];
				index[1][0]=k;
				index[1][1]=j;
			}
		}
		if(min == max){
			if (index[0][0] == index[1][0] && index[0][1] == index[1][1]){
				printf("saddle point at (%d,%d):%d", index[0][0],index[0][1],min);
				}
			}
		}
}

