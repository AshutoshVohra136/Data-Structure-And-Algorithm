#include<iostream>

/*
input
5 7
0 1 4
0 2 8
1 2 2
1 3 6
2 3 3
2 4 9
3 4 5

*/
using namespace std;
int findMinVertex(int*distance,bool*visited,int n){
	int minVertex=-1;
	for(int i=0;i<n;i++)
	{
		if(!visited[i]&&(minVertex==-1||distance[i]<distance[minVertex]))
		minVertex=i;
	}
	
}


void dijkstra(int**edges,int n){
	int *distance=new int[n];
	bool *visited=new bool[n];
	for(int i=0;i<n;i++){
		visited[i]=false;
		distance[i]=INT_MAX;
		
	}
	distance[0]=0;
	
	for(int i=0;i<n-1;i++){
	
	int minVertex=findMinVertex(distance,visited,n);
visited[minVertex]=1;
		
	for(int j=0;j<n;j++){
	if(!visited[i]&&edges[minVertex][i]!=0){
	int dist=distance[minVertex]+edges[minVertex][i];
	if(dist<distance[j])
	distance[j]=dist;
	
	}}
}
}




int main(){
	int n,e;
	cin >> n >> e ;
	int**edges=new int*[n];
	for(int i=0;i<n;i++)
	edges[i]=new int[n];
	
	for(int i=0;i<e;i++)
	{
		int f , s , w;
		cin >> f >> s >> w;
		edges[f][s]=w;
		edges[s][f]=w;
		
	}
	dijkstra(edges,n);
	for(int i=0;i<n;i++)
	delete [] edges[i];
	delete edges;
	return 0;
}
