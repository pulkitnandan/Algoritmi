#include<iostream>
#include<cmath>
using namespace std;

bool binarySearchIterative(int *array, int arraySize, int searchNumber){
	int i = 0;
	int iterations = log2(arraySize) + 1;
	
	int start = 0;
	int end = arraySize;
	int middle;
	
	while(i++ != iterations){	
		middle = start + (end - start) / 2 ;	
		if(searchNumber == array[middle])
			return true;
		else if(searchNumber < array[middle])
			end = middle;
		else start = middle ;
	}
	
	return false;
}

bool binarySearchRecursive(int *array,int start, int end, int searchNumber){
	int middle = start + (end - start) / 2;
	if(searchNumber == array[middle])
		return true;
	else if(searchNumber < array[middle])
		end = middle;
	else start = middle;
		
	return binarySearchRecursive(array, start, end, searchNumber);
}

int main(){
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

	int i = 0;
	
	while(++i != 14)
	if(binarySearchIterative(array, sizeof(array) / sizeof(int), i))	
		cout << i <<" found" << endl;
	else cout << i << " not found" << endl;
	
	i = 0;
	
	while(++i != 14)
	if(binarySearchRecursive(array, 0, sizeof(array) / sizeof(int), 3))	
		cout << i <<" found" << endl;
	else cout << i << " not found" << endl;
}
