#include<iostream>
using namespace std;

void insertElementWithShift(int *, int, int);

void exchange(int *, int, int);

void insertionSortRecur(int *array, int arraySize){
	
	if(arraySize > 1)
		insertionSortRecur(array, arraySize - 1);
	
	int insertElement = array[arraySize - 1];
	
	for(int i = 0; i < arraySize; i++)
		if(insertElement < array[i] ){
			insertElementWithShift(array, i, arraySize);
			break;
		}
}

int main(){
	int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	insertionSortRecur(array, sizeof(array) / sizeof(int));
	
	for(int i = 0; i < sizeof(array) / sizeof(int); i++)
		cout << array[i];
}

void insertElementWithShift(int *array, int index, int arraySize){
	for(int i = index; i < arraySize - 2; i++)
		exchange(array, i, arraySize - 1);
}

void exchange(int *array, int odum, int dodum){
	int temp = array[odum];
	array[odum] = array[dodum];
	array[dodum] = temp;
}
