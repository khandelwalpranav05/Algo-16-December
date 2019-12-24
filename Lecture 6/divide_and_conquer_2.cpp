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

bool canGive(int n,int x,int m,int mid,int y){
	return mid*x <= m + (n-mid)*y;
}

int winningCBScholarship(int n,int m,int x,int y){

	int minStudent = 0;
	int maxStudent = n; 

	int ans = 0;


	while(minStudent<=maxStudent){

		int mid = minStudent + (maxStudent - minStudent)/2;

		if(canGive(n,x,m,mid,y)){
			minStudent = mid + 1;
			ans = mid;
		}else{
			maxStudent = mid - 1;
		}
	}

	return ans;
}

void merge(int arr[],int s,int e){

	int mid = s + (e-s)/2;

	int i = s;
	int j = mid + 1;

	int temp[e-s+1];
	int k =0;

	while(i<=mid and j<=e){

		if(arr[i]<=arr[j]){
			temp[k++] = arr[i++];
		}else{
			temp[k++] = arr[j++];
		}
	}

	while(i<=mid){
		temp[k++] = arr[i++];
	}

	while(j<=e){
		temp[k++] = arr[j++];
	}

	int p = 0;

	for(int x = s;x <= e;x++){
		arr[x] = temp[p];
		p++;
	}
}

void mergeSort(int arr[],int s,int e){
	if(s==e){
		return;
	}

	int mid = s + (e-s)/2;

	mergeSort(arr,s,mid);
	mergeSort(arr,mid+1,e);

	merge(arr,s,e);
}

void quickSort(int arr[],int low,int high){
	if(low>=high){
		return;
	}

	int left = low;
	int right = high;

	int mid = (low+high)/2;

	int pivot = arr[mid];

	while(left<=right){

		while(arr[left]<pivot){
			left++;
		}

		while(arr[right]>pivot){
			right--;
		}

		if(left<=right){
			swap(arr[left],arr[right]);
			left++;
			right--;
		}
	}

	for(int i=0;i<6;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl<<"****************"<<endl;

	quickSort(arr,low,right);
	quickSort(arr,left,high);
}

int main(){

	// int arr[] = {2,4,1,8,9};
	// int n = 5;
	// int cows = 3;

	// cout<<aggressiveCows(arr,n,cows)<<endl;

	// cout<<winningCBScholarship(5,10,2,1)<<endl;

	// int arr[] = {6,5,4,3,2,1};
	// int n = 6;

	// mergeSort(arr,0,n-1);

	// for(int i=0;i<n;i++){
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<endl;

	int arr[] = {10, 7, 8, 9, 1, 5};
	int n = 6;

	cout<<"BEFORE SORT"<<endl;

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	cout<<"WHILE SORTING"<<endl;

	quickSort(arr,0,n-1);

	cout<<"AFTER SORT"<<endl;

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}