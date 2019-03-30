/**
 * Given two sorted lists, L1 and L2, write a procedure to compute L1 ∪ L2 using only the basic list operations.
 */



#include <iostream>
#include <list>

std::list<int> listUnion(const std::list<int> & l1, const std::list<int> & l2) {
	std::list<int> result;
	std::list<int>::const_iterator it1 = l1.begin();
	std::list<int>::const_iterator it2 = l2.begin();

	while (it1 != l1.end()) {
		if (it2 == l2.end() || (it2 != l2.end() && *it1 < *it2)) {
			result.push_back(*it1++);
		}
		else if (it2 != l2.end() && *it1 == *it2) {
			result.push_back(*it1++);
			it2++;
		}
		while ((it2 != l2.end() && it1 == l1.end()) || (it2 != l2.end() && *it2 < *it1)) {
			result.push_back(*it2++);
		}
	}
	return result;
}



int main() {
	std::list<int> l1 {1, 3, 5, 6, 7};
	std::list<int> l2 {2, 3, 4, 6, 8, 9};
	auto result = listUnion(l1, l2);
	std::cout << '\n' << std::endl;
	for (auto elem : result) {
		std::cout << elem << std::endl;
	}
	return 0;
}