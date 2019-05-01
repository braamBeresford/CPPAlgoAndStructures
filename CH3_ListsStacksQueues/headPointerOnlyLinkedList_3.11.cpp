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

bool HeadLinked::removeIfContained(int x){
	node * prev = nullptr;
	node * curr = head;
	if(head->data == x && head->next == nullptr){
		delete head;
		head = nullptr;
		return true;
	}
	while(curr != nullptr){
		if(curr->data == x){
			if(prev == nullptr && curr->next != nullptr){
				head = curr->next;
				delete curr;
				return true;
			}
			else if (prev != nullptr && curr->next != nullptr){
				prev->next = curr->next;
				delete curr;
				return true;
			}
			else if(prev != nullptr && curr->next == nullptr){
				delete curr;
				return true;
			}
		}

		if(curr->next == nullptr)
			break;
		prev = curr;
		curr = curr->next;
	}

	return false;

}

int main(){
	HeadLinked test;
	test.addIfNotContained(2);
	// test.addIfNotContained(3);
	// test.addIfNotContained(4);
	// test.addIfNotContained(3);

	std::cout << "size: " << test.sizeOf()<< std::endl;

	test.removeIfContained(2);
	std::cout << "size: " << test.sizeOf()<< std::endl;

	return 0;
}