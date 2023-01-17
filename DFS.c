
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int adjMatrix [MAX][MAX] = {0}, visited[MAX] = {0};
void DFS(int start) {
    int i;
    printf("%d ", start);
    visited[start] = 1;
    for (i = 0; i < MAX; i++) {
        if (adjMatrix[start][i] == 1 && visited[i] == 0)
        DFS(i);
    }
}
int main() {
    int i, j, n, edges, x, y, startnode;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    for (i = 0; i<edges; i++) {
        printf("Enter the edge: ");
        scanf("%d %d", &x, &y);
        adjMatrix[x][y] = adjMatrix[y][x] = 1;
    }
    printf("Enter the starting node: ");
    scanf("%d", &startnode);
    printf("The DFS traversal with start node %d is: ", startnode);
    DFS(startnode);
    return 0;
}

