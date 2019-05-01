/**
 * You are given a list, L, and another list, P, containing integers sorted 
 * in ascending order. The operation printLots(L,P) will print the elements 
 * in L that are in positions specified by P. For instance, if P = 1, 3, 4,
 * 6, the elements in positions 1, 3, 4, and 6 in L are printed. Write the 
 * procedure printLots(L,P). You may use only the public STL container operations.
 * What is the running time of your procedure?
 */

#include <iostream>
#include <list>


// template<typename Printable>
void printLots(const std::list<int> & printed, const std::list<int> & finder){
	int printedLen = printed.size();
	std::list<int>::const_iterator it = printed.begin();
	for(auto elem: finder){
		if(printedLen <= elem){
			std::cout << "You have attempted to access an element outside the range of the list" << std::endl;
			return;
		}
		//std::next is used here instead of std::advance to avoid computing differences in indexes
		//although still slower. 
		std::cout << *std::next(it, elem) << std::endl;

	}
	return;
}

int main(){

	std::list<int> toBePrinted = {1, 4, 6, 7, 8};
	std::list<int> decision = {1,3};
	printLots(toBePrinted, decision);
	return 0;
}

