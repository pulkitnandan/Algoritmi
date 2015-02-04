#include<iostream>
using namespace std;


void insertionSort(int *array, int arraySize){
	for(int i = 1; i < arraySize; i++){
		int key = array[i];
		int j = i - 1;
		while(j >= 0 && array[j] > key){
			array[j + 1] = array[j];
			j--;
		}
		array[++j] = key;
	}
}

int main(){
	int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	insertionSort(array, sizeof(array) / sizeof(int));
	
	for(int i = 0; i < sizeof(array) / sizeof(int); i++)
		cout << array[i];
}
