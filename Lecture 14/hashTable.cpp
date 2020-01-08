#include <iostream>

using namespace std;

template <typename T>
class node{
public:
	string key;
	T value;
	node<T>* next;

	node(string key,T value){
		this->key = key;
		this->value = value;
		this->next = NULL;
	}
};

template <typename T>
class HashTable{
public:

	int maxSize;
	int currSize;
	node<T>** bucket;

	HashTable(int maxSize = 7){
		this->maxSize = maxSize;
		this->currSize = 0;
		this->bucket = new node<T>*[this->maxSize];

		for(int i=0;i<this->maxSize;i++){
			bucket[i] = NULL;
		}
	}

	int hashFunction(string key){
		int idx = 0;
		int mulFactor = 1;

		for(int i=0;i<key.length();i++){
			idx = idx%this->maxSize + ((key[i]%this->maxSize)*(mulFactor%this->maxSize))%this->maxSize;
			idx = idx%this->maxSize;
			mulFactor = ((mulFactor%this->maxSize)*(37%this->maxSize))%this->maxSize;
		}

		return idx%this->maxSize;
	}

	void rehash(){
		int oldSize = this->maxSize;
		node<T>** oldBucket = this->bucket;

		this->maxSize= 2*this->maxSize;
		this->bucket = new node<T>*[this->maxSize];

		for(int i=0;i<this->maxSize;i++){
			bucket[i] = NULL;
		}

		for(int i=0;i<oldSize;i++){
			node<T>* temp = oldBucket[i];

			while(temp!=NULL){
				insert(temp->key,temp->value);
				temp = temp->next;
			}
		}

		delete [] oldBucket;
	}

	void insert(string key,T value){

		float loadFactor = (float)this->currSize/this->maxSize;

		if(loadFactor>0.7){
			rehash();
		}

		int idx = hashFunction(key);

		node<T>* n = new node<T>(key,value);
		n->next = bucket[idx];
		bucket[idx] = n;
		this->currSize++;

	}

	void display(){

		for(int i=0;i<maxSize;i++){
			node<T>* temp = bucket[i];

			while(temp!=NULL){
				cout<<temp->key<<"->"<<temp->value<<" ,";
				temp = temp->next;
			}
			cout<<endl;
		}
	}

	T* search(string key){
		int idx = hashFunction(key);

		node<T>* temp = bucket[idx];

		while(temp!=NULL){
			if(key==temp->key){
				return &(temp->value);
			}
			temp = temp->next;
		}

		return NULL;
	}

	void erase(string key){

		int idx = hashFunction(key);

		node<T>* temp = bucket[idx];

		if(temp==NULL){
			cout<<"No data"<<endl;
			return;
		}

		if(temp->key == key){
			node<T>* toBeDeleted = bucket[idx];

			bucket[idx] = bucket[idx]->next;
			delete toBeDeleted;
			return;
		}

		node<T>* prev = NULL;

		while(temp!=NULL){
			if(temp->key==key){
				break;
			}
			prev = temp;
			temp = temp->next;
		}

		if(temp==NULL){
			cout<<"No Data"<<endl;
			return;
		}

		prev->next = temp->next;
		delete temp;
	}

};

int main(){

	HashTable<int> h;

	h.insert("India",142);
	h.insert("Pakistan",67);
	h.insert("Norway",3);
	h.insert("Canada",16);

	h.display();

	// int* a = h.search("India");
	// int* b = h.search("China");

	cout<<"**************************"<<endl;

	h.insert("Sweden",2);
	h.insert("North Korea",165);
	h.insert("Finland",1);

	h.display();

	cout<<"**************************"<<endl;

	h.erase("Pakistan");

	h.display();

	// cout<<*a<<endl;
	// cout<<*b<<endl;

	// int* arr = new int[3];

	// delete [] arr;

	return 0;
}