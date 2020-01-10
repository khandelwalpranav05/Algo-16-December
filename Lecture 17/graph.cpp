#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

template <typename T>
class Graph{

	unordered_map<T, list<T> > adjList;

public:
	void addEgde(T u,T v,bool bidir = true){
		adjList[u].push_back(v);

		if(bidir){
			adjList[v].push_back(u);
		}
	}

	void display(){
		for(auto node:adjList){

			cout<<node.first<<" -> ";

			for(T var:node.second){
				cout<<var<<" ,";
			}
			cout<<endl;
		}
	}

	void bfs(T src){
		
	}
};	


int main(){

	// Graph g;

	// g.addEgde(1,2);
	// g.addEgde(1,3);
	// g.addEgde(1,4);
	// g.addEgde(2,4);
	// g.addEgde(3,4);

	// g.display();

	Graph<char> g;

	g.addEgde('a','b');
	g.addEgde('a','c');
	g.addEgde('a','d');
	g.addEgde('b','d');
	g.addEgde('c','d');

	g.display();

	return 0;
}