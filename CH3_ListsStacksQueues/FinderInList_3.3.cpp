/**
 * Implement the STL find routine that returns the iterator containing the 
 * first occur- rence of x in the range that begins at start and extends 
 * up to but not including end. If x is not found, end is returned. This
 * is a nonclass (global function) with signature
 */

#include <iostream>
#include <list>

template <typename Iterator, typename Object>
Iterator find2(Iterator start, Iterator end, const Object & x ){
	for(;start !=end; start++){
		if(*start == x)
			return start;
	}
	return end; 
}

int main(){
	std::list<int> test = {1,6,4,7,8};
	int find = 6;
	std::list<int>::iterator st= test.begin();
	std::advance(st, 2); //Should not find six since the function is given starter iterator after value
	std::list<int>::iterator en= test.end();

	auto t = find2(st, en, find);
	if(t==en){
		std::cout << "Not found!" << std::endl;
	} else {
		std::cout << "I found the thing you were looking for: " << *t << std::endl;
	}

	return 0;
}

