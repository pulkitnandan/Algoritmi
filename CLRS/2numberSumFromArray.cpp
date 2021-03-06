#include<iostream>
#include<cmath>
using namespace std;

bool binarySearchIterative(int *, int, int);

bool sumOf2Numbers(int *array, int arraySize, int sum){
	
	for(int i = 0; i < arraySize; i++){
		int remainingValue = sum - array[i];
		if(binarySearchIterative(array, arraySize, remainingValue))	{
			cout << i << " " << " Found " << endl;
			break;
		}
	}
			
}

int main(){
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
	int sum = 25;
	for(int i = 0; i < sizeof(array)/ sizeof(int); i++){
		cout << i << " ";
		for(int j = 33; j < 133; j++)
			sumOf2Numbers(array, i, j);
	}
}

bool binarySearchIterative(int *array, int arraySize, int searchNumber){
	int i = 0;
	int iterations = log2(arraySize) + 1;
	
	int start = 0;
	int end = arraySize;
	int middle;
	
	while(i++ != iterations){	
		middle = start + (end - start) / 2 ;	
		if(searchNumber == array[middle]){
			cout << " " << middle <<" ";
			return true;
		}
		else if(searchNumber < array[middle])
			end = middle;
		else start = middle ;
	}
	
	return false;
}
