#include <iostream>
#include<unordered_map>	


using namespace std;

bool subarrayWithSumZero(int arr[],int n){

	unordered_map<int,int> h;

	h[0] = 0;

	int sum=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];

		if(h.count(sum)){
			return true;
		}

		h[sum] = sum;
	}

	return false;
}

int longestSubarraySumWithZero(int arr[],int n){

	unordered_map<int,int> h;

	h[0] = -1;

	int sum = 0;

	int maxLength = -1;

	for(int i=0;i<n;i++){

		sum+=arr[i];

		if(h.count(sum)){
			int abhiTakKiLength = i - h[sum];
			maxLength = max(maxLength,abhiTakKiLength);
		}else{
			h[sum] = i;
		}
	}

	return maxLength;
}

int main(){

	int arr[] = {1,2,3,-3,-2,-1};
	int n = 6;

	cout<<longestSubarraySumWithZero(arr,n)<<endl;

	return 0;
}