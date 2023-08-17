#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void allocate2DArray(int rows, int cols, int*** array) {
    srand((unsigned int)time(NULL));
    *array = (int**)malloc(rows * sizeof(int*)); // Cấp phát mảng con trỏ
    for (int i = 0; i < rows; i++) {
        *((*array) + i) = (int*)malloc(cols * sizeof(int)); // Cấp phát mỗi dòng
        //(*array) là con trỏ lớn nhất bởi vì con trỏ lớn nhất nắm địa chỉ của từng con trỏ con thứ 0
        // (*array)[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            (*array)[i][j] = rand()%(22+1) + 7 ; // Gán giá trị
        }
    }
}
//7 - 29

void free2DArray(int rows, int** array) {
    for (int i = 0; i < rows; i++) {
        free(array[i]); // Giải phóng mỗi dòng
    }
    free(array); // Giải phóng mảng con trỏ
}

int main() {
    int rows = 3;
    int cols = 4;
    int** array2D;

    allocate2DArray(rows, cols, &array2D); // Cấp phát bộ nhớ mảng 2D

    // In mảng 2D đã cấp phát
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", array2D[i][j]);
        }
        printf("\n");
    }

    free2DArray(rows, array2D); // Giải phóng bộ nhớ

    return 0;
}
