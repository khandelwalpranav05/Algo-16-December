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

int main(){

	node* root = NULL;

	root = constructTree();

	preorder(root);
	cout<<endl;

	cout<<countNodes(root)<<endl;

	return 0;
}

// 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1