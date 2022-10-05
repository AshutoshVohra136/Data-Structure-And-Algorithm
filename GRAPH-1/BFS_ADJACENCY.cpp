//BFS TRAVERSAL
#include<queue>
#include<iostream>
using namespace std;
void printBFS(int **edges,int n,int sv,bool* visited){
	queue<int>pendingNodes;
	pendingNodes.push(sv);
	visited[sv]=true;
	while(pendingNodes.size()!=0){
		int currentNode=pendingNodes.front();
		pendingNodes.pop();
		cout<<currentNode<<" ";
		for(int i=0;i<n;i++){
			if(i==currentNode)continue;
			if(edges[currentNode][i]==1&&!visited[i]){
				pendingNodes.push(i);
				visited[i]=true;
			
		}
	}
}}
int main(){
int n,e;
cin>> n >> e;
int **edges=new int*[n];
for(int i=0;i<n;i++)
{
edges[i]=new int[n];
for(int j=0;j<n;j++)
edges[i][j]=0;
}

for(int i=0;i<e;i++)
{
	int s,e;
	cin >> s >> e;
	edges[s][e]=1;
	edges[e][s]=1;
	}
bool *visited=new bool[n];
for(int j=0;j<n;j++)
visited[j]=false;

printBFS(edges,n,0,visited);
delete [] visited;
for(int j=0;j<n;j++)
delete [] edges[j];
delete [] edges;
return 0;

	
}
