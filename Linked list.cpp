#include<iostream>
using namespace std;


//creating linked list class
class Node {
public:
	int data;
	Node* next;
	
	//constructor
	Node(int data) {
		this->data = data;
		this-> next = NULL;
	}
};

//insert at Head
void inserAtHead(Node* &head, int d) {
	Node* temp = new Node(d);
	temp->next = head;
	head = temp;
}

//inser at Tail

void insertAtTail(Node* &tail, int d) {
	Node* temp = new Node(d);
	tail->next = temp;
	tail = tail->next;   //tail = temp
}

void insertAtPosition(Node* &tail, Node* &head, int position, int d){
    //inser at first positon
	if (position == 1) {
		inserAtHead(head, d);
		return;
	}
	Node* temp = head;
	int cnt = 1;
	while (cnt < position - 1) {
		temp = temp->next;
		cnt++;
	}
	//insert at last position
	if (temp->next == NULL) {
		insertAtTail(tail,d);
		return;
	}
	Node* nodeToInsert = new Node(d);
	nodeToInsert->next = temp->next;
	temp->next = nodeToInsert;
}
//print function
void print(Node* &head) {
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data<<" ";
		temp = temp->next;
		cout << endl;
	}
}

//deletion in linked list

void deleteAtPosition(int position, Node* &head) {
 //deleting first node
	if (position == 1) {
		Node* temp = head;
		head = head->next;
		temp->next = NULL;
		delete temp;
	}
	//deleting node in middle and at last position
	else {
		Node* curr = head;
		Node* prev = NULL;
		int cnt = 1;
		while (cnt < position) {
			prev = curr;
			curr = curr->next;
			cnt++;
		}
		prev->next = curr->next;
		curr->next = NULL;
		delete curr;
	}
}

int main() {
	Node* node1 = new Node(15);
	Node* head = node1;
	//if one element is in linked list then head and tail points to same node
	Node* tail = node1;
	//print(head);

	inserAtHead(head, 12);
	inserAtHead(head, 10);
	//print(head);

	insertAtTail(tail, 22);
	//print(head);

	insertAtPosition(tail, head, 5, 21);

	insertAtPosition(tail, head, 6, 23);

	insertAtPosition(tail, head, 7, 223);
	insertAtPosition(tail, head, 8, 25);
	//print(head);

	//deleteAtPosition(5,head);
	
	deleteAtPosition(1,head);
	deleteAtPosition(7, head);
	//deleteAtPosition(7, head);
	print(head);
	return 0;
}