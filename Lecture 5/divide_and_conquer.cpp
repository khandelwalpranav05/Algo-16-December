#include <iostream>

using namespace std;

int binarySearch(int arr[],int n,int data){

	int start = 0;
	int end = n-1;

	while(start<=end){

		int mid = (start + end)/2;

		if(arr[mid]==data){
			return mid;
		}else if(arr[mid] > data){
			end = mid - 1;
		}else{
			start = mid + 1;
		}
	}

	return -1;
}

int lowerBound(int arr[],int n,int data){

	int start = 0;
	int end = n-1;

	int ans = -1;

	while(start<=end){

		int mid = (start + end)/2;

		if(arr[mid]==data){

			ans = mid;
			end = mid - 1;
			// start = mid+1;
		}else if(arr[mid] > data){

			end = mid - 1;

		}else{

			start = mid + 1;

		}
	}

	return ans;

}

int upperBound(int arr[],int n,int data){

	int start = 0;
	int end = n-1;

	int ans = -1;

	while(start<=end){

		int mid = (start + end)/2;

		if(arr[mid]==data){

			ans = mid;
			start = mid+1;
		}else if(arr[mid] > data){

			end = mid - 1;

		}else{

			start = mid + 1;

		}
	}

	return ans;
}

bool isPerfectSquare(int n){

	int start = 1;
	int end = n;

	while(start<=end){
		int mid = (start+end)/2;

		if(mid*mid==n){
			return true;
		}else if(mid*mid > n){

			start = mid + 1;

		}else{

			end = mid - 1;

		}
	}

	return false;
}

int searchRotatedArray(int arr[],int start,int end,int data){
	if(start>end){
		return -1;
	}

	int mid = start+(end-start)/2;

	if(arr[mid]==data){
		return mid;
	}

	if(arr[start]<=arr[mid]){

		if(arr[start]<=data and data<arr[mid]){
			return searchRotatedArray(arr,start,mid-1,data);
		}else{
			return searchRotatedArray(arr,mid+1,end,data);
		}

	}else{

		if(arr[mid] < data and data <=arr[end]){

			return searchRotatedArray(arr,mid+1,end,data);

		}else{
			return searchRotatedArray(arr,start,mid-1,data);
		}
	}
}

int uniqueNumber(int arr[],int start,int end){
	if(start>end){
		return -1;
	}

	int mid = start + (end - start)/2;

	if(arr[mid-1]!=arr[mid] and arr[mid]!=arr[mid+1]){
		return arr[mid];
	}

	if(arr[mid]==arr[mid+1]){
		int dist = mid - start;

		if(dist&1){
			return uniqueNumber(arr,start,mid-1);
		}else{
			return uniqueNumber(arr,mid+2,end);
		}
	}

	if(arr[mid]==arr[mid-1]){
		int dist = mid - start + 1;

		if(dist&1){
			return uniqueNumber(arr,start,mid-2);
		}else{
			return uniqueNumber(arr,mid+1,end);
		}
	}
}

int main(){

	// int arr[] = {1,2,3,56,78,90,110};
	// int n = 7;
	// cout<<binarySearch(arr,n,56)<<endl;

	// int arr[] = {1,2,2,2,2,2,3,3};
	// int n = 8;

	// cout<<lowerBound(arr,n,2)<<endl;
	// cout<<upperBound(arr,n,2)<<endl;

	// int arr[] = {6,7,1,2,3,4,5};
	// int n = 7;
	
	// cout<<searchRotatedArray(arr,0,n-1,6)<<endl;
	// cout<<searchRotatedArray(arr,0,n-1,4)<<endl;

	// int arr[] = {1,1,2,2,4,4,5,5,6,6};
	// int n = 11;
	// cout<<uniqueNumber(arr,0,9)<<endl;

	return 0;
}