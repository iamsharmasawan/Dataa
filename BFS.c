
#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#define MAX 100
void BFS (int adjMatrix[][MAX], int visited[], int startnode) {
    int queue[MAX], front = -1, rear = -1, i;
    visited[startnode] = 1;
    queue[++rear] = startnode;
    printf("%d ", startnode);
    while (front != rear) {
    startnode = queue[++front];
        for (i = 0; i < MAX; i++) {
            if (adjMatrix[startnode][i] == 1 && visited[i] == 0) {
            queue[++rear] = i;
            visited[i] = 1;
            printf("%d ", i);
            }
        }
    }
}
void main () {
    int adjMatrix[MAX][MAX] = {0}, visited[MAX] = {0}, i, x, y, n;
    int edges, startnode;
    clrscr();
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
    printf("The BFS traversal with start node %d is: ", startnode);
    BFS(adjMatrix, visited, startnode);
    getch();
}

