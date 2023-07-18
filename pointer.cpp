#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Nhap(int **a, int sd, int sc){
    srand((unsigned int)time(NULL));
    for(int i = 0; i < sd; i++){
        a[i] = (int*)malloc(sc*sizeof(int));
        for(int j = 0; j < sc; j++){
            *(*a+i*sc+j) = rand()%50 + 1;
        }
    }
}
int TimX(int **a, int sd, int sc, int x){
    int vtri = 0;
    for (int i = 0; i < sd; i++){
        for(int j = 0; j < sc; j++){
            if(*(*a + i * sc + j) == x){
                vtri = i;
                return vtri;
            }
        }
    }
    return -1;
}
void XoaDongChuaX(int **a, int *sd, int sc, int x){
    if(TimX(a,*sd,sc,x) == -1){
        printf("Khong tim thay X ");
    }
    (*sd)--;
    //a = (int**)realloc(a,*sd*sizeof(int*));
    for(int i = TimX(a,*sd + 1,sc,x); i < *sd + 1; i++){
        for(int j = 0; j < sc; j++){
            *(*a + i * sc + j) = *(*a + (i+1) * sc + j);
        }
    }
}
void Xuat(int **a, int sd, int sc){
    for(int i = 0; i < sd; i++){
        for(int j = 0; j < sc; j++){
            printf("%d ",*(*a+i*sc+j)); 
        }
        printf("\n");
    }
}
void TaoB(int *b, int sc){
    //b = (int*)malloc(sc*sizeof(int));
    srand((unsigned int)time(NULL));
    for(int i = 0; i < sc; i++){
        *(b + i) = rand()%100 + 1;
    }
}
void ThemBVaoDongCuoi(int **a, int *b, int *sd, int sc){
    (*sd)++;
    //a = (int**)realloc(a,(*sd)*sizeof(int*));
    for(int j = 0; j < sc; j++){
        *(*a + ((*sd - 1) * sc + j)) = *(b + j);
    }
}
void Test(void){
    int **a, sd, sc, x, *b;
    printf("Nhap so dong: ");
    scanf("%d",&sd);
    printf("Nhap so cot: ");
    scanf("%d",&sc);
    b = (int*)malloc(sc*sizeof(int));
    TaoB(b,sc);
    a = (int**)malloc(sd*sizeof(int*));
    Nhap(a,sd,sc);
    printf("Gia tri cua ma tran:\n");
    Xuat(a,sd,sc);
    a = (int**)realloc(a,(sd + 1)*sizeof(int*));
    // printf("Nhap X: ");
    // scanf("%d",&x);
    // if(TimX(a,sd,sc,x) == -1){
    //     printf("Khong tim thay X ");
    // }
    // else{
    //     XoaDongChuaX(a,&sd,sc,x);
    //     printf("\nMang sau khi xoa X: \n");
    //     Xuat(a,sd,sc);
    // }
    ThemBVaoDongCuoi(a,b,&sd,sc);
    printf("\nSau khi them 1 dong: \n");
    Xuat(a,sd,sc);
    
}
int main(){
    Test();
    return 0;
}