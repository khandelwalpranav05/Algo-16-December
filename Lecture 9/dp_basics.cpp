#include <iostream>

using namespace std;

int fib(int n){
	if(n==0 or n==1){
		return n;
	}

	return fib(n-1) + fib(n-2);
}

int fibMemo(int n,int dp[]){
	if(n==0 or n==1){
		dp[n] = n;
		return n;
	}

	if(dp[n]!=-1){
		return dp[n];
	}

	int fibn1 = fibMemo(n-1,dp);
	int fibn2 = fibMemo(n-2,dp);

	int fibn = fibn1 + fibn2;

	dp[n] = fibn;

	// for(int i=0;i<=5;i++){
	// 	cout<<dp[i]<<" ";
	// }
	// cout<<endl;
	// cout<<"*******************"<<endl;

	return fibn;
}

int fibDP(int n){

	int dp[n+1];

	dp[0] = 0;
	dp[1] = 1;

	for(int i=2;i<=n;i++){
		dp[i] = dp[i-1] + dp[i-2];
	}

	return dp[n];
}

int reduceToOne(int n){
	if(n==1){
		return 0;
	}

	int count1 = INT_MAX,count2 = INT_MAX,count3 = INT_MAX;

	if(n%3==0){
		count3 = reduceToOne(n/3) + 1;
	}

	if(n%2==0){
		count2 = reduceToOne(n/2) + 1;
	}

	count1 = reduceToOne(n-1) + 1;

	return min(count1,min(count2,count3));
}

int reduceToOneMemo(int n,int dp[]){
	if(n==1){
		dp[n] = 0;
		return 0;
	}

	if(dp[n]!=-1){
		return dp[n];
	}

	int count1 = INT_MAX,count2 = INT_MAX,count3 = INT_MAX;

	if(n%3==0){
		count3 = reduceToOneMemo(n/3,dp) + 1;
	}

	if(n%2==0){
		count2 = reduceToOneMemo(n/2,dp) + 1;
	}

	count1 = reduceToOneMemo(n-1,dp) + 1;

	dp[n] = min(count1,min(count2,count3));

	for(int i=1;i<=10;i++){
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	cout<<"****************"<<endl;

	return dp[n];
}

int main(){

	// cout<<fib(7)<<endl;

	// int n = 45;
	// int dp[n+1];

	// memset(dp,-1,sizeof(dp));

	// cout<<fibMemo(n,dp)<<endl;

	// cout<<fibDP(7)<<endl;

	// clock_t start = clock();
	// fib(n);
	// clock_t end_1 = clock();
	// fibDP(n);
	// clock_t end_2 = clock();
	// fibMemo(n,dp);
	// clock_t end_3 = clock();
	
	// cout<<"Recursion took "<<(end_1 - start)<<endl;
	// cout<<"DP took "<<(end_2 - end_1)<<endl;
	// cout<<"Memoization took "<<(end_3 - end_2)<<endl;

	int n = 10;
	int dp[n+1];
	memset(dp,-1,sizeof(dp));

	cout<<reduceToOneMemo(n,dp)<<endl;

	return 0;
}