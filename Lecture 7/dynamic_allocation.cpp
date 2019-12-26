#include <iostream>

using namespace std;

class Car{
public:
	int speed;
	int modelNumber;

	Car(){
		cout<<"Starting"<<endl;
	}

	~Car(){
		cout<<"Ending"<<endl;
	}
};

int main(){

	// int arr* = new int[3];

	// int *a = new int(30);
	// int b = 30;

	// delete a;
	// delete [] arr;

	Car c;

	Car* d = new Car();


	delete d;



	return 0;
}

// int main(){


// 	int n;
// 	cin>>n;

// 	int arr[n][n];


// 	int arr[n];


// 	return 0;
// }