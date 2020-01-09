#include <iostream>
#include<unordered_map>

using namespace std;

class node{
public:
	char data;
	bool isTerminal;
	unordered_map<char,node*> h;

	node(char data){
		this->data = data;
		this->isTerminal = false;
	}
};

class Trie{
	node* root;

public:
	Trie(){
		this->root = new node('\0');
	}

	void addWord(string word){

		node* temp = root;

		for(int i=0;i<word.length();i++){

			char ch = word[i];

			if(temp->h.count(ch)){
				temp = temp->h[ch];
			}else{
				node* child = new node(ch);
				temp->h[ch] = child;
				temp = temp->h[ch];
			}
		}

		temp->isTerminal = true;
	}

	bool search(string word){
		node* temp = root;

		for(char ch:word){
			if(temp->h.count(ch)){
				temp = temp->h[ch];
			}else{
				return false;
			}
		}

		return temp->isTerminal;
	}
};

int main(){

	Trie t;

	string pool[] = {"apple","ape","application","app","mango","news"};

	for(string word:pool){
		t.addWord(word);
	}

	string test[] = {"app","new","cape","mango"};

	for(string var:test){
		cout<<t.search(var)<<endl;
	}

	return 0;
}