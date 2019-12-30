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

bool validateStackSequences(int pushed[],int n,int popped[],int m) {
        
        stack<int> s;
        int idxPop = 0;
        
        for(int i=0;i<n;i++){
            
            s.push(pushed[i]);
            while(!s.empty() and s.top()==popped[idxPop]){
                idxPop++;
                s.pop();
            }
            
        }
        
        // return s.empty();
        return idxPop==n;
}

int histogram(int arr[],int n){

	stack<int> s;

	int maxArea = INT_MIN;

	int i = 0;

	while(i<n){

		if(s.empty() or arr[i]>=arr[s.top()]){
			s.push(i);
			i++;
		}else{

			int extractTop = s.top();
			s.pop();

			int currArea;

			if(s.empty()){
				currArea = arr[extractTop]*i;
			}else{
				currArea = arr[extractTop]*(i - s.top() - 1);
			}

			maxArea = max(currArea,maxArea);

			if(s.empty()){
				cout<<"Area of height "<<arr[extractTop]<<" lying between "<<0<<" and "<<i<<endl;
				cout<<"But Max Area abhi tak "<<maxArea<<endl;
				cout<<"***************************"<<endl;
			}else{
				cout<<"Area of height "<<arr[extractTop]<<" lying between "<<(s.top()+1)<<" and "<<i<<endl;
				cout<<"But Max Area abhi tak "<<maxArea<<endl;
				cout<<"***************************"<<endl;
			}
		}
	}

	while(!s.empty()){
		int extractTop = s.top();
		s.pop();

		int currArea;

		if(s.empty()){
			currArea = arr[extractTop]*i;
		}else{
			currArea = arr[extractTop]*(i - s.top() - 1);
		}

		maxArea = max(currArea,maxArea);

		if(s.empty()){
			cout<<"Area of height "<<arr[extractTop]<<" lying between "<<0<<" and "<<i<<endl;
			cout<<"But Max Area abhi tak "<<maxArea<<endl;
			cout<<"***************************"<<endl;
		}else{
			cout<<"Area of height "<<arr[extractTop]<<" lying between "<<(s.top()+1)<<" and "<<i<<endl;
			cout<<"But Max Area abhi tak "<<maxArea<<endl;
			cout<<"***************************"<<endl;
		}
	}

	return maxArea;
}

int main(){

	// cout<<balancedParanthesis("((()))")<<endl;

	// cout<<checkDuplicate("((a+b) + (c+d))")<<endl;

	// int arr[] = {100, 80, 60, 70, 60, 75, 85};
	// int n = 7;

	// stockSpan(arr,n);

	// int arr[] = {5,3,10,2,6,13,4};
	// int n = 7;

	// nextGreater(arr,n);

	int arr[] = {2,1,2,3,1};
	int n = 5;

	cout<<histogram(arr,n)<<endl;

	return 0;
}