#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void inputValue(int *value){
    printf("input value: ");
    scanf("%d",value);
}
void allocateMemoryOnHeap(int value, int **ptr) {
    srand((unsigned int)time(NULL));
    *ptr = (int*)malloc(value*sizeof(int)); 
    
    for(int i = 0; i < value; i++){
        *(*ptr + i) = rand() % 100 + 1;
    }
}
void outputArr(int value, int *ptr){
    for(int i = 0; i < value; i++){
        printf("%d ",*(ptr + i));
    }
    printf("\n");
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
void addNewValue(int *value, int **ptr, int index, int number){
    *value += 1;
    *ptr = (int*)realloc(*ptr, (*value)*sizeof(int));
    for(int i = *value; i > index; i--){
        *(*ptr + i) = *(*ptr + i - 1);
    }
    *(*ptr + index) = number;
}
int main() {
    int value, *ptrHeap;
    inputValue(&value);
    allocateMemoryOnHeap(value, &ptrHeap);
    outputArr(value,ptrHeap);
    arrange(value, ptrHeap);
    outputArr(value,ptrHeap);
    addNewValue(&value,&ptrHeap,2,297);
    outputArr(value,ptrHeap);
    free(ptrHeap);
    return 0;
}
