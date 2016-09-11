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
		
		Node(T data, Node* prev, Node* next){
			this->data = data;
			this->prev = prev;
			this->next = next;
		}
	};
	Node* head = NULL;
	Node* curr = NULL;
	
public:
	List(){};
	void add(T data){
		Node* newNode;
		if(head == NULL){
			newNode = new Node(data, NULL, NULL);
			head = newNode;
			curr = newNode;
			return;
		}
		newNode = new Node(data, curr, NULL);
		curr->next = newNode;
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
	T get(){
		return curr->data;
	}
	void init(){
		curr = head;
	}
};

int main(){
	
	List<int> lst;
	lst.add(1);
	lst.add(2);
	lst.add(3);
	lst.init();
	
	while(lst.hasNext()){
		cout << lst.get() << endl;
		lst.next();
	}
	
	return 0;
}
