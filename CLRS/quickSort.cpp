#include<iostream>
using namespace std;

int createPartition(int *, int, int);

void quickSort(int *array, int start, int end){
	if(start < end){
		int partition = createPartition(array, start, end);
		quickSort(array, start, partition - 1);
		quickSort(array, partition + 1, end);
	}
}

int main(){
	int array[] = {9, 4, 2, 23, 13, 34, 23, 6, 12};
	quickSort(array, 0, 8);
	for(int i = 0; i < 9; i++)
		cout << array[i] << " ";
}

void exchange(int *array, int odum, int dodum){
	int temp = array[odum];
	array[odum] = array[dodum];
	array[dodum] = temp;
}

int createPartition(int *array, int start, int end){
	int pivot = array[end];
	int index = start - 1;
	for(int i = start; i < end; i++)
		if(array[i] <= pivot){
			index++;
			exchange(array, index, i);
		}
	exchange(array, index + 1, end);
	return index + 1;
}
