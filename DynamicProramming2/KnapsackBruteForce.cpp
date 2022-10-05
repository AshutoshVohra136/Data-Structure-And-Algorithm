// KNAPSACK

#include<iostream>
using namespace std;
int knapsack(int*weight,int*values,int n,int maxWeight){
	if(n==0||maxWeight==0)return 0;
	if(weight[0]>maxWeight)
	return	knapsack(1+weight,1+values,n-1,maxWeight);
		
	int x=knapsack(1+weight,1+values,n-1,maxWeight-weight[0])+values[0];
	int y=knapsack(1+weight,1+values,n-1,maxWeight);
		return max(x,y);
} 

int main(){int n=5;
int weight[]={5,1,8,9,2};
int values[]={4,10,2,3,1};
int maxWeight=15;
cout<<knapsack(weight,values,n,maxWeight)<<endl;

	
}
