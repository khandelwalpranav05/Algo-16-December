#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>

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

		queue<T> q;
		unordered_map<T,bool> visited;

		q.push(src);
		visited[src] = true;

		while(!q.empty()){

			T node = q.front();
			q.pop();

			cout<<node<<" ";

			for(auto neighbor:adjList[node]){
				if(!visited[neighbor]){
					q.push(neighbor);
					visited[neighbor] = true;
				}
			}
		}

		cout<<endl;
	}

	void helper(T node,unordered_map<T,bool> &visited){

		cout<<node<<" ";
		visited[node] = true;

		for(T neighbor:adjList[node]){
			if(!visited[neighbor]){
				helper(neighbor,visited);
			}
		}
	}

	void dfs(T src){
		unordered_map<T,bool> visited;

		int connectComponents = 0;

		for(auto node:adjList){

			T element = node.first;

			if(!visited[element]){
				helper(element,visited);
				cout<<endl;
				connectComponents++;
			}
		}

		cout<<"Connected Components "<<connectComponents<<endl;
	}

	void dfsTopologicalSort(T src){
		
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

	// Graph<char> g;

	// g.addEgde('a','b');
	// g.addEgde('a','c');
	// g.addEgde('a','d');
	// g.addEgde('b','d');
	// g.addEgde('c','d');

	// g.display();

	Graph<int> g;

	g.addEgde(1,2);
	g.addEgde(1,4);
	g.addEgde(3,2);
	g.addEgde(3,4);
	g.addEgde(3,5);
	g.addEgde(4,5);
	g.addEgde(5,6);

	g.addEgde(7,8);
	g.addEgde(9,8);
	g.addEgde(7,9);

	g.addEgde(16,15);

	g.addEgde(17,18);


	g.display();

	g.bfs(1);

	g.dfs(1);

	return 0;
}