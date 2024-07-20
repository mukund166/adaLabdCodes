 #include <stdio.h>
#include <stdlib.h>

void prn(int n, int m[][50]) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
}

void dijkstra(int n, int s, int m[][50], int dist[10]) {
    int i, v, count = 1, min, visited[10];
    for (i = 1; i <= n; i++) {
        visited[i] = 0;
        dist[i] = m[s][i];
    }
    visited[s] = 1;
    dist[s] = 0;
    while (count <= n) {
        min = 999;
        v = 0;
        for (i = 1; i <= n; i++) {
            if (dist[i] < min && visited[i] == 0) {
                min = dist[i];
                v = i;
            }
        }
        visited[v] = 1;
        count++;
        for (i = 1; i <= n; i++) {
            if (m[v][i] != 0 && dist[i] > dist[v] + m[v][i]) {
                dist[i] = dist[v] + m[v][i];
            }
        }
    }
}

int main() {
    int n, s, m[50][50], dist[10];
    printf("enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("enter [%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (m[i][j] == 0) {
                m[i][j] = 998;
            }
        }
    }
    prn(n, m);
    printf("read source: ");
    scanf("%d", &s);
    dijkstra(n, s, m, dist);
    printf("shortest path from %d is:\n", s);
    for (int i = 1; i <= n; i++) {
        if (s != i) {
            printf("%d -> %d = %d\n", s, i, dist[i]);
        }
    }
    return 0;
}
