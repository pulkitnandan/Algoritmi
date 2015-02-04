#include<iostream>
#include<climits>
using namespace std;

void conquer(int *, int, int, int);

void divide(int *array, int startIndex, int endIndex){
	int middleIndex;
	if(startIndex < endIndex){
		middleIndex = (startIndex + endIndex) / 2;
		divide(array, startIndex, middleIndex);
		divide(array, middleIndex + 1, endIndex);
		conquer(array, startIndex, middleIndex, endIndex);
	}
}

int inversions = 0;

int main(){

	int array[] = {1, 11, 111, 1111, 11111};
	divide(array, 0, sizeof(array) / sizeof(int) - 1);
	
	cout << inversions;		
}

void conquer(int *array, int startIndex, int middleIndex, int endIndex){

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
	
	for(int i = 0; i < leftListLen; i++)
		for(int j = 0; j < rightListLen; j++)
			if(leftList[i] < rightList[j])
				inversions++;
}
