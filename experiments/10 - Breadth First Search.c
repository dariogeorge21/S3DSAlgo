#include <stdio.h>
#define MAX 100
int queue[MAX], front = 0, rear = -1;
int visited[MAX];
void enqueue(int vertex) {
    rear++;
    queue[rear] = vertex;}
int dequeue() {
    int vertex = queue[front];
    front++;
    return vertex;}
int isEmpty() {
    return front > rear;}
void BFS(int adj[MAX][MAX], int n, int start) {
    enqueue(start);
    visited[start] = 1;
    while (!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;}}
        }}
int main() {
    int n, start;
    int adj[MAX][MAX];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);}}
    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);
    for (int i = 0; i < n; i++) {
        visited[i] = 0;}
    printf("BFS Traversal: ");
    BFS(adj, n, start);
    return 0;
}
