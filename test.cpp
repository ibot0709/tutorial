#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class List{
private:
	struct Node{
		T data;
		Node* next;
		Node* prev;
		
		Node(T data, Node* next, Node* prev){
			this->data = data;
			this->next = next;
			this->prev = prev;
		}
	};
	Node* head;
	Node* curr;
	
public:
	List(){};
	void add(T data){
		Node* newNode = new Node(data, NULL, NULL);
		
		if(head == NULL){
			head = newNode;
		}
		curr = newNode;
	}
	T next(){
		curr = curr->next;
		return curr->data;
	}
	bool hasNext(){
		if(curr->next == NULL){
			return false;
		}
		return true;
	}
	T get(){ return curr->data }
};

int main(){
	
	List<int> lst;
	lst.add(1);
	lst.add(2);
	lst.add(3);
	
	while(lst.hasNext){
		cout << lst.get() << endl;
	}
	
	return 0;
}
