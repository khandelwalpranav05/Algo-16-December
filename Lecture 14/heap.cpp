#include <iostream>
#include <vector>

using namespace std;

void upheapify(vector<int> &v,int idx){
	if(idx==0) return;

	int parentIdx = (idx - 1)/2;

	if(v[parentIdx] < v[idx]){
		swap(v[parentIdx],v[idx]);
		upheapify(v,parentIdx);
	}
}

void insert(vector<int> &v,int data){

	v.push_back(data);
	int idx = v.size() - 1;
	upheapify(v,idx);
}

void display(vector<int> v){

	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

void downHeapify(vector<int> &v,int idx){
	int leftChild = idx*2 + 1;
	int rightChild = idx*2 + 2;

	if(leftChild>=v.size() and rightChild>=v.size()){
		return;
	}

	int largestIdx = idx;

	if(leftChild<v.size() and v[leftChild]>v[largestIdx]){
		largestIdx = leftChild;	
	}

	if(rightChild<v.size() and v[rightChild]>v[largestIdx]){
		largestIdx = rightChild;
	}

	if(largestIdx==idx){
		return;
	}

	swap(v[largestIdx],v[idx]);
	downHeapify(v,largestIdx);
}

int erase(vector<int> &v){
	int n = v.size() - 1;
	swap(v[0],v[n]);

	int temp = v[n];
	v.pop_back();

	downHeapify(v,0);

	return temp;
}

int eraseAtAnyIndex(vector<int> &v,int idx){

	int temp = v[idx];
	int n = v.size() - 1;
	swap(v[idx],v[n]);

	v.pop_back();

	downHeapify(v,idx);

	return temp;
}

int main(){

	vector<int> v({40,30,20,25,17,19});

	insert(v,50);

	display(v);

	eraseAtAnyIndex(v,1);

	display(v);

	return 0;
}