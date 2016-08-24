#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort (int arr[], int n){
	int i,j;
	for (i=0;i<n-1;++i){
		for (j=0;j<n-i-1;++j){
			if (arr[j] > arr[j+1]){
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

void print_sorted_array (int arr[], int n){
	int i;
    for (i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
	int arr[] = {64, 25, 12, 22, 11};
	int n = sizeof(arr)/sizeof(arr[0]);
	bubble_sort(arr, n);
	print_sorted_array(arr, n);
	return 0;
}