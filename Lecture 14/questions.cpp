#include <iostream>
#include<unordered_map>	
#include <list>

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

int longestSubarraySumWithK(int arr[],int n,int k){

	//TODO

	return 0;
}

int verticalOrder(){

	unordered_map<int,list<int> > h;
	return 0;
}

int subarraySum(vector<int>& nums, int k) {
            
    unordered_map<int,int> h;
    int ans = 0;
    int sum = 0;
        
    h[0] = 1;
        
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
            
        if(h.count(sum - k)){
            ans+=h[sum-k];
        }
            
        h[sum]+=1;
    }
        
    return ans;
}

int main(){

	// int arr[] = {1,2,3,-3,-2,-1};
	// int n = 6;
	// cout<<longestSubarraySumWithZero(arr,n)<<endl;

	// int arr[] = {1,-1,54,-51,-1,-3};
	// int n = 6;
	// int k = -1;

	// cout<<longestSubarraySumWithK(arr,n,k)<<endl;

	return 0;
}