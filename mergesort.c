#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    int temp[100];
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    for (; i <= mid; i++)
        temp[k++] = arr[i];
    for (; j <= high; j++)
        temp[k++] = arr[j];
    for (i = low; i <= high; i++)
        arr[i] = temp[i];
}

void IMergeSort(int arr[], int n) {
    int step, low, high, mid, i;
    for (step = 2; step <= n; step = step * 2) {
        for (i = 0; i + step - 1 < n; i = i + step) {
            low = i;
            high = i + step - 1;
            mid = (low + high) / 2;
            merge(arr, low, mid, high);
        }
        if (n - i > step / 2) {
            low = i;
            high = i + step - 1;
            mid = (low + high) / 2;
            merge(arr, low, mid, n - 1);
        }
    }
    if (step / 2 < n) {
        merge(arr, 0, step / 2 - 1, n - 1);
    }
}

int main() {
    int arr[] = {11, 5, 14, 2, 6, 3, 1}, n = 7, i;
    IMergeSort(arr, n);
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
