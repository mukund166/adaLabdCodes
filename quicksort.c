#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int low, int high){
    int pivot = A[low], i=low+1, j=high;

    do{
        while (i <= high && A[i] <= pivot) i++;
        while (j >= low && A[j] > pivot) j--;
        if (i < j)
            swap(&A[i], &A[j]);

    }while(i<j);

    swap(&A[low], &A[j]);
    return j;
}
void quicksort(int A[], int low, int high){
    int part ;
    if(low<high){
        part = partition(A, low, high);
        quicksort(A, low, part -1);
        quicksort(A, part+1, high);
    }
}
int main(){
    int A[]={11,13,7,12,16,9,24,5,10,3,27},n=11,i;
    quicksort(A,0,10);
    for(i=0;i<11;i++)
        printf("%d ",A[i]);
}
