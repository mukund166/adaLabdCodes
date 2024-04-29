#include <stdio.h>

void linear(){
    int arr[10];
    for(int i=0; i<10; i++){
        printf("enter val arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    int found = 0;
    int val;
    printf("enter value to be searched: ");
    scanf("%d", &val);

    for(int i=0; i<10; i++){
            if(val == arr[i]){
                found = 1;
                printf("found at %d", i);
                break;
            }
    }
    if(found == 0) printf("not found");

}
void bin(){
    int arr[10];
    printf("enter numbers in a sorted format\n");
    for(int i=0; i<10; i++){
        printf("enter val arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    int beg = 0, endi = 9 , mid = (endi + beg)/2;
    int found = 0;
    int val;
    printf("enter value to be searched: ");
    scanf("%d", &val);

    while(beg<=endi){
        if(val == arr[mid]){
            found = 1;
            printf("found at %d", mid);
            break;
        }
        else if(val > arr[mid]){
            beg = mid;
            mid = (endi + beg)/2;
        }
        else{
            endi = mid;
            mid = (endi + beg)/2;
        }
    }
    if (found == 0) printf ("not found");

}
void main(){
    bin();
}
