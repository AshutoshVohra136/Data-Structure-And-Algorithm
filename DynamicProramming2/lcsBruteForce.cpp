#include<iostream>
using namespace std;

int lcsBruteForce(string s,string t){
	if(s.size()==0||t.size()==0)return 0;
	//RECURSIVE CALLS
	if(s[0]==t[0])
return 1+	lcsBruteForce(s.substr(1),t);
else{
	int a=lcsBruteForce(s.substr(1),t);
	int b=lcsBruteForce(s,t.substr(1));
	int c=lcsBruteForce(s.substr(1),t.substr(1));
	return max(a,max(c,b));
}
}
int main(){

	string s="xyz",t="zxay";
	cout<<lcsBruteForce(s,t)<<endl;
	 
}
