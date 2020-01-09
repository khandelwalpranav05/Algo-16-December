#include <iostream>
#include <queue>
#include <unordered_map>
#include <list>

using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

node* builtBST(node*root,int data){
	if(root==NULL){
		root = new node(data);
		return root;
	}

	if(data>root->data){
		root->right = builtBST(root->right,data);
	}else{
		root->left = builtBST(root->left,data);
	}

	return root;
}

node* insert(){

	int data;
	cin>>data;	

	node*root = NULL;

	while(data!=-1){
		root = builtBST(root,data);
		cin>>data;
	}

	return root;
}

void preorder(node* root){
	if(root==NULL){
		return;
	}

	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void inOrder(node*root){
	if(root==NULL){
		return;
	}

	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

bool search(node* root,int item){
	if(root==NULL){
		return false;
	}

	if(item==root->data){
		return true;
	}

	if(item>root->data){
		return search(root->right,item);
	}else{
		return search(root->left,item);
	}
}

bool isBST(node*root,int leftRange = INT_MIN,int rightRange=INT_MAX){
	if(root==NULL){
		return true;
	}

	bool leftBST = isBST(root->left,leftRange,root->data);
	bool rightBST = isBST(root->right,root->data,rightRange);

	if(!leftBST or !rightBST or root->data<leftRange or root->data > rightRange){
		return false;
	}else{
		return true;
	}
}

node* constructTree(){
	int data;
	cin>>data;

	if(data==-1){
		return NULL;
	}

	node*root = NULL;

	if(root==NULL){
		root = new node(data);
	}

	root->left = constructTree();
	root->right = constructTree();

	return root;
}
    
int countBST(int n){
    if(n==0){
        return 1;
    }
        
    int ans = 0;
        
    for(int i=1;i<=n;i++){
            
        int leftBST = countBST(i-1);
        int rightBST = countBST(n-i);
            
        ans +=leftBST*rightBST;
    }
        
    return ans;
}

// int countBST(int n,int dp[]){
//         if(n==0){
//             return 1;
//         }
        
//         if(dp[n]!=-1){
//             return dp[n];
//         }
        
//         int ans = 0;
        
//         for(int i=1;i<=n;i++){
            
//             int leftBST = countBST(i-1,dp);
//             int rightBST = countBST(n-i,dp);
            
//             ans +=leftBST*rightBST;
//         }
        
//         dp[n] = ans;
        
//         return ans;
//     }

int numTrees(int n) {
    return countBST(n);
}

int numTreesDP(int n) {
    int dp[n+1];
        
    dp[0] = 1;
    dp[1] = 1;
        
    for(int i=2;i<=n;i++){
        dp[i] = 0;
        for(int j=1;j<=i;j++){
            dp[i]+=dp[j-1]*dp[i-j];
        }
    }
        
    return dp[n];
}
    
void helper(node* root,int &k,int &ans){
    if(root==NULL){
        return;
    }
        
    helper(root->left,k,ans);
    k--;
    if(k==0) ans = root->data;
    helper(root->right,k,ans);
}

int kthSmallest(node* root, int k) {
    int ans = 0;
    helper(root,k,ans);
    return ans;
}

class TreeDetail{
public:
	int size;
	bool bst;
	int min;
	int max;
};

TreeDetail largestBSTinAbinaryTree(node* root){
	TreeDetail val;

	if(root==NULL){
		val.size = 0;
		val.bst = true;
		val.min = INT_MAX;
		val.max = INT_MIN;
		return val;
	}

	TreeDetail leftStatus = largestBSTinAbinaryTree(root->left);
	TreeDetail rightStatus = largestBSTinAbinaryTree(root->right);

	if(!leftStatus.bst or !rightStatus.bst or root->data > rightStatus.min or root->data < leftStatus.max){
		val.bst = false;
		val.size = max(leftStatus.size,rightStatus.size);
		return val;
	}

	val.bst = true;
	val.size = leftStatus.size + rightStatus.size + 1;

	val.min = root->left!=NULL ? leftStatus.min : root->data;
	val.max = root->right!=NULL ? rightStatus.max : root->data;

	return val;
}

node* buildTreeFromArray(int arr[],int start,int end){
	if(start>end){
		return NULL;
	}

	int mid = start + (end - start)/2;

	node* root = new node(arr[mid]);

	root->left = buildTreeFromArray(arr,start,mid-1);
	root->right = buildTreeFromArray(arr,mid+1,end);

	return root;
}

int sumReplacement(node* root){
	if(root==NULL){
		return 0;
	}

	if(root->left==NULL and root->right==NULL){
		return root->data;
	}

	int leftSum = sumReplacement(root->left);
	int rightSum = sumReplacement(root->right);

	int temp = root->data;
	root->data = leftSum + rightSum;

	return temp + root->data;
}

void serialize(node*root){
	if(root==NULL){
		cout<<(-1)<<" ";
		return;
	}

	cout<<root->data<<" ";
	serialize(root->left);
	serialize(root->right);
}

int preOrderIndex = 0;

node* builtFromPreorderInorder(int pre[],int in[],int start,int end){
	if(start==end){
		return new node(pre[preOrderIndex++]);
	}

	node* root = new node(pre[preOrderIndex]);

	int mid;

	for(int i = start;i<=end;i++){
		if(pre[preOrderIndex] == in[i]){
			mid = i;
			break;
		}
	}

	preOrderIndex++;

	root->left = builtFromPreorderInorder(pre,in,start,mid-1);
	root->right = builtFromPreorderInorder(pre,in,mid+1,end);

	return root;
}

class LinkedListPair{
public:
	node* head;
	node* tail;
};

LinkedListPair treeToLinkedList(node*root){
	LinkedListPair val;

	if(root==NULL){
		val.head = NULL;
		val.tail = NULL;
		return val;
	}

	if(root->left==NULL and root->right==NULL){
		val.head =root;
		val.tail = root;
		return val;
	}

	if(root->left!=NULL and root->right==NULL){
		LinkedListPair leftPair = treeToLinkedList(root->left);

		leftPair.tail->right = root;

		val.head = leftPair.head;
		val.tail = root;
		return val;
	}

	if(root->left==NULL and root->right!=NULL){

		LinkedListPair rightPair = treeToLinkedList(root->right);
		root->right = rightPair.head;

		val.head = root;
		val.tail = rightPair.tail;
		return val;
	}

	if(root->left!=NULL and root->right!=NULL){

		LinkedListPair leftPair = treeToLinkedList(root->left);
		LinkedListPair rightPair = treeToLinkedList(root->right);

		leftPair.tail->right = root;
		root->right = rightPair.head;

		val.head = leftPair.head;
		val.tail = rightPair.tail;
		return val;
	}
}

void levelOrder(node*root){

	queue<node*> q;

	q.push(root);

	while(!q.empty()){

		node* temp = q.front();
		q.pop();

		cout<<temp->data<<" ";

		if(temp->left){
			q.push(temp->left);
		}

		if(temp->right){
			q.push(temp->right);
		}
	}
	cout<<endl;
}

void verticalOrder(node*root,int v,int unordered_map<int,list<int> > &h){
	if(root==NULL){
		return;
	}

	h[v].push_back(root->data);

	verticalOrder(root->left,v-1,h);
	verticalOrder(root->right,v+1,h);
}

void topView(node*root){

	unordered_map<int,list<int> > h;

	verticalOrder(root,0,h);

	
}

int main(){

	// node* root = insert();

	// inOrder(root);
	// cout<<endl;

	// cout<<isBST(root)<<endl;

	node* root = NULL;
	root = constructTree();

	// levelOrder(root);

	// serialize(root);
	// cout<<endl;

	// sumReplacement(root);

	// preorder(root);
	// cout<<endl;

	// TreeDetail check = largestBSTinAbinaryTree(root);
	// cout<<check.size<<endl;

	// cout<<isBST(root)<<endl;

	// cout<<search(root,3)<<endl;
	// cout<<search(root,33)<<endl;

	// int pre[] = {4,2,1,3,6,5,7};
	// int in[] = {1,2,3,4,5,6,7};
	// int n = 7;

	// node* root = builtFromPreorderInorder(pre,in,0,n-1);

	// preorder(root);
	// cout<<endl;

	// LinkedListPair val = treeToLinkedList(root);

	// node* temp = val.head;

	// while(temp!=NULL){
	// 	cout<<temp->data<<" ";
	// 	temp = temp->right;
	// }
	// cout<<endl;

	return 0;
}

// 4 2 1 3 6 5 7 -1

// Input for largest bst in a bt
// 8 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1 9 7 -1 -1 10 -1 -1

// Input for sum replacement
// 1 2 3 -1 -1 4 5 -1 -1 6 -1 -1 9 8 -1 -1 7 -1 -1

// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1