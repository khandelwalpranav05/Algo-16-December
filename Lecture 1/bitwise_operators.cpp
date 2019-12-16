#include <iostream>
#include <climits>

using namespace std;

int main(){

	cout<<(5&7)<<endl;
	cout<<(5|7)<<endl;
	cout<<(5^7)<<endl;

	int n = 5;

	cout<<(n>>1)<<endl;
	cout<<(n<<1)<<endl;

	cout<<(n>>2)<<endl;
	cout<<(n<<2)<<endl;

	// cout<<(10&9)<<endl;

	int min = INT_MIN;
	int max = INT_MAX;

	cout<<"Max is "<<(max+1)<<endl;
	cout<<"Min is "<<min<<endl;

	cout<<sizeof(int)<<endl;

	long a;
	cout<<sizeof(a)<<endl;

	return 0;
}