#include<iostream>
#include<climits>
using namespace std;

//Not for all negative no.s in array
int *findMaximumSubarrayKadane(int *array, int arraySize){
	
	int maxSoFar = 0, maxEndingHere = 0;
	
	//Stores starting, ending index and sum of maximum subarray
	int *returnArray = new int[3];

	returnArray[2] = INT_MIN;
	
	for(int i = 0; i < arraySize; i++){
	
		maxEndingHere += array[i];
		
		if(maxEndingHere < 0){
			maxEndingHere = 0;
			returnArray[0] = i + 1;
		}
			
		if(maxSoFar < maxEndingHere){
			returnArray[1] = i;
			returnArray[2] = maxEndingHere;
			maxSoFar = maxEndingHere;
		}
	
	}
	
	return returnArray;
}

int main(){
	int array[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};

	int *returnArray = findMaximumSubarrayKadane(array, sizeof(array) / sizeof(int));
	
	for(int i = 0; i < 3; i++)
		cout << returnArray[i] << " ";
}
