#include <iostream>
#include <vector>
#include <unordered_map>

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

int reduceToOneDP(int n){

	int dp[n+1];

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	for(int i=4;i<=n;i++){

		int count1 = INT_MAX,count2 = INT_MAX,count3 = INT_MAX;

		if(i%3==0){
			count3 = dp[i/3] + 1;
		}

		if(i%2==0){
			count2 = dp[i/2] + 1;
		}

		count1 = dp[i-1] + 1;

		dp[i] = min(count1,min(count2,count3));
	}

	return dp[n];
}

// Count Board Path

int countBoardPath(int start,int end){
	if(start==end){
		return 1;
	}

	if(start>end){
		return 0;
	}

	int count = 0;

	for(int dice = 1;dice<=6;dice++){
		count+=countBoardPath(start+dice,end);
	}

	return count;
}

// Count Board Path With Memoization

int countBoardPathMemo(int start,int end,int dp[]){
	if(start==end){
		dp[start] = 1;
		return 1;
	}

	if(start>end){
		return 0;
	}

	if(dp[start]!=0){
		return dp[start];
	}

	int count = 0;

	for(int dice = 1;dice<=6;dice++){
		count+=countBoardPathMemo(start+dice,end,dp);
	}

	dp[start] = count;

	for(int i=0;i<=10;i++){
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	cout<<"****************"<<endl;

	return count;
}

// Count Board Path Pure DP

int countBoardPathDP(int start,int end){
	int dp[end + 1];

	dp[end] = 1;

	for(int i = end-1;i>=start;i--){

		dp[i] = 0;

		for(int dice = 1;dice<=6;dice++){

			if(i + dice <= end){
				dp[i]+=dp[i+dice];
			}
		}	
	}

	return dp[start];
}

// Perfect Square With Memoization
    
int perfectSquare(int n,int dp[]){
    if(n==0){
        return 0;
    }
        
    if(dp[n]!=-1){
        return dp[n];
    }
        
    int minValue = INT_MAX;
        
    for(int i=1;i*i<=n;i++){
        int abhiTakKaAnswer = perfectSquare(n - i*i,dp) + 1;
        minValue = min(minValue,abhiTakKaAnswer);
    }
        
    dp[n] = minValue;

    for(int i=1;i<=10;i++){
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	cout<<"****************"<<endl;
        
    return minValue;
}

int numSquaresMemo(int n) {
        
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
        
    return perfectSquare(n,dp);
}

// Perfect Square with Pure DP

int numSquaresDP(int n) {
        
    int dp[n+1];
        
    dp[0] = 0;
    dp[1] = 1;
        
    for(int i=2;i<=n;i++){
            
        int minValue = INT_MAX;
            
        for(int j=1;j*j<=i;j++){
            int abhiTakKaAnswer = dp[i-j*j] + 1;
            minValue = min(minValue,abhiTakKaAnswer);
        }
            
        dp[i] = minValue;
    }
        
    return dp[n];
}

// Longest Increasing Subsequence

int lengthOfLIS(vector<int>& nums) {
        
    if(nums.size()==0){
        return 0;
    }
        
    vector<int> dp(nums.size(),1);
        
    for(int i=1;i<nums.size();i++){
            
        for(int j=0;j<i;j++){
                
            if(nums[i] > nums[j]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
        
    int maxLength = dp[0];
        
    for(int i=1;i<dp.size();i++){
        maxLength = max(dp[i],maxLength);
    }
        
    return maxLength;
}

// Partition Equal Subset Sum

bool partitionEqualSumSubset(int arr[],int n,int si,int sum,int total){
	if(2*sum==total){
		return true;
	}

	if(sum>total or si>=n){
		return false;
	}



	bool include = partitionEqualSumSubset(arr,n,si+1,sum+arr[si],total);
	bool exclude = partitionEqualSumSubset(arr,n,si+1,sum,total);

	return exclude||include;
}

bool isPossible(int arr[],int n){
	int total = 0;

	for(int i=0;i<n;i++){
		total+=arr[i];
	}

	if(total&1){
		return false;
	}

	return partitionEqualSumSubset(arr,n,0,0,total);
}

// Longest Common Subsequence

int longestCommonSubsequence(string s1,string s2){
	if(s1.length()==0 or s2.length()==0){
		return 0;
	}

	char ch1 = s1[0];
	char ch2 = s2[0];

	string ros1 = s1.substr(1); 
	string ros2 = s2.substr(1);

	if(ch1==ch2){

		return 1 + longestCommonSubsequence(ros1,ros2);

	}else{

		int firstChoice = longestCommonSubsequence(s1,ros2);
		int secondChoice = longestCommonSubsequence(ros1,s2);

		return max(firstChoice,secondChoice);
	}
}

const int MAX = 100;

int dp[MAX][MAX];

int lcsMemo(string s1,string s2){
	if(s1.length()==0 or s2.length()==0){
		dp[s1.length()][s2.length()] = 0;
		return 0;
	}

	if(dp[s1.length()][s2.length()]!=-1){
		return dp[s1.length()][s2.length()];
	}

	char ch1 = s1[0];
	char ch2 = s2[0];

	string ros1 = s1.substr(1); 
	string ros2 = s2.substr(1);

	int result;

	if(ch1==ch2){

		result  = 1 + lcsMemo(ros1,ros2);

	}else{

		int firstChoice = lcsMemo(s1,ros2);
		int secondChoice = lcsMemo(ros1,s2);

		result =  max(firstChoice,secondChoice);
	}

	dp[s1.length()][s2.length()] = result;

	for(int i=0;i<=5;i++){
		for(int j=0;j<=5;j++){
			cout<<dp[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"*********************"<<endl;

	return result;
}

int lcsDP(string s1,string s2){

	int lcsStorage[s1.length() + 1][s2.length() + 1];

	for(int i=0;i<=s1.length();i++){
		lcsStorage[i][0] = 0;
	}

	for(int j=0;j<=s2.length();j++){
		lcsStorage[0][j] = 0;
	}

	for(int row = 1;row<=s1.length();row++){
		for(int col = 1;col<=s2.length();col++){

			if(s1[row-1]==s2[col-1]){

				lcsStorage[row][col] = lcsStorage[row-1][col-1] + 1;

			}else{

				lcsStorage[row][col] = max(lcsStorage[row-1][col],lcsStorage[row][col-1]);

			}

		}
	}

	return lcsStorage[s1.length()][s2.length()];
}

// Target Sum with Memoization
    
int targetSum(vector<int> nums,int si,int sum,int S,unordered_map<string,int> &h){
    string key = to_string(si) + " " + to_string(sum);
        
    if(h.count(key)){
        return h[key];
    }
        
        // cout<<key<<endl;
        
    if(si==nums.size()){
        if(sum==S){
            return 1;
        }else{
            return 0;
        }
    }   
        
    int positive = targetSum(nums,si+1,sum + nums[si],S,h);
    int negative = targetSum(nums,si+1,sum - nums[si],S,h);
        
    int total = positive + negative;
        
    h[key] = total;
        
    return total;
}

int findTargetSumWays(vector<int>& nums, int S) {
        
    unordered_map<string,int> h;
    return targetSum(nums,0,0,S,h);
}

// Distinct Subsequence (Memoization using 2D Array)

int distinctDP[6][4];

int helper(string s,int si,string t,int ti){
    if(ti==t.length()){
    	distinctDP[si][ti] = 1;
        return 1;
    }
        
    if(si==s.length()){
    	distinctDP[si][ti] = 0;
    	return 0;
    }

    if(distinctDP[si][ti]!=-1){
    	return distinctDP[si][ti];
    }
        
    int count = 0;
        
    if(s[si]==t[ti]){
        count+=helper(s,si+1,t,ti+1);
    }
    count+=helper(s,si+1,t,ti);
    
    distinctDP[si][ti] = count;

    for(int i=0;i<6;i++){
    	for(int j=0;j<4;j++){
    		cout<<distinctDP[i][j]<<"\t";
    	}
    	cout<<endl;
    }
    cout<<"*****************"<<endl;

    return count;
}

// Distinct Subsequence (Memoization using HashMap)

int distinctSubsequence(string s,int si,string t,int ti,unordered_map<string,int> &h){
    string key = to_string(si) + "->" + to_string(ti);
        
    if(h.count(key)){
        return h[key];
    }
        
    if(ti==t.length()){
        return 1;
    }
        
    if(si==s.length()){
        return 0;
    }
        
    int count = 0;
        
    if(s[si]==t[ti]){
        count+=distinctSubsequence(s,si+1,t,ti+1,h);
    }
    count+=distinctSubsequence(s,si+1,t,ti,h);
        
    h[key] = count;
        
    return count;
}

int numDistinct(string s, string t) {
        
    unordered_map<string,int> h;
    return distinctSubsequence(s,0,t,0,h);
}

// Distinct Subsequence Pure DP

int distinctSubsequenceDP(string s, string t) {
        
    long long dp[s.length()+1][t.length()+1];
        
    for(int i=0;i<=t.length();i++){
        dp[s.length()][i] = 0;
    }
        
    for(int j=0;j<=s.length();j++){
        dp[j][t.length()] = 1;
    }
        
    for(int i=s.length()-1;i>=0;i--){
        for(int j=t.length()-1;j>=0;j--){
                
            if(s[i]==t[j]){
                    
                dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
                    
            }else{
                dp[i][j] = dp[i+1][j];
            }
                
        }
    }
        
        
    return dp[0][0];
}

int knapSack(int value[],int weight[],int si,int capacity,int n){
	if(si==n){
		return 0;
	}

	int include = INT_MIN;
	int exclude = INT_MIN;

	if(weight[si]<=capacity){
		include = value[si] + knapSack(value,weight,si+1,capacity - weight[si],n);
	}

	exclude = knapSack(value,weight,si+1,capacity,n);

	int result = max(include,exclude);
	return result;
}

int knapSackDP[5][9];

int knapSackMemo(int value[],int weight[],int si,int capacity,int n){
	if(si==n){
		knapSackDP[si][capacity] = 0;
		return 0;
	}

	if(knapSackDP[si][capacity]!=-1){
		return knapSackDP[si][capacity];
	}

	int include = INT_MIN;
	int exclude = INT_MIN;

	if(weight[si]<=capacity){
		include = value[si] + knapSackMemo(value,weight,si+1,capacity - weight[si],n);
	}

	exclude = knapSackMemo(value,weight,si+1,capacity,n);

	int result = max(include,exclude);

	knapSackDP[si][capacity] = result;

	for(int i=0;i<5;i++){
		for(int j=0;j<9;j++){
			cout<<knapSackDP[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"***************************************************"<<endl;

	return result;
}

// Longest Palindromic Subsequence With Memoization
    
int helper(string str,int left,int right,vector< vector<int> > &dp){
    if(left>right){
        return 0;
    }
        
    if(left==right){
        return 1;
    }
        
    if(dp[left][right]!=-1){
        return dp[left][right];
    }
        
    char ch1 = str[left];
    char ch2 = str[right];
        
    int result;
        
    if(ch1==ch2){
            
        result = helper(str,left+1,right-1,dp) + 2;
            
    }else{
            
        int first = helper(str,left+1,right,dp);
        int second = helper(str,left,right-1,dp);
            
        result = max(first,second);
            
    }
        
    dp[left][right] = result;
        
    return result;
}

int longestPalindromeSubseq(string s) {
        
    int row = s.length();
    int col = s.length();
        
    vector< vector<int> > dp(row,vector<int> (col,-1));
        
    return helper(s,0,s.length()-1,dp);
}

// Longest Palindromic Subsequence With Pure DP

int longestPalindromeSubseqDP(string s) {
        
    int n = s.length();
        
    int dp[n][n];
        
    memset(dp,0,sizeof(dp));
        
    for(int i=0;i<n;i++){
        dp[i][i] = 1;
    }
        
    for(int col=1;col<n;col++){
        for(int row=col-1;row>=0;row--){
                
            if(s[row]==s[col]){
                dp[row][col] = dp[row+1][col-1] + 2;
            }else{
                dp[row][col] = max(dp[row][col-1],dp[row+1][col]);
            }
        }
    }
        
    return dp[0][n-1];   
}

// COIN CHANGE WITH MEMOIZATION
    
int helper(vector<int> coins,int amount,int dp[]){
    if(amount==0){
        return 0;
    }
        
    if(amount<0){
        return -1;
    }
        
    if(dp[amount]!=0){
        return dp[amount];
    }
        
    int minValue = INT_MAX;
        
    for(int coin:coins){
            
        int recursionResult = helper(coins,amount - coin,dp); 
            
        if(recursionResult >=0){
            minValue = min(minValue,recursionResult+1);
        }
    }
        
    dp[amount] = minValue==INT_MAX ? -1 : minValue;
        
    return dp[amount];
}

int coinChange(vector<int>& coins, int amount) {
        
    int dp[amount+1];
    memset(dp,0,sizeof(dp));
    return helper(coins,amount,dp);
}

// COIN CHANGE WITH PURE DP

int main(){

//*************FIBONACCI************

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

//*************REDUCE TO ONE************

	// int n = 10;
	// int dp[n+1];
	// memset(dp,-1,sizeof(dp));

	// cout<<reduceToOneMemo(n,dp)<<endl;

	// cout<<reduceToOneDP(n)<<endl;

//*************COUNT BOARD PATH************

	// int end = 10;
	// int dp[end+1];
	// memset(dp,0,sizeof(dp));
	// cout<<countBoardPathMemo(0,end,dp)<<endl;

	// int end = 10;
	// int start = 0;
	// cout<<countBoardPathDP(start,end)<<endl;

//*************PERFECT SQUARE************

	// int n = 10;
	// cout<<numSquaresMemo(n)<<endl;

	// cout<<numSquaresDP(n)<<endl;

//*************LONGEST INCREASING SUBSEQUENCE************

	// int arr[] = {3,6,2,5,7,4,10};
	// int n = 7;

	// lengthOfLIS()

//*************LEETCODE 416************
// PARTIAL EQUAL SUBET SUM

//*************LONGEST COMMON SUBSEQUENCE 1143***************

	// cout<<longestCommonSubsequence("abcdef","gahcdef")<<endl;

	// memset(dp,-1,sizeof(dp));

	// cout<<lcsMemo("bcdef","hcpef")<<endl;

	// cout<<lcsDP("bcdef","hcpef")<<endl;

//*************LEETCODE 494. Target Sum************
	// int arr[] = {1, 1, 1, 1, 1} //Convert it to vector
	// int S = 3;
	// int n = 5;

//*************LEETCODE 115. Distinct Subsequences************

	// string s = "bbaag";
	// string t = "bag";

	// memset(distinctDP,-1,sizeof(distinctDP));
	// cout<<helper(s,0,t,0)<<endl;

	// cout<<numDistinct(s,t)<<endl;

	// cout<<distinctSubsequenceDP(s,t)<<endl;

//************* KNAPSACK ******************

	// int value[] = {50,40,70,40};
	// int weight[]= {5, 4, 6, 3};
	// int capacity = 8;

	// int n = 4;

	// // cout<<knapSack(value,weight,0,capacity,n)<<endl;

	// memset(knapSackDP,-1,sizeof(knapSackDP));
	// cout<<knapSackMemo(value,weight,0,capacity,n)<<endl;

// ************ LONGEST PALINDROMIC SUBSEQUENCE 516 ***********

	// cout<<longestPalindromeSubseq("abeghebcg")<<endl;
	// cout<<longestPalindromeSubseqDP("abeghebcg")<<endl;

// ************ COIN CHANGE 322 **************

	
// ************ COUNT PALINDROMIC SUBSEQUENCE ********

	

	return 0;
}