/*
Time complexity: O(V + E)
Space complexity: O(V^2)
where V is the number of vertices in the input graph and
E is the number of edges in the input graph
*/
#include <iostream>
using namespace std;
void DFS(bool** graph, int v, bool* visited, int currentVertex) {
visited[currentVertex] = true;
for (int i = 0; i < v; ++i) {
if (graph[currentVertex][i] && !visited[i]) {
DFS(graph, v, visited, i);
}
}
}
int getIslandGroups(bool** graph, int v) {
bool* visited = new bool[v]();
int groupCount = 0;
for (int i = 0; i < v; ++i) {
if (!visited[i]) {
DFS(graph, v, visited, i);
++groupCount;
}
}
return groupCount;
}
int main() {
int v, e;
cin >> v >> e;
bool** graph = new bool*[v];
for (int i = 0; i < v; ++i) {
graph[i] = new bool[v]();
}
for (int i = 0, a, b; i < e; ++i) {
cin >> a >> b;
graph[a][b] = true;
graph[b][a] = true;
}
cout << getIslandGroups(graph, v);
for (int i = 0; i < v; ++i) {
delete[] graph[i];
}
delete[] graph;
}
