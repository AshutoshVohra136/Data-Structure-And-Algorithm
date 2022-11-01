#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// MINIMUM SPANNING TREE


// INPUT
/*
8 13
0 3 1
0 1 4
0 2 9
3 2 8
1 2 2
1 5 6
1 6 11
2 6 3
5 6 12
5 7 13
7 8 7
8 6 10
5 8 5



*/
class Edge{
public:
	int weight;
	int source;
	int destination;
	
	
};

bool compare(Edge e1,Edge e2){
	return e1.weight>e2.weight;
}
	int findParent(int*parent,int v){
		if(parent[v]==v)
		return v;
		return findParent(parent,parent[v]);
		
	}

void 	KrusKals(Edge*input,int n,int E){
	
	sort(input,input+E,compare);
	
	int*parent=new int[n];
	for(int i=0;i<n;i++)
		parent[i]=i;
	Edge*output=new Edge[n-1];
	int count=0;

	int i=0; // INDEX TO TRAVERSE OVER THE INPUT ARRAY
	while(count!=n-1){
		Edge currentEdge=input[i];
		int sourceParent=findParent(parent,currentEdge.source);
		int destiParent=findParent(parent,currentEdge.destination);
		if(sourceParent!=destiParent)
		{
			output[count]=currentEdge;
			count++;
			parent[sourceParent]=destiParent;
		}
		i++;
	}
	
	for(int i=0;i<n-1;i++)
	{
		if(output[i].source<output[i].destination)
		cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
		else
		
		cout<<output[i].destination<<" "<<output[i].source<<" "<<output[i].weight<<endl;
	}
	
}
int main(){
int n,E;
cin>> n >> E;
Edge *input=new Edge[E];

for(int i=0;i<E;i++)
{
	int s,d,w;
	cin >> s >> d >> w;
	input[i].source=s;
	input[i].destination=d;
	input[i].weight=w;
	
}
	KrusKals(input,n,E);
	return 0;
}
