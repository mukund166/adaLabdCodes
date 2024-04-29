#include <stdio.h>

void bubble(){
    int arr[10];

    for(int i=0; i<10; i++){
        printf("enter val arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    int swap;
    for(int i=0; i<10; i++){
        for(int j=i+1; j<10; j++){
            if(arr[i] > arr[j]){
                swap = arr[i];
                arr[i] = arr[j];
                arr[j] = swap;
            }
        }
    }

    for(int i=0; i<10; i++){
        printf("arr[%d]: %d\n", i, arr[i]);
    }
}

void main(){
    bubble();
}
