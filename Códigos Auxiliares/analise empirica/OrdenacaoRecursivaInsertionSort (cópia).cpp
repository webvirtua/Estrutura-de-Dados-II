#include<stdio.h>
#define TAM 9

void print_r(int *arr, size_t n);
void insertion_sort(int *arr, size_t n, size_t i);

int main(){
    int nums[TAM] = {2,8,9,0,0,2,13,3,7};
    print_r(nums, TAM);

    printf("Ordenando\n");
    insertion_sort(nums, TAM, 0);
    print_r(nums, TAM);

    return 0;
}

void print_r(int *arr, size_t n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion_sort(int *arr, size_t n, size_t i){
    int el,j;

    if(i == n-1){
        return;
    }else{
        insertion_sort(arr, n, i+1);
        el = arr[i];

        for(j = i+1; j<n; j++){
            if(el > arr[j]){
                arr[j-1] = arr[j];
                arr[j] = el;
            }
        }
    }
}
