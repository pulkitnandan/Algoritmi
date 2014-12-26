#include<iostream>
using namespace std;

void exchange(int *, int, int);

void bubbleSort(int *array, int arraySize){
	for(int i = 0; i < arraySize; i++)
		for(int j = arraySize - 1; j > i; j--)
			if(array[j] < array[j - 1])
				exchange(array, j, j - 1);
}	

int main(){
	int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	bubbleSort(array, sizeof(array) / sizeof(int));
	
	for(int i = 0; i < sizeof(array) / sizeof(int); i++)
		cout << array[i];
}

void exchange(int *array, int odum, int dodum){
	int temp = array[odum];
	array[odum] = array[dodum];
	array[dodum] = temp;
}
