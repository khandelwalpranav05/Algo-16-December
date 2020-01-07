#include <iostream>

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

int main(){

	// node* root = insert();

	// inOrder(root);
	// cout<<endl;

	// cout<<isBST(root)<<endl;

	node* root = NULL;
	root = constructTree();

	TreeDetail check = largestBSTinAbinaryTree(root);
	cout<<check.size<<endl;

	// cout<<isBST(root)<<endl;

	// cout<<search(root,3)<<endl;
	// cout<<search(root,33)<<endl;

	return 0;
}

// 4 2 1 3 6 5 7 -1

// Input for largest bst in a bt
// 8 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1 9 7 -1 -1 10 -1 -1