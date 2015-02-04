#include<iostream>
using namespace std;

int hornersRule(int *coefficientArray, int arraySize, int X){
	int result = 0;
	for(int i = arraySize - 1; i >= 0; i--)
		result = coefficientArray[i] + X * result;
	return result;
}

int main(){
	int coefficientArray[] = {1, 2, 3};
	int X = 1;
	cout << hornersRule(coefficientArray, sizeof(coefficientArray) / sizeof(int), X);
}
