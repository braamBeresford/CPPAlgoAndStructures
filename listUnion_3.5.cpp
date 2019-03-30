/**
 * Given two sorted lists, L1 and L2, write a procedure to compute L1 ∪ L2 using only the basic list operations.
 */



#include <iostream>
#include <list>

std::list<int> listUnion(const std::list<int> & l1, const std::list<int> & l2) {
	std::list<int> result;
	std::list<int>::const_iterator it1 = l1.begin();
	std::list<int>::const_iterator it2 = l2.begin();

	while(it1 != l1.end() && it2 != l2.end()) {
		if (*it1 == *it2) {
			result.push_back(*it1++);
			it2++;
		} 
		else if(*it1 < *it2){
			it1++;
		}
		else if(*it2 < *it1){
			it2++;
		}
	}
	return result;
}



int main() {
	std::list<int> l1 {1, 3, 5, 7,9};
	std::list<int> l2 { 7};
	auto result = listUnion(l1, l2);
	putchar('\n');
	for (auto elem : result) {
		std::cout << elem <<  ' ';
	}
	putchar('\n');
	return 0;
}