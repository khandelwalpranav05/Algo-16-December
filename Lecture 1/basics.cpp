#include <iostream>

using namespace std;

int maxSubArray(int arr[],int n){
	int maxSum = 0;

	for(int i=0;i<n;i++){

		int currSum = 0;

		for(int j=i;j<n;j++){

			currSum+=arr[j];

			if(currSum>maxSum){
				maxSum = currSum;
			}
		}
	}

	return maxSum;
}

int kadanes_algo(int arr[],int n){

	int maxSum = arr[0];
	int currSum = arr[0];

	for(int i=1;i<n;i++){

		currSum = max(currSum+arr[i],arr[i]);

		// maxSum = max(currSum,maxSum);
		if(currSum>maxSum){
			maxSum = currSum;
		}
	}

	return maxSum;
}

int maxCircularSum(int arr[],int n){

	int currMin = arr[0];
	int currMax = arr[0];
	int maxSum = arr[0];
	int minSum = arr[0];
	int total = arr[0];

	for(int i=1;i<n;i++){

		currMax = max(currMax+arr[i],arr[i]);
		maxSum = max(currMax,maxSum);

		currMin = min(currMin+arr[i],arr[i]);
		minSum = min(currMin,minSum);

		total+=arr[i];
	}

	return max(maxSum,total-minSum);

}

int main(){

	// int arr[] = {1,2,-3,4,-5};

	// cout<<maxSubArray(arr,5)<<endl;
	// cout<<kadanes_algo(arr,5)<<endl;

	int arr[] = {5,-3,5};
	cout<<maxCircularSum(arr,3)<<endl;

	return 0;
}