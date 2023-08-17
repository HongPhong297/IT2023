#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void allocateMemoryOnHeap(int value, int **ptr) {
    srand((unsigned int)time(NULL));
    *ptr = (int*)malloc(value*sizeof(int)); 
    /*khi khai báo 1 hay nhiều chiều cũng chỉ cần 1 sao vì hàm mallloc cần 1 con trỏ đứng trước nó*/
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
int main() {
    int value;
    printf("input value: ");
    scanf("%d",&value);
    int *ptrHeap;
    allocateMemoryOnHeap(value, &ptrHeap);
    for(int i = 0; i < value; i++){
        printf("%d ",*(ptrHeap + i));
    }
    printf("\n");
    arrange(value, ptrHeap);
    for(int i = 0; i < value; i++){
        printf("%d ",*(ptrHeap + i));
    }
    free(ptrHeap);
    return 0;
}
