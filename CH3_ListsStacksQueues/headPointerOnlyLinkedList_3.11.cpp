#include <iostream>

template <typename T>
struct node
{
	T data;
	node<T> *next;
};

template <typename T>
class HeadLinked{
private:
	node<T>* head;
	int len;

public:
	HeadLinked();
	T sizeOf();
	void print();
	bool isContained(T x);
	bool addIfNotContained(T x);
	bool removeIfContained(T x);
};
template <typename T>
HeadLinked<T>::HeadLinked(){
	head = nullptr;
}
template <typename T>
T HeadLinked<T>::sizeOf(){
	return this->len;
}
template <typename T>
bool HeadLinked<T>::isContained(T x){
	node<T> * curr = head;

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

template <typename T>
void HeadLinked<T>::print(){
	node<T> * curr = head;
	if(head == nullptr)
		return;
	std::cout << head->data << std::endl;
	while(curr->next != nullptr){
		std::cout << curr->data << std::endl;
		curr = curr->next;
	}
}

template <typename T>
bool HeadLinked<T>::addIfNotContained(T x){
	node<T> * curr = head;
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

	
	node<T> * temp= new node<T>;
	temp->data = x;
	if(head == nullptr){
		head = temp;
	}else{
		curr->next = temp;		
	}
	this->len++;
	return true;
}

template <typename T>
bool HeadLinked<T>::removeIfContained(T x){
	node<T> * prev = nullptr;
	node<T> * curr = head;
	if(head->data == x && head->next == nullptr){
		delete head;
		head = nullptr;
		this->len--;

		return true;
	}
	while(curr != nullptr){
		if(curr->data == x){
			if(prev == nullptr && curr->next != nullptr){
				head = curr->next;
			}
			else if (prev != nullptr && curr->next != nullptr){
				prev->next = curr->next;
			}
			this->len--;
			delete curr;
			return true;
		}

		if(curr->next == nullptr)
			break;
		prev = curr;
		curr = curr->next;
	}

	return false;

}

int main(){
	HeadLinked<int> test;
	test.addIfNotContained(2);
	test.addIfNotContained(3);
	// test.addIfNotContained(4);
	// test.addIfNotContained(3);

	// std::cout << "size: " << test.sizeOf()<< std::endl;
	test.print();
	// test.removeIfContained(2);
	// std::cout << "size: " << test.sizeOf()<< std::endl;

	return 0;
}