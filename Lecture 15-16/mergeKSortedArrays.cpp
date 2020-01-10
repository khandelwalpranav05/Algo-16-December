#include <iostream>
#include <queue>

using namespace std;

class ArrayPointer{
public:
	int value;
	int idx;
	int arrayNumber;

	ArrayPointer(int value,int idx,int arrayNumber){
		this->value = value;
		this->idx = idx;
		this->arrayNumber = arrayNumber;
	}
};

class ArrayCompare{
public:
	bool operator()(ArrayPointer a,ArrayPointer b){
		return a.value > b.value;
	}
};

vector<int> merge(){

	priority_queue<ArrayPointer,vector<ArrayPointer>,ArrayCompare > pq;

	vector<int> res;

	vector< vector<int> > matrix ({{1,4,7,10},
								{2,5,8},
								{3,6,9,12}});


	for(int i=0;i<3;i++){
		ArrayPointer a(matrix[i][0],0,i);
		pq.push(a);
	}

	while(pq.top().value!=INT_MAX){
		ArrayPointer smallest = pq.top();
		pq.pop();

		res.push_back(smallest.value);

		smallest.idx +=1;

		int row = smallest.arrayNumber;

		if(smallest.idx ==matrix[row].size()){
			smallest.value = INT_MAX;
			pq.push(smallest);
			continue;
		}

		smallest.value = matrix[row][smallest.idx];
		pq.push(smallest);
	}

	return res;
}

int main(){

	vector<int> result = merge();

	for(int var:result){
		cout<<var<<" ";
	}
	cout<<endl;

	return 0;
}