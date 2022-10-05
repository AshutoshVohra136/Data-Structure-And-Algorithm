#include<iostream>
using namespace std;

vector<int>* getPath(int **graph,int n,int sv,int ev){
	
	bool* visited=new bool[n];
	for(int i=0;i<n;i++)
		visited[i]=false;
	queue<int>bfsQ;
	bfsQ.push(sv);
	visited[sv]=true;
	unordered_map<int,int>parent;
	bool done=false;
	while(bfsQ.size()!=0&&!done){
		int front=bfsQ.front;
		bfsQ.pop();
		
		for(int i=0;i<n;i++)
		{
		if(graph[front][i]&&!visited[i]){
			bfsQ.push(i);
			parent[i]=front;
			visited[i]=1;
			if(i==ev)
			{done=true;
			break;
			}
		}	
		}
	}
	delete [] visited;
	if(!done)return  NULL;
	else	{
		vector<int>*output=new vector<int>();
		int current=ev;
		output->push_back(current);
		while(current!=sv)
		{
			current=parent[current];
			output->push_back(current);
		}
		return output;
		
		
	}
	
}
int main(){
	int n,e;
	cin>> n >> e;
	bool **graph=new bool*[n];
	for(int i=0;i<n;i++)
		{
		graph[i]=new bool[n];
		for(int j=0;j<n;j++)
		graph[i][j]=0;
	}
	
	for(int i=0,a,b;i<e;i++)
	{
		cin>> a >> b;
		graph[a][b]=1;
		graph[b][a]=1;
		
		
	}
	
	int sv,ev;
	cin >> sv >> ev;
	
	vector<int>* output=getPath(graph,n,sv,ev);
	if(output!=NULL){
		
		for(int i=0;i<output0>size();i++)
		{
			cout<<output->at(i)<<" ";
		
		
		}
	}
	return 0;
	
}
