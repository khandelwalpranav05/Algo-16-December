#include <iostream>

using namespace std;

string moveAllXToEnd(string str){
	if(str.length()==0){
		return "";
	}

	char ch = str[0];
	string ros = str.substr(1);

	string recursionResult = moveAllXToEnd(ros);

	if(ch=='x'){
		return recursionResult + ch;
	}else{
		return ch+recursionResult;
	}
}

int p = 0;

void printSubsequence(string str,string ans){
	if(str.length()==0){
		// cout<<"print"<<endl;
		cout<<ans<<endl;
		p++;
		return;
	}

	char ch = str[0];
	string ros = str.substr(1);

	printSubsequence(ros,ans);
	printSubsequence(ros,ans+ch);

}

void printPermutations(string str,string ans){
	if(str.length()==0){
		cout<<ans<<endl;
		return;
	}

	for(int i=0;i<str.length();i++){
		char ch = str[i];

		string ros = str.substr(0,i) + str.substr(i+1);
		printPermutations(ros,ans+ch);
	}
}

void mappedString(string str,string ans){
	if(str.length()==0){
		cout<<ans<<endl;
		return;
	}

	char ch1 = str[0];
	string ros = str.substr(1);

	int ch1_int = ch1 - '0';

	ch1 = ch1 - '0' + 'A' - 1;

	mappedString(ros,ans + ch1);

	if(ros.length()>0){

		char ch2 = str[1];
		int ch2_int = ch2 - '0';

		int second_num = ch1_int*10 + ch2_int;

		if(second_num < 27){
			ch2 = second_num + 'A' - 1;
			string ros2 = str.substr(2);

			mappedString(ros2,ans+ch2);
		}
	}

}

string keycode[] = {".","#","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};


int main(){

	// cout<<moveAllXToEnd("xxxkjfxxxoe")<<endl;
	// cout<<moveAllXToEnd("abcdxxxbght")<<endl;

	// printSubsequence("abc","");
	// cout<<"Number of Subsequence "<<p<<endl;

	// printPermutations("abc","");

	// char a = 'A';

	// a= a +1;

	// cout<<(a)<<endl;

	mappedString("1234","");

	return 0;
}