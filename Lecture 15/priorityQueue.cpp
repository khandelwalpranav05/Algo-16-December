#include <iostream>
#include <queue>

using namespace std;

int main(){

	priority_queue<int,vector<int>,greater<int> > pq;

	pq.push(6);
	pq.push(4);
	pq.push(3);
	pq.push(5);
	pq.push(1);

	cout<<pq.top()<<endl;

	pq.pop();

	cout<<pq.size()<<endl;

	cout<<pq.top()<<endl;

	return 0;
}