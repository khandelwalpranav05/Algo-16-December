#include <iostream>
#include<stack>

using namespace std;

bool balancedParanthesis(string str){

	stack<char> s;

	for(int i=0;i<str.length();i++){

		if(str[i]=='('){
			s.push(str[i]);
		}else{

			if(!s.empty() and s.top()=='('){
				s.pop();
			}else{
				return false;
			}
		}
	}

	return s.empty();
}

bool checkDuplicate(string str){

	stack<char> s;

	for(int i=0;i<str.length();i++){

		if(str[i]!=')'){
			s.push(str[i]);
		}else{

			if(s.top()=='('){
				return true;
			}

			while(s.top()!='('){
				s.pop();
			}
			s.pop();
		}
	}

	return false;
}

void stockSpan(int arr[],int n){

	stack<int> s;

	s.push(0);
	cout<<1<<" ";
	for(int i=1;i<n;i++){

		while(!s.empty() and arr[s.top()] <= arr[i]){
			s.pop();
		}

		int meriValue;

		if(s.empty()){
			meriValue = i+1;
		}else{
			meriValue = i - s.top();
		}

		cout<<meriValue<<" ";

		s.push(i);
	}
}

void nextGreater(int arr[],int n){

	stack<int> s;

	for(int i=0;i<n;i++){

		while(!s.empty() and arr[i]>arr[s.top()]){
			int idx = s.top();
			s.pop();

			cout<<arr[idx]<<"->"<<arr[i]<<endl;
		}

		s.push(i);
	}

	while(!s.empty()){
		int idx = s.top();
		s.pop();

		cout<<arr[idx]<<"->"<<(-1)<<endl;
	}
}

int main(){

	// cout<<balancedParanthesis("((()))")<<endl;

	// cout<<checkDuplicate("((a+b) + (c+d))")<<endl;

	// int arr[] = {100, 80, 60, 70, 60, 75, 85};
	// int n = 7;

	// stockSpan(arr,n);

	int arr[] = {5,3,10,2,6,13,4};
	int n = 7;

	nextGreater(arr,n);

	return 0;
}