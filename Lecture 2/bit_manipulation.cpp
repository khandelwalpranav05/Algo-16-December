#include <iostream>

using namespace std;

void uniqueNumberPair(int arr[],int n){

	int XorPair = arr[0];

	for(int i=1;i<n;i++){
		XorPair^=arr[i];
	}

	if(XorPair==0){
		return;
	}

	int var = XorPair;

	int position = 0;

	while(true){

		if(var&1){
			break;
		}
		position++;
		var = var>>1;
	}

	int check = XorPair;

	for(int i=0;i<n;i++){

		int element = (arr[i]>>position);

		if(element&1){
			check = check^arr[i];
		}
	}

	cout<<check<<endl;
}

void uniqueNumberTriplet(int arr[],int n){

	int bitAdder[32] = {0};

	for(int i = 0;i<n;i++){

		int var = arr[i];

		for(int j=31;j>=0;j--){

			bitAdder[j]+=(var&1);
			var = var>>1;
		}
	}

	// for(int i=28;i<32;i++){
	// 	cout<<bitAdder[i]<<" ";
	// }
	// cout<<endl;

	int decimal = 0;

	int multiply = 1;

	for(int i = 31;i>=0;i--){
		bitAdder[i] = bitAdder[i]%3;

		decimal = decimal + multiply*bitAdder[i];
		multiply = multiply<<1;
	}

	cout<<"Unique value is "<<decimal<<endl;
}

int main(){

	// int arr[] = {1,2,3,4,5,7,4,3,2,1};
	// int n = 10;

	// uniqueNumberPair(arr,n);

	int arr[] = {1,1,1,2,2,2,5,5,5,4};
	int n = 10;

	uniqueNumberTriplet(arr,n);

	return 0;
}