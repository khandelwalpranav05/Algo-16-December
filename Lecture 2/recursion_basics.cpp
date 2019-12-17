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

bool isSorted(int arr[],int n,int si){
	if(si==n-1){
		return true;
	}

	if(arr[si] > arr[si+1]){
		return false;
	}

	bool rest_of_the_array = isSorted(arr,n,si+1);
	return rest_of_the_array;
}

int linearSearch(int arr[],int n,int si,int data){
	if(si==n){
		return -1;
	}

	if(arr[si]==data){
		return si;
	}

	return linearSearch(arr,n,si+1,data);
}

int fibonacci(int n){
	if(n==1 or n==0){
		return n;
	}

	int fibn1 = fibonacci(n-1);
	int fibn2 = fibonacci(n-2);

	return fibn2+fibn1;
}

int pairingProblem(int n){
	if(n==1 or n==2){
		return n;
	}

	int stag = pairingProblem(n-1);
	int pair = pairingProblem(n-2);

	return stag + pair*(n-1);
}

int countBoardPath(int start,int end){
	if(start==end){
		return 1;
	}

	if(start>end){
		return 0;
	}

	int count = 0;

	for(int dice = 1;dice<=6;dice++){
		count+=countBoardPath(start+dice,end);
	}

	return count;
}

int countMazePath(int sr,int sc,int er,int ec){
	if(sr==er and sc==ec){
		return 1;
	}

	if(sr>er or sc>ec){
		return 0;
	}

	int count = 0;

	int vertical = countMazePath(sr+1,sc,er,ec);
	int horizontal = countMazePath(sr,sc+1,er,ec);

	count = horizontal + vertical;
	return count;
}

string replacePi(string str){
	if(str.length()==0){
		return "";
		// return str;
	}

	char ch = str[0];
	string ros = str.substr(1);

	string recursionResult = replacePi(ros);

	if(ch=='p' and recursionResult[0]=='i'){
		return "3.14" + recursionResult.substr(1);
	}else{
		return ch+recursionResult;
	}
}

int main(){

	// cout<<sumTilln(5)<<endl;

	// cout<<factorial(5)<<endl;

	// cout<<power(2,10)<<endl;

	// cout<<powerBetter(2,10)<<endl;

	// int arr[] = {1,2,4,3,5,6};
	// cout<<isSorted(arr,6,0)<<endl;
	// cout<<linearSearch(arr,6,0,89)<<endl;

	// cout<<pairingProblem(3)<<endl;

	// cout<<countBoardPath(0,3)<<endl;

	// auto a = 20;

	// cout<<countMazePath(0,0,2,2)<<endl;

	cout<<replacePi("xxpixxipixx")<<endl;

	return 0;
}