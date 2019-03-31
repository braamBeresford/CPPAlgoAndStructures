/**
 * The Josephus problem is the following game: N people, numbered 1 to N, are sitting in a circle.
 *  Starting at person 1, a hot potato is passed. After M passes, the person holding the hot potato
 *  is eliminated, the circle closes ranks, and the game continues with the person who was sitting
 *  after the eliminated person picking up the hot potato. The last remaining person wins. Thus, if
 *  M = 0 and N = 5, players are eliminated in order, and player 5 wins. If M = 1 and N = 5, the
 *  order of elimination is 2, 4, 1, 5.
 *
 * a. Write a program to solve the Josephus problem for general values of M and N. Try to make
 * 		your program as efficient as possible. Make sure you dispose of cells.
 * b. What is the running time of your program?
 * c. If M = 1, what is the running time of your program? How is the actual speed
 * 		affected by the delete routine for large values of N (N > 100,000)?
 */

#include <iostream>
#include <list>
#include <iterator>

struct person{
	int ID;
};
int josephus(int n, int k) 
{ 
  if (n == 1) 
    return 1; 
  else{
    return (josephus(n - 1, k) + k-1) % n + 1; 

  }
} 

int josephusSim(int M, int N){
	std::list<int> people;
	for(int i = 0; i < N; i++){
		people.push_back(i+1);
	}
	
	// for(auto elem: people){
	// 	std::cout<< elem << ' ';
	// }
	// putchar('\n');
	int currPerson =0; 

	while(people.size() > 1){
		std::list<int>::iterator it = people.begin();
		currPerson += M;
		std::cout << "M: " << currPerson << " Size: " << people.size()<< "H: " << (currPerson)%people.size() << std::endl;

		std::advance(it, (currPerson%people.size()));
		// std::cout<< *it << ' ';
		people.erase(it);
	}
	for(auto elem: people){
		std::cout<< elem << ' ';
	}
	putchar('\n');
	return *people.begin();

}


int main() {
	int M=5;
	int N=1;

	std::cout<<josephusSim(M, N) << std::endl;

	std::cout<<josephus(M, N) << std::endl;
	return 0;
}