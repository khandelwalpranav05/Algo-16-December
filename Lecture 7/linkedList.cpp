#include <iostream>

using namespace std;

class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		this->next = NULL;
	}
};

void insertAtHead(node*&head,int data){
	node *n = new node(data);
	n->next = head;
	head = n;
}

void display(node*head){

	node* temp = head;

	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}

	cout<<endl;
}

int length(node* head){

	int len = 0;

	node* temp = head;

	while(temp!=NULL){
		len++;
		temp = temp->next;
	}

	return len;
}

void insertAtTail(node*&head,int data){
	if(head==NULL){
		insertAtHead(head,data);
		return;
	}

	node* temp = head;

	while(temp->next!=NULL){
		temp = temp->next;
	}

	node* n = new node(data);
	temp->next = n;
}

void insertAtIndex(node*&head,int data,int idx){
	if(idx<=1){
		insertAtHead(head,data);
		return;
	}

	if(idx >= length(head)){
		insertAtTail(head,data);
		return;
	}

	node* temp = head;

	int steps = 1;

	while(steps<idx-1){
		steps++;
		temp=temp->next;
	}

	node* n= new node(data);

	n->next = temp->next;
	temp->next = n;
}

void deleteAtHead(node*&head){
	if(head==NULL){
		return;
	}

	node* temp = head;
	head = head->next;
	delete temp;
}

void deleteAtTail(node*&head){
	if(head==NULL){
		return;
	}

	if(head->next==NULL){
		deleteAtHead(head);
	}

	node* temp = head;

	while(temp->next->next!=NULL){
		temp=temp->next;
	}

	node* toBeDeleted = temp->next;
	temp->next = NULL;
	delete toBeDeleted;
}

void deleteAtIndex(node*head,int idx){
	if(idx<=1){
		deleteAtHead(head);
		return;
	}

	if(idx>=length(head)){
		deleteAtTail(head);
		return;
	}

	node* temp = head;

	int steps = 1;

	while(steps<idx-1){
		steps++;
		temp=temp->next;
	}

	node* toBeDeleted = temp->next;

	temp->next = temp->next->next;
	delete toBeDeleted;

}

node* reverseRecursive(node*head){
	if(head==NULL or head->next==NULL){
		return head;
	}

	node* newHead = reverseRecursive(head->next);
	node* currentHead = head;

	currentHead->next->next = currentHead;
	currentHead->next = NULL;
	return newHead;
}

bool searchRecursive(node* head,int data){
	if(head==NULL){
		return false;
	}

	if(head->data!=data){
		return true;
	}else{
		return searchRecursive(head->next,data);
	}
}

node* midPoint(node*head){

	node* slow = head;
	node* fast = head;

	while(fast->next!=NULL and fast->next->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

void reverseIterative(node*&head){

	node* curr = head;
	node* prev = NULL;

	while(curr!=NULL){
		node* n = curr->next;
		curr->next = prev;

		prev = curr;
		curr = n;
	}

	head = prev;
}

node* merge(node* a,node* b){
	if(a==NULL){
		return b;
	}

	if(b==NULL){
		return a;
	}

	node* c;

	if(a->data <= b->data){

		c = a;
		c->next = merge(a->next,b);

	}else{

		c = b;
		c->next = merge(a,b->next);
	}

	return c;
}

node* mergeSort(node* head){
	if(head==NULL or head->next==NULL){
		return head;
	}

	node* mid = midPoint(head);

	node* a = head;
	node* b = mid->next;

	mid->next = NULL;

	a = mergeSort(a);
	b = mergeSort(b);

	node* c = merge(a,b);

	return c;
}

node* kReverse(node* head,int k){
	if(head==NULL or head->next==NULL){
		return head;
	}

	node* curr = head;
	node* prev = NULL;

	int count = 1;

	while(count<=k and curr!=NULL){
		node* n = curr->next;
		curr->next = prev;

		prev = curr;
		curr = n;
		count++;
	}

	head->next = kReverse(curr,k);

	return prev;
}

int main(){

	node* head = NULL;

	insertAtHead(head,10);
	insertAtHead(head,20);
	insertAtHead(head,30);
	insertAtHead(head,40);

	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtTail(head,4);

	insertAtIndex(head,890,5);

	display(head);

	head = mergeSort(head);

	display(head);

	head = kReverse(head,3);

	display(head);

	// deleteAtHead(head);

	// display(head);

	// deleteAtTail(head);

	// display(head);

	// deleteAtIndex(head,4);

	// display(head);

	// head= reverseRecursive(head);

	// display(head);

	// reverseIterative(head);

	// display(head);


	// deleteAtTail(head);

	// display(head);
	// node* mid = midPoint(head);

	// cout<<mid->data<<endl;

	// cout<<searchRecursive(head,30)<<endl;
	// cout<<searchRecursive(head,38)<<endl;

	// cout<<length(head)<<endl;

	// node* head1 = NULL;
	// insertAtTail(head1,1);
	// insertAtTail(head1,3);
	// insertAtTail(head1,5);
	// insertAtTail(head1,7);
	// insertAtTail(head1,8);
	// insertAtTail(head1,10);

	// node* head2 = NULL;
	// insertAtTail(head2,2);
	// insertAtTail(head2,4);
	// insertAtTail(head2,6);
	
	// node* mergesList = merge(head1,head2);
	// display(mergesList);
	return 0;
}