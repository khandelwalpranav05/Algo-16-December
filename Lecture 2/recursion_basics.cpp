#include <iostream>

using namespace std;

int sumTilln(int n){
	if(n==1){
		return 1;
	}

	return n+sumTilln(n-1);

	// int recursionResult = sumTilln(n-1);
	// return n+recursionResult;
}

int factorial(int n){
	if(n==1){
		return 1;
	}

	int recursionResult = factorial(n-1);
	return n*recursionResult;
}

int power(int n,int p){
	if(p==0){
		return 1;
	}

	int recursionResult = power(n,p-1);
	return n*recursionResult;
}

int powerBetter(int n,int p){
	if(p==0){
		return 1;
	}

	int powern1 = powerBetter(n,p/2);

	int powerSquare = powern1*powern1;

	return p&1 ? powerSquare*n : powerSquare;
}

int main(){

	// cout<<sumTilln(5)<<endl;

	// cout<<factorial(5)<<endl;

	// cout<<power(2,10)<<endl;

	cout<<powerBetter(2,10)<<endl;

	return 0;
}