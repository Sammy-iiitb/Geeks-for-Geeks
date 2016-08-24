#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

// this sorting is the selection sort and for the
// start and the finish arrays are sorted at once
void sort_finish_time_array (int arr_finish[], int arr_start[], int n){
	int i, j;
	for (i=0;i<n-1;i++){
		int smallest_index;
		smallest_index = i;
		for (j=i+1;j<n;j++){
			if (arr_finish[j] < arr_finish[smallest_index]){
				smallest_index = j;
			}
		}
		swap (&arr_finish[smallest_index], &arr_finish[i]);
		swap (&arr_start[smallest_index], &arr_start[i]);
	}
}

void print_sorted_array (int arr[], int n){
	int i;
    for (i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void activity_selection_algo (int arr_finish[], int arr_start[], int n){
	int i,j;
	//int final_arr[];
	int k= 0;
	printf("%d\n", k);
	int check_element = arr_finish[0];
	for (i=0;i<n-1;++i){
		int element_print;
		int finish_element = check_element;
		if (arr_start[i+1] >= finish_element){
			//final_arr[i] = i;
			element_print = i+1;
			printf("%d\n", element_print);
		}
		check_element = arr_finish[element_print];
	}
}

int main (){
	int arr_1[] = {3,1,0,8,5,5};
	int arr_2[] = {4,2,6,9,7,9};
	sort_finish_time_array (arr_2, arr_1, 6);
	print_sorted_array(arr_2, 6);
	print_sorted_array(arr_1, 6);
	activity_selection_algo (arr_2, arr_1, 6);
	return 0;
}