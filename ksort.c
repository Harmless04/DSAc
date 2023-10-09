#include <limits.h>
#include <stdio.h>

int partition(int arr[], int l, int r);

int kthSmallest(int arr[], int l, int r, int K)
{

	if (K > 0 && K <= r - l + 1) {

		
		int pos = partition(arr, l, r);

		
		if (pos - l == K - 1)
			return arr[pos];
		if (pos - l > K - 1) 
			return kthSmallest(arr, l, pos - 1, K);
	
		
		return kthSmallest(arr, pos + 1, r,
						K - pos + l - 1);
	}
return INT_MAX;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int arr[], int l, int r)
{
	int x = arr[r], i = l;
	for (int j = l; j <= r - 1; j++) {
		if (arr[j] <= x) {
			swap(&arr[i], &arr[j]);
			i++;
		}
	}

	swap(&arr[i], &arr[r]);
	return i;
}
int main()
{
	int arr[] = { 12, 3, 5, 7, 4, 19, 26 };
	int N = sizeof(arr) / sizeof(arr[0]), K = 3;

	// Function call
	printf("K'th smallest element is %d",
		kthSmallest(arr, 0, N - 1, K));
	return 0;
}

