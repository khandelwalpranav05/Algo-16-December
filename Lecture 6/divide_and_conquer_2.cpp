#include <iostream>
#include <algorithm>

using namespace std;

bool isPossible(int arr[],int n,int mid,int k){

	int cows = 1;

	int dist = arr[0];

	for(int i=1;i<n;i++){

		if(arr[i] - dist >= mid){
			dist = arr[i];
			cows++;

			if(cows==k){
				return true;
			}
		}
	}

	return false;
}

int aggressiveCows(int arr[],int n,int cows){

	sort(arr,arr+n);

	int minDist = 1; 
	int maxDist = arr[n-1] - arr[0];

	int ans = 1;

	while(minDist<=maxDist){

		int mid = minDist + (maxDist - minDist)/2;

		if(isPossible(arr,n,mid,cows)){

			ans = mid;
			minDist = mid + 1;

		}else{

			maxDist = mid - 1;

		}

	}

	return ans;
}



int main(){

	int arr[] = {2,4,1,8,9};
	int n = 5;
	int cows = 3;

	cout<<aggressiveCows(arr,n,cows)<<endl;

	return 0;
}