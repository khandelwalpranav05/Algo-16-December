#include <iostream>

using namespace std;

class Stack{
	int top;
	int *arr;
	int maxSize;
public:
	Stack(int default_size=5){
		this->maxSize = default_size;
		this->top = -1;
		this->arr = new int[this->maxSize];
	}

	void push(int data){
		if(this->top == this->maxSize - 1){
			cout<<"Stack Overflow"<<endl;
			return;
		}
		this->top++;
		this->arr[top] = data;
	}

	int size(){
		return this->top + 1;
	}

	bool isEmpty(){
		return this->top==-1;
	}

	void pop(){
		if(this->top==-1){
			cout<<"Stack is empty"<<endl;
			return;
		}

		this->top--;
	}

	int getTop(){
		return this->arr[this->top];
	}
};

int main(){

	Stack s;

	s.push(1);	
	s.push(2);	
	s.push(3);	
	s.push(4);

	cout<<s.getTop()<<endl;

	s.pop();
	s.push(12);	

	s.push(67);

	cout<<s.getTop()<<endl;

	s.pop();
	s.pop();
	s.pop();

	cout<<s.getTop()<<endl;

	return 0;
}