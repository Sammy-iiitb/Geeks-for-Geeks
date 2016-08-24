#include <stdio.h>
#include <stdlib.h>

int binary_search (int array[], int left, int right, int number){
	//considering that the array is sorted in the ascending order
	//we don't have to sort the array and just search the element
	int middle = left + (right-1)/2;
	if (number > array[middle]) {
		return binary_search(array, middle, right, number);
	}
	if (number < array[middle]) {
		return binary_search(array, left, middle, number);
	}
	if (number == array[middle]){
		return middle;
	}
}

int main(){
	int arr[] = {2, 3, 4, 10, 40};
	int right = sizeof(arr)/sizeof(arr[0]);
	int number = 40;
	int result = binary_search (arr, 0, right-1, number);
	printf("%d\n", result);
	return 0;
}