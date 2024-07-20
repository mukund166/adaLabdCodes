#include <stdio.h>
#include <limits>
// Function to perform Floyd's algorithm for all-pairs shortest paths
void floyd(int n, int W[][n], int D[][n]) {
    // Initialize distance matrix D as the same as weight matrix W
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            D[i][j] = W[i][j];
        }
    }

    // Apply Floyd's algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (D[i][k] != INT_MAX && D[k][j] != INT_MAX && D[i][j] > D[i][k] + D[k][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
}

// Function to print the distance matrix
void printMatrix(int n, int D[][n]) {
    printf("Distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (D[i][j] == INT_MAX) {
                printf("INF\t");
            } else {
                printf("%d\t", D[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int W[n][n]; // Weight matrix of the graph
    int D[n][n]; // Distance matrix (will be computed)

    printf("Enter the weight matrix W (enter -1 for infinity):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &W[i][j]);
            if (W[i][j] == -1) {
                W[i][j] = INT_MAX; // Assuming -1 represents infinity (change as needed)
            }
        }
    }

    // Call Floyd's algorithm
    floyd(n, W, D);

    // Print the distance matrix
    printMatrix(n, D);

    return 0;
}
