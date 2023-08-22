#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void allocateMemoryOnHeap(int value, int **ptr) {
    srand((unsigned int)time(NULL));
    *ptr = (int*)malloc(value*sizeof(int)); 
    
    for(int i = 0; i < value; i++){
        *(*ptr + i) = rand() % 101 + 1;
    }
}
void arrange(int value, int *ptr){
    for(int i = 0; i < value - 1; i++){
        int min = i;
        for(int j = i + 1; j < value; j++){
            if(*(ptr + j) < *(ptr + min)){
                min = j;
            }
        }
        int temp = *(ptr + i);
        *(ptr + i)= *(ptr + min);
        *(ptr + min) = temp;
    }
}
// void addNewValue(int value, int )
int main() {
    int value;
    printf("input value: ");
    scanf("%d",&value);
    int *ptrHeap = &value;
    printf("%p \n",ptrHeap);
    //allocateMemoryOnHeap(value, ptrHeap);
    ptrHeap = (int*)malloc(value*sizeof(int));
    if(ptrHeap != NULL)
        printf("Khai bao thanh cong");
    printf("\nDia chi cua bien: %p",ptrHeap);
    srand((unsigned int)time(NULL));
    for(int i = 0; i < value; i++){
        *(ptrHeap + i) = rand() % 101 + 1;
    }
    printf("\n");
    printf("%p \n",&value);
    for(int i = 0; i < value; i++){
        printf("%p\n",(ptrHeap + i));
    }
    
    //arrange(value, ptrHeap);
    // for(int i = 0; i < value; i++){ 
    //     printf("%d ",*(ptrHeap + i));
    // }
    free(ptrHeap);
    return 0;
}
