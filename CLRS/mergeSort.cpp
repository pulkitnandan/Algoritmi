#include<iostream>
#include<climits>
using namespace std;

void merge(int *, int, int, int);

void mergeSort(int *array, int startIndex, int endIndex){
	
	int middleIndex;
	
	if(startIndex < endIndex){
		middleIndex = (startIndex + endIndex) / 2;
		mergeSort(array, startIndex, middleIndex);
		mergeSort(array, middleIndex + 1, endIndex);
		merge(array, startIndex, middleIndex, endIndex);
	}
}

int main(){

	int array[] = {11111, 1111, 111, 11, 1};
	
	mergeSort(array, 0, sizeof(array) / sizeof(int) - 1);
	
	for(int i = 0; i < sizeof(array) / sizeof(int); i++)
		cout << array[i] << " ";		
	
	return 0;
}

void merge(int *array, int startIndex, int middleIndex, int endIndex){

	int leftListLen = middleIndex - startIndex + 1;
	int rightListLen = endIndex - middleIndex;	 
	
	int *leftList = new int[leftListLen + 1];
	int *rightList = new int[rightListLen + 1];
		
	for(int i = 0; i < leftListLen; i++)
		leftList[i] = array[startIndex + i];
	
	for(int i = 0; i < rightListLen; i++)
		rightList[i] = array[middleIndex + i + 1];
		
	leftList[leftListLen] = INT_MAX;
	rightList[rightListLen] = INT_MAX;
	
	for(int i = 0, j = 0, k = startIndex; k <= endIndex; k++)
		if(leftList[i] <= rightList[j])
			array[k] = leftList[i++];
		else array[k] = rightList[j++];
	
	delete[] leftList;
	delete[] rightList;

}
