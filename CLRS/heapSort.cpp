#include<iostream>
#include<cstring>
using namespace std;

void maxHeapify(int *,int, int);

void buildMaxHeap(int *, int);

void exchange(int *, int, int);

void saveAndNullify(int *, int, int);

int heapExtractMax(int *, int);

int sortedArray[9];
int j;

void heapSort(int *array, int size){
	buildMaxHeap(array, size);
	for(int i = size - 1; i >= 0; i--){;
		saveAndNullify(array, 0, i);
		size--;
		maxHeapify(array, size, 0);
	}
}

int main(){
	int array[] = {5, 13, 1, 25, 7, 17, 20, 8, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	heapSort(array, 9);
	for(int i = 0; i < 9; i++)
		cout << sortedArray[i] << " ";
}

int heapExtractMax(int *array, int size){
	if(size < 0)
		return 0;
	int max = array[0];
	array[0] = array[size - 1];
	size--;
	maxHeapify(array, 9, 0);
	return max;
}

void saveAndNullify(int *array, int odum, int dodum){
	sortedArray[j++] = array[odum];
	array[odum] = array[dodum];
	array[dodum] = 0;

}

void exchange(int *array, int odum, int dodum){
	int temp = array[odum];
	array[odum] = array[dodum];
	array[dodum] = temp;
}

void buildMaxHeap(int *array, int size){
	for(int i = size / 2 - 1; i >= 0; i-- )
		maxHeapify(array, size -1, i);
}

void maxHeapify(int *array, int size, int index){
	int largestIndex;
	int leftIndex = 2 * index + 1;
	int rightIndex = 2 * index + 2;
	
	if(leftIndex <= size && array[leftIndex] > array[index])
		largestIndex = leftIndex;
	else largestIndex = index;
	
	
	if(rightIndex <= size && array[rightIndex] > array[largestIndex])
		largestIndex = rightIndex;
	
	if(largestIndex != index){
		exchange(array, index, largestIndex);
		maxHeapify(array, size, largestIndex);
	}
}
