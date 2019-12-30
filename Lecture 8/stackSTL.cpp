#include <iostream>
#include <stack>

using namespace std;

int main(){

	stack<int> s;

	s.push(67);
	s.push(7);
	s.pop();

	cout<<s.top()<<endl;

	cout<<s.empty()<<endl;

	return 0;
}