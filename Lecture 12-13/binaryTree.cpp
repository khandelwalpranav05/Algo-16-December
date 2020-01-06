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

void preorder(node* root){
	if(root==NULL){
		return;
	}

	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

int countNodes(node*root){
	if(root==NULL){
		return 0;
	}

	int leftCount = countNodes(root->left);
	int rightCount = countNodes(root->right);

	return leftCount + rightCount + 1;
}

int sumOfNodes(node*root){
	if(root==NULL){
		return 0;
	}

	int leftSum = sumOfNodes(root->left);
	int rightSum = sumOfNodes(root->right);

	return leftSum + rightSum + root->data;
}

void postOrder(node*root){
	if(root==NULL){
		return;
	}

	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
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

	if(root->data==item){
		return true;
	}

	bool leftSearch = search(root->left,item);
	bool rightSearch = search(root->right,item);

	return leftSearch or rightSearch;
}

int height(node* root){
	if(root==NULL){
		return -1;
	}

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	return max(leftHeight,rightHeight) + 1;
}

int diameter(node*root){
	if(root==NULL){
		return 0;
	}

	int leftDiameter = diameter(root->left);
	int rightDiameter = diameter(root->right);

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	int totalDiamter = max(leftHeight+rightHeight+2,max(leftDiameter,rightDiameter));
	return totalDiamter;
}

bool isBalanced(node*root){
	if(root==NULL){
		return true;
	}

	bool leftBalanced = isBalanced(root->left);
	bool rightBalanced = isBalanced(root->right);

	if(!leftBalanced or !rightBalanced){
		return false;
	}

	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	int gap = abs(leftHeight - rightHeight);

	if(gap>1){
		return false;
	}else{
		return true;
	}
}

class DiaHeight{
public:
	int height;
	int diameter;
};

DiaHeight diameterOptimized(node*root){
	DiaHeight val;
	if(root==NULL){
		val.diameter = 0;
		val.height = -1;
		return val;
	}

	DiaHeight leftPair = diameterOptimized(root->left);
	DiaHeight rightPair = diameterOptimized(root->right);

	int leftDiameter = leftPair.diameter;
	int rightDiameter = rightPair.diameter;
	int throughRoot = leftPair.height + rightPair.height + 2;

	val.diameter = max(throughRoot,max(leftDiameter,rightDiameter));

	val.height = max(leftPair.height,rightPair.height) + 1;

	return val;
}

class BalanceHeight{
public:
	int height;
	bool balance;
};

BalanceHeight isBalancedOptimized(node*root){
	BalanceHeight val;
	if(root==NULL){
		val.height = -1;
		val.balance = true;
		return val;
	}

	BalanceHeight leftPair = isBalancedOptimized(root->left);
	BalanceHeight rightPair = isBalancedOptimized(root->right);

	val.height = max(leftPair.height,rightPair.height) + 1;

	if(leftPair.balance==false or rightPair.balance==false){
		val.balance = false;
		return val;
	}

	int gap = abs(leftPair.height - rightPair.height);

	if(gap>1){
		val.balance = false;
	}else{
		val.balance = true;
	}

	return val;
}

void printRootToLeaf(node*root,string path){
	if(root==NULL){
		// cout<<path<<endl;
		return;
	}

	string val = to_string(root->data);

	if(root->left==NULL and root->right==NULL){
		path = path + val;
		cout<<path<<endl;
		return;
	}

	printRootToLeaf(root->left,path + val);
	printRootToLeaf(root->right,path + val);

}

node* lca(node* root,int data1,int data2){
	if(root==NULL){
		return NULL;
	}

	if(root->data == data1 or root->data==data2){
		return root;
	}

	node* leftLCA = lca(root->left,data1,data2);
	node* rightLCA = lca(root->right,data1,data2);

	if(leftLCA!=NULL and rightLCA!=NULL){
		return root;
	}

	if(leftLCA==NULL and rightLCA==NULL){
		return NULL;
	}

	return leftLCA!=NULL ? leftLCA : rightLCA;

}

int main(){

	node* root = NULL;

	root = constructTree();

	// preorder(root);
	// cout<<endl;

	// cout<<countNodes(root)<<endl;
	// cout<<sumOfNodes(root)<<endl;
	// cout<<search(root,2)<<endl;

	// cout<<height(root)<<endl;

	// cout<<diameter(root)<<endl;

	// cout<<isBalanced(root)<<endl;

	// DiaHeight val = diameterOptimized(root);
	// cout<<val.diameter<<endl;

	// BalanceHeight val = isBalancedOptimized(root);
	// cout<<val.balance<<endl;

	// printRootToLeaf(root,"");

	node* val = lca(root,3,6);
	cout<<val->data<<endl;
	return 0;
}

// 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1

// FOR DIAMETER TESTING
// 8 4 2 1 -1 -1 -1 3 -1 -1 5 -1 6 -1 -1
// 4 2 8 9 10 -1 -1 -1 -1 7 -1 3 -1 4 -1 6 -1 -1 5 -1 -1
// 1 -1 2 -1 3 -1 4 -1 5 -1 -1

// FOR LCA
