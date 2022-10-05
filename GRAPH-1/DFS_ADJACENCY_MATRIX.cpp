#include<iostream>
using namespace std;


void printGraph(int **edges,int numofVertex,int sv,bool*visited){
		cout<<sv<<" ";
		visited[sv]=true;
		for(int i=0;i<numofVertex;i++)
		{
			if(i==sv)continue;
			if(edges[sv][i]==1){
				if(visited[i])continue;
				printGraph(edges,numofVertex,i,visited);
			}
		}
		
	}
int main(){

	int numofVertex,numofEdges;
	cin>> numofVertex >> numofEdges;
	int **edges=new int*[numofVertex];
	for(int i=0;i<numofVertex;i++)
	{
			edges[i]=new int[numofVertex];
			for(int j=0;j<numofVertex;j++)
				edges[i][j]=0;		//zero indicate no edge between 2 vertices
				
	}

	
	for(int i=0;i<numofEdges;i++)
	
{	int firstVertex,secondVertex;
	cin>>firstVertex>>secondVertex;
	
	edges[firstVertex][secondVertex]=1;
	edges[secondVertex][firstVertex]=1;
		
}
	
	bool *visited=new bool[numofVertex];
	for(int i=0;i<numofVertex;i++)
		visited[i]=false;
	
	
	printGraph(edges,numofVertex,0,visited);
																								
}

