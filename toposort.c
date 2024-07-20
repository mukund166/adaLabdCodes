/*#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int n; // Number of vertices
int adj[MAX][MAX]; // Adjacency matrix
int visited[MAX]; // Array to keep track of visited vertices
int stack[MAX]; // Stack to store the sorted vertices
int top = -1; // Top of the stack

// Function to push an element onto the stack
void push(int item) {
    stack[++top] = item;
}

// Function to pop an element from the stack
int pop() {
    return stack[top--];
}

// Function to perform depth-first search
void dfs(int v) {
    int i;
    visited[v] = 1;
    for (i = 0; i < n; ++i) {
        if (adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }
    push(v);
}

// Function to perform topological sorting
void topologicalSort() {
    int i;
    for (i = 0; i < n; ++i) {
        visited[i] = 0;
    }
    for (i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    printf("Topological sorting of the given graph is: ");
    while (top != -1) {
        printf("%d ", pop());
    }
}

int main() {
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            scanf("%d", &adj[i][j]);
        }
    }
    topologicalSort();
    return 0;
}*/
#include <stdio.h>

void DFS(int A[][11], int i, int n, int visited[], int stack[], int* top) {
    if(visited[i] == 0) {
        visited[i] = 1;
        for(int j = 1; j < n; j++) {
            if(A[i][j] == 1 && visited[j] == 0) {
                DFS(A, j, n, visited, stack, top);
            }
        }
        stack[--*top] = i;
    }
}

void topologicalSort(int A[][11], int n) {
    int visited[11] = {0};
    int stack[11];
    int top = n;

    for(int i = 1; i < n; i++) {
        if(visited[i] == 0) {
            DFS(A, i, n, visited, stack, &top);
        }
    }

    printf("Topological Order: ");
    for(int i = 1; i < n; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int G[11][11] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

    topologicalSort(G, 11);
    return 0;
}

