#include <iostream>

struct node
{
	int data;
	 node *next;
};

class HeadLinked{
private:
	node* head;
	int len;

public:
	HeadLinked();
	int sizeOf();
	void print();
	bool isContained(int x);
	bool addIfNotContained(int x);
	bool removeIfContained(int x);
};

HeadLinked::HeadLinked(){
	head = nullptr;
}
int HeadLinked::sizeOf(){
	int len = 0;
	node * curr = head;
	while(curr != nullptr){
		len++;
		curr = curr->next;
	}
	return len;
}
bool HeadLinked::isContained(int x){
	node* curr = head;

	while(curr != nullptr){
		if(curr->data == x){
			return true;
		}
		if(curr->next != nullptr)
			curr = curr->next;
		else
			break;
	}
	return false;
}

bool HeadLinked::addIfNotContained(int x){
	node* curr = head;
	// This code is duplicated from isContained to prevent having two loops
	// A loop in isContains and a loop to find the end of the list]
	while(curr != nullptr){
		if(curr->data == x){
			return false;
		}
		if(curr->next != nullptr)
			curr = curr->next;
		else
			break;
	}

	
	node* temp= new node;
	temp->data = x;
	if(head == nullptr){
		head = temp;
	}else{
		curr->next = temp;		
	}
	return true;
}

int main(){
	HeadLinked test;
	test.addIfNotContained(2);
	test.addIfNotContained(3);
	test.addIfNotContained(4);
	test.addIfNotContained(3);

	std::cout << "size: " << test.isContained(3)<< std::endl;
	return 0;
}