#include<iostream>
#include<climits>
#include<cmath>
using namespace std;

int main(){
	unsigned long long maxUlLong = ULONG_LONG_MAX;
	/**for(int i = 0; i < 64; i++) {
		maxUlLong = 1 << i;
		cout << i << " " << maxUlLong << endl;
	}*/
	unsigned long long a , b;
	a = b = 2;
	for(int i = 0; i < 63; i++)
		for(int j = 0; j < 63; j++)
			if(pow(2, i) - pow(2, j) == 240){
				break;
			}
			else cout << i << " " <<  j << endl;
	return 0;
}
