#include<iostream>
using namespace std;

void exchange(int *, int, int);

void selectionSort(int *array, int size){
	for(int i = 0; i < size; i++){
		int smallest = i;
		for(int j = i + 1; j < size; j++)
			if(array[smallest] > array[j])
				smallest = j;
		exchange(array, smallest, i);
	}
}

int main(){
	int array[] = {9 ,8, 6, 5, 4, 3, 2, 1};
	selectionSort(array, 8);
	for(int i = 0; i < 8; i++)
		cout << array[i] << " ";
}

void exchange(int *array, int odum, int dodum){
	int temp = array[odum];
	array[odum] = array[dodum];
	array[dodum] = temp;
}
