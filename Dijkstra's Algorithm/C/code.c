#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define maxnodes 100
int findmindistance(int dist[], bool visited[], int numnodes) {
int mindist =INT_MAX;//here INT_MAX is a predefined value
int minindex=-1;
for (int v = 0; v < numnodes; v++) {
if (visited[v] == false && dist[v] <= mindist) {
mindist = dist[v];
minindex = v;
}
}
return minindex;
}
//To find the shortest path following code is used
void printshortestpath(int dist[], int origin[], int xy, int numnodes) {
printf("Vertex\t\tDistance\tPath\n");
for (int v = 0; v < numnodes; v++) {
printf("%d\t\t%d\t\t", v, dist[v]);
int j = v;
while (j != xy) {
printf("%d <- ", j);
j = origin[j];
}
printf("%d\n", xy);
}
}
void dijkstra(int graph[maxnodes][maxnodes], int xy, int numnodes) {
int dist[maxnodes]; 
bool visited[maxnodes]; 
int origin[maxnodes];
for (int i = 0; i < numnodes; i++) {
dist[i] = INT_MAX;
visited[i] = false;
}
dist[xy] = 0;
origin[xy] = -1; 
for (int count = 0; count < numnodes - 1; count++) {
///find  minimum distance between each node
int u = findmindistance(dist, visited, numnodes);
visited[u] = true;
for (int v = 0; v < numnodes; v++) {
if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] +
graph[u][v] < dist[v]) {
dist[v] = dist[u] + graph[u][v];
origin[v] = u;
}
}
}
//Prints the shortest path
printshortestpath(dist, origin, xy, numnodes);
}
int main() {
int numnodes, i, j;
int graph[maxnodes][maxnodes];
printf("Input the number of nodes: ");
scanf("%d", &numnodes);
printf("Input your adjacency matrix:\n");
for (i = 0; i < numnodes; i++) {
for (j = 0; j < numnodes; j++) {
scanf("%d", &graph[i][j]);
}
}
int source;
printf("Input the source vertex: ");
scanf("%d", &source);
dijkstra(graph, source, numnodes);
return 0;
}
