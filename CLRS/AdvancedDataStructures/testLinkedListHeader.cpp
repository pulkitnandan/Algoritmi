#include <iostream>

using namespace std;
#include "linkedListDisjointSet.h"

int main(void){
	
	List<int> list;
	
	list.push_back(3);
	list.push_back(4);
	list.push_back(4);
	list.push_front(5);
	list.push_front(4);
	list.push_front(3);
	list.push_front(2);
	list.push_front(1);
	
	/*Print all elements*/
	for (List<int>::iterator iter = list.begin();
	     iter != list.end(); ++iter)
	{	
		std::cout << (*iter) << std::endl;
	}

	cout << endl;	
	
	/*Delete second element and reprint*/
	List<int>::iterator tmp = list.begin() + 1;
	
	list.erase(tmp);

	for (List<int>::iterator iter = list.begin();
	     iter != list.end(); ++iter)
	{	
		std::cout << (*iter) << std::endl;
	}
	
	cout << endl;
	
	/*Now delete first node and print again*/
	tmp = list.begin();
	list.erase(tmp);
	for (List<int>::iterator iter = list.begin();
	     iter != list.end(); ++iter)
	{
		std::cout << (*iter) << std::endl;
	}
	
	return 0;	
}
