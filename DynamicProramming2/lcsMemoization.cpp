#include<iostream>
using namespace std;
int helper(string s,string t,int**output){
		int m=s.size(),n=t.size(),z;
	if(s.size()==0||t.size()==0)return 0;
	if(output[m][n]!=-1)return output[m][n];
	//RECURSIVE CALLS
	if(s[0]==t[0])
 z= 1+helper(s.substr(1),t.substr(1),output);
else{
	int a=helper(s.substr(1),t,output);
	int b=helper(s,t.substr(1),output);
	int c=helper(s.substr(1),t.substr(1),output);
 z= max(a,max(c,b));
}	
	
	output[m][n]=z;

	
	return z;
}
int lcsMemoization(string s,string t){
	int m=s.size(),n=t.size();
	int **output=new int*[m+1];
	for(int i=0;i<=m;i++){
		output[i]=new int[n+1];
		for(int j=0;j<=n;j++){
			
			output[i][j]=-1;
		}
	}
	int ans=helper(s,t,output);	
	for(int i=0;i<=m;i++)
	delete [] output[i];	// DELETING INNER ARRAY
	delete [] output;   //DELETING OUTER ARRAY
	
return ans;
}
int main(){

	string s="bch",t="abch";
	cout<<lcsMemoization(s,t)<<endl;
	 
}
