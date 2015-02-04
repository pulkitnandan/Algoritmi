#include<iostream>
#include<climits>
using namespace std;

int *findMaxCrossingSubarray(int *, int, int, int);

int *findMaximumSubarray(int *array, int low, int high){
	int *returnArray = new int[3];
	
	returnArray[0] = low;
	returnArray[1] = high;
	returnArray[2] = array[low];
	
	if(high == low)
		return returnArray;
	else {
		int mid = (low + high) / 2;
		
		int *leftSide = findMaximumSubarray(array, low, mid);
		int *rightSide = findMaximumSubarray(array, mid + 1, high);
		int *crossSide = findMaxCrossingSubarray(array, low, mid, high);
		
		if(leftSide[2] >= rightSide[2] && leftSide[2] >= crossSide[2]){
			delete[] rightSide;
			delete[] crossSide;
			return leftSide;
		}
		else if(rightSide[2] >= leftSide[2] && rightSide[2] >= crossSide[2]){
			delete[] leftSide;
			delete[] crossSide;
			return rightSide;
		}
		else {
			delete[] leftSide;
			delete[] rightSide;
			return crossSide;
		}
	}
}

int main(){
	int array[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	int *returnArray = findMaximumSubarray(array, 0, sizeof(array) / sizeof(int) - 1);
	
	for(int i = 0; i < 3; i++)
		cout << returnArray[i] << " ";
	
	delete[] returnArray;
	return 0;
}

int *findMaxCrossingSubarray(int *array, int low, int mid, int high){
	int leftSum, rightSum;
	int sum = 0;
	int maxLeft, maxRight;
	int *returnArray = new int[3];
	leftSum = rightSum = INT_MIN;
	
	for(int i = mid; i >= low; i--){
		sum = sum + array[i];
		if(sum > leftSum){
			leftSum = sum;
			maxLeft = i;
		}
	}
	
	sum = 0;
	
	for(int i = mid + 1; i <= high; i++){
		sum = sum + array[i];
		if(sum > rightSum){
			rightSum = sum;
			maxRight = i;
		}
	}
	
	returnArray[0] = maxLeft;
	returnArray[1] = maxRight;
	returnArray[2] = leftSum + rightSum;
	
	return returnArray;
}
