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

	return maxSum>0 ? max(maxSum,total-minSum): maxSum;
}


// O(n^4)
int maxSubmatrixSum(int arr[2][2],int n,int m){

	int prefixSum[2][2];

	for(int i=0;i<n;i++){
		prefixSum[i][0] = arr[i][0];
		for(int j=1;j<m;j++){
			prefixSum[i][j]=prefixSum[i][j-1] + arr[i][j];
		}
	}

	for(int i=1;i<n;i++){
		for(int j=0;j<m;j++){
			prefixSum[i][j]+=prefixSum[i-1][j];
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<prefixSum[i][j]<<" ";
		}
		cout<<endl;
	}

	// TODO

	return 0;
}

int maxSubmatrixSumOptimized(int arr[2][2],int n,int m){

	int sum = 0;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){

			int start = (i+1)*(j+1);
			int end = (n-i)*(m-j);

			sum+= start*end*arr[i][j];
		}
	}

	return sum;
}

int main(){

	// int arr[] = {1,2,-3,4,-5};

	// cout<<maxSubArray(arr,5)<<endl;
	// cout<<kadanes_algo(arr,5)<<endl;

	// int arr[] = {5,-3,5};
	// cout<<maxCircularSum(arr,3)<<endl;

	int arr[2][2] = {
		{1,1},
		{1,1},
	};

	cout<<maxSubmatrixSumOptimized(arr,2,2)<<endl;

	return 0;
}