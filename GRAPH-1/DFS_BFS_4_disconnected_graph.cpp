//BFS/DFS TRAVERSAL FOR DISCONNECTED GRAPH
#include<queue>
#include<iostream>

//INPUT 
// 7 5 0 2 0 3 2 3 1 4 5 6
using namespace std;
void printDFS(int **edges,int numofVertex,int sv,bool*visited){
		cout<<sv<<" ";
		visited[sv]=true;
		for(int i=0;i<numofVertex;i++)
		{
			if(i==sv)continue;
			if(edges[sv][i]==1){
				if(visited[i])continue;
				printDFS(edges,numofVertex,i,visited);
			}
		}
		
	}
	
	
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







int dfs(int**edges,int n){
	cout<<" DEPTH FIRST SEARCH "<<"\n";
bool *visited=new bool[n];
for(int j=0;j<n;j++)
visited[j]=false;

int c=0;
for(int i=0;i<n;i++)
{		//THIS LOOP IS FOR IF THE GRAPH HAS CONNECTED COMPONENTS
if(!visited[i])
{
	
c++;
printDFS(edges,n,i,visited);
}
}

delete [] visited;
return c;}








void bfs(int**edges,int n){
	cout<<" BREADTH FIRST SEARCH "<<"\n";
bool *visited=new bool[n];
for(int j=0;j<n;j++)
visited[j]=false;


for(int i=0;i<n;i++)
{
if(!visited[i])
printBFS(edges,n,i,visited);

}

delete [] visited;
}



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


bfs(edges,n);
int c=dfs(edges,n);
cout<<"\t\nConnected\t\n\t\n\t\n\t\n"<<c;
for(int j=0;j<n;j++)
delete [] edges[j];
delete [] edges;
return 0;

	
}
