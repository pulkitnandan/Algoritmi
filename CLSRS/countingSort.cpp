#include<iostream>
using namespace std;

void countingSort(int *array, int size, int *auxArray, int limit){
	int *countingArray = new int[limit + 1];
	
	for(int i = 0; i <= limit; i++)
		countingArray[i] = 0;
		
	for(int i = 0; i < size; i++)
		countingArray[array[i]]++;
		
		
		for(int i = 0; i <= limit; i++)
			cout << i << " " << countingArray[i] << " " << endl;
		
		cout << endl;
		
	for(int i = 1; i <= limit; i++)
		countingArray[i] += countingArray[i - 1];
	
		for(int i = 0; i <= limit; i++)
			cout << i << " " << countingArray[i] << " " << endl;
		
	for(int i = size - 1; i >= 0; i--){
		auxArray[countingArray[array[i]]] = array[i];
		countingArray[array[i]] = countingArray[array[i]] - 1;
	}
}

int main(){
	int array[] = {5, 13, 1, 25, 7, 17, 20, 8, 20};
	int sortedArray[9] = {0};
	countingSort(array, 9, sortedArray, 40);
	for(int i = 0; i < 9; i++)
		cout << sortedArray[i] << " ";
	
	return 0;
}
