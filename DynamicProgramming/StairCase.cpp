#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int stairCaseDP(int n){
	
int *arr=new int[n+1];
arr[0]=1;
arr[1]=1;
arr[2]=2;


	for(int i=3;i<=n;i++)
	arr[i]=arr[i-1]+arr[i-2]+arr[i-3];
	int answer=arr[n];
	delete []arr;
	return answer;
}
int main(){
	int n;											
	cin>>n;
cout<<stairCaseDP(n);
	
}


/*


BRUTE FORCE

int staircase(int n){
   
   Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     
    
    // 
   
    if(n<=0)return 1;
    
    int x=staircase(n-1);
   
   	int	y=staircase(n-2);
    
       int z=staircase(n-3);
    return x+y+z;
}


int stairCase_memoization(,int*arr,int n){
    if(n<=0)return 1;
	if(arr[n]!=-1) 
		return arr[n];


		
		
    int x=stairCase_memoization(int*arr,int n-1);
  

   	int 	y=stairCase_memoization(int*arr,int n-2);
    
      int z=stairCase_memoization(int*arr,int n-3);
    arr[n]= x+y+z;
    

return arr[n];		
}

int memoizationHelper(int n){
int *arr=new int[n+1];
for(int i=0;i<=n;i++)
	arr[i]=-1;

	
	int answer=stairCase_memoization(arr, n);
	delete []arr;
	return answer;
}
int main(){
	int n;
	cin>>n;
cout<<staircase( n);
	
}

*/















/*


DP

Time complexity: O(N)
Space complexity: O(1)
Where N is the input given
*/



/*
#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int stairCase(int n)
{
if (n <= 1)
{
return 1;
}
long long a = 1, b = 1, c = 2;
for (int i = 0; i <= n - 3; ++i)
{
long long d = (a + b + c) % mod;
a = b;
b = c;
c = d;
}
return c;
}
int main(){
int testCase;
cin>>testCase;
while(testCase--){
int n;
cin>>n;
cout<<stairCase(n)<<endl;
}
}
*/
