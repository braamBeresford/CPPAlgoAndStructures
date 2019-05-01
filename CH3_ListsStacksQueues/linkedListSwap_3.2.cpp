/**
 * Swap two adjacent elements by adjusting only the links (and not the data) using 
 * 	a. singly linked lists
 * 	b. doubly linked lists
 */

#include <iostream>
#include <list>


// I decided not worth implementing a linked list for this problem.
// It is a trivial pointer manupulation problem.

//Pseudo for singly, swapping "first" and "second" block:
/*
	Store the pointer to the first block
	Store the pointer to the second block
	Store the pointer from the second to the third block
	Point the second block to the first block
	Point the first block to the third block
	Point the block originally preceding the first block to the second block

	Done
 */
