#include <iostream>
#include <unordered_map>

using namespace std;

int main(){

	unordered_map<string,int> h;

	pair<string,int> p("Sweden",2);

	h.insert(make_pair("India",145));
	h["Pakistan"] = 67;
	h.insert(p);

	cout<<h.count("China")<<endl;
	cout<<h.count("India")<<endl;

	cout<<h["India"]<<endl;

	for(auto node:h){
		cout<<node.first<<"->"<<node.second<<endl;
	}

	return 0;
}






