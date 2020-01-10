#include <iostream>
#include <math.h>

using namespace std;

class node{
public:
	node* left;
	node* right;

	node(){
		this->left = NULL;
		this->right = NULL;
	}
};

void insert(node* root,int val){

	for(int i=31;i>=0;i--){

		int bit = (val>>i)&1;

		if(bit){

			if(!root->right){
				node* child= new node();
				root->right = child;
			}

			root = root->right;

		}else{

			if(!root->left){
				node* child= new node();
				root->left = child;
			}

			root = root->left;
		}
	}
}

int maxXor(int arr[],int n,node* head){

	int maxValue = INT_MIN;

	for(int i=0;i<n;i++){

		node* root = head;

		int val = arr[i];

		int currXor = 0;

		for(int j=31;j>=0;j--){

			int bit = (val>>j)&1;

			if(bit){

				if(root->left){
					currXor+=pow(2,j);
					root=root->left;
				}else{
					root = root->right;
				}

			}else{
				if(root->right){
					currXor+=pow(2,j);
					root=root->right;
				}else{
					root = root->left;
				}
			}
		}

		maxValue = max(maxValue,currXor);
	}

	return maxValue;
}

int main(){


	int arr[] = {25, 10, 2, 8, 5, 3};
	int n = 6;

	node* root = new node();

	for(int i=0;i<n;i++){
		insert(root,arr[i]);
	}

	cout<<maxXor(arr,n,root)<<endl;

	return 0;
}