#include<stdio.h>

int main(){
    int limit;
    printf("Enter the limit of array: ");
    scanf("%d",&limit);
    int arr[limit];
    printf("Enter the elements: ");
    for (int i=0;i<limit;i++){
        scanf("%d",&arr[i]);
    }printf("The array elements are: \n");
    for (int i=0;i<limit;i++){
        printf("%d\t",arr[i]);
    }
    for (int i=0;i<limit;i++){
        for(int j=0;j<(limit-i-1);j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("\nThe sorted array:\n");
    for(int i=0;i<limit;i++){
        printf("%d  ",arr[i]);
    }
}
