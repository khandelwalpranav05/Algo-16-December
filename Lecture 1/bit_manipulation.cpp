#include <iostream>

using namespace std;

int uniqueNumber(int arr[],int n){

	//TODO

}

int countSetBits(int n){

	int temp = 0;

	while(n!=0){

		temp += (n&1);

		n = n>>1;
	}

	return temp;
}

int floorJumps(int n){
	return countSetBits(n);
}

int main(){

	cout<<floorJumps(13)<<endl;
	return 0;
}