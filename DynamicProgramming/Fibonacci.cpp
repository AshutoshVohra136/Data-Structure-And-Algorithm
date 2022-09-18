#include<iostream>
using namespace std;


/*

DYNAMIC APPROACH

DYNAMIC APPROACH IS BASICALLY AN ITERATIVE APPROACH ANS IS BEST ONE.


int fib_DP(int n){

int *arr=new int[n+1];
 


arr[0]=0;
arr[1]=1;
for(int i=2;i<=n;i++)
arr[i]=arr[i-1]+arr[i-2];


return arr[n];

}








*/











/*

MEMOIZATION  SOLUTION

BASICALLY ITS AN TOP DOWN APPROACH 
MEMOIZATION IS AN RECURSIVE APPROACH


int fibHelper(int n,int *arr){
	if(n<=1)return n;
	
	if(arr[n]!=-1)return arr[n];
	
	int a=fibHelper(n-1,arr);
	int b=fibHelper(n-2,arr);
	arr[n]=a+b;
	return arr[n];
	
}
int fib(int n){
int *arr=new int [n+1];
for(int i=0;i<=n;i++)
arr[i]=-1;

return fibHelper( n, arr);
}

*/


int main(){

int n;
cin>>n;
cout<<fib_DP(n);

return 0;
}
