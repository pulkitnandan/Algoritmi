#include<iostream>
#include<climits>
using namespace std;

int *findMaximumSubarrayBruteForce(int *array, int arraySize){
	
	//Stores starting, ending index and sum of maximum subarray
	int *returnArray = new int[3];

	returnArray[2] = INT_MIN;
	
	for(int i = 0; i < arraySize; i++){
	
		int currentArraySum = array[i];
	
		for(int j = i + 1; j < arraySize; j++){
	
			currentArraySum += array[j];
	
			if(currentArraySum >= returnArray[2]){
				returnArray[0] = i;
				returnArray[1] = j;
				returnArray[2] = currentArraySum;
			}
	
		}
	
	}
	
	return returnArray;
}

int main(){
	int array[] = {-2, -3, 4, -1, -2, 1, 5, -3};

	int *returnArray = findMaximumSubarrayBruteForce(array, sizeof(array) / sizeof(int));
	
	for(int i = 0; i < 3; i++)
		cout << returnArray[i] << " ";
	
	delete[] returnArray;
	
	return 0;
}
