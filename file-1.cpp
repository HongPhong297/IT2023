#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void InputN(int *n){

    do{
        printf("Input N: ");
        scanf("%d",n);
        if(*n <= 0 || *n > 10000)
            printf("Wrong try\n");
    }while(*n <= 0 || *n > 10000);
}
void CreateArr(int n, int *a){
    srand((unsigned int)time(NULL));
    for(int i = 0; i < n; i++){
        *(a+i) = rand()%100 + 1;
    }
}
int TaoFile(int n, int *a)
{
    FILE *f;
    f=fopen("so.out", "w");
    if(f==NULL)
        return 0;
    fprintf(f, "%d\n", n);
    for(int i=0; i < n; i++)
        fprintf(f, "%d ",*(a + i));
    fclose(f);
    return 1;
}
int LuuKetQua(int n, int *b){
    FILE *f;
    f=fopen("ketqua.out", "w");
    if(f==NULL)
        return 0;
    fprintf(f, "%d\n", n);
    for(int i=0; i < n; i++)
        fprintf(f, "%d ",*(b + i));
    fclose(f);
    return 1;
}
int DocFile(int n, int *b)
{
    FILE *f;
    f=fopen("so.out", "r");
    if(f==NULL)
        return 0;
    fscanf(f, "%d",&n);
    for(int i = 0; i < n; i++ ){
        fscanf(f, "%d", (b + i));
    }
    // fscanf(f, "%d", n);
    // fscanf(f, "%d", M);
    fclose(f);
    return 1;
}
void SapXep(int n, int *b){
    int temp;
    int min;
    for(int i = 0; i < n; i++){
        min = i;
        for(int j = i + 1; j < n; j++)
            if(b[j] < b[min])
                min = j;
        temp = b[i];
        b[i] = b[min];
        b[min] = temp;
    }
}

int max(int n, int *b){
    int m = 0;
    int gt = b[0];
    for(int i = 1; i < n; i++){
        if(b[i] > b[m]){
            m = i;
            gt = b[i];
        }    
    }
    return gt;
}
int min(int n, int *b){
    int m = 0;
    int gt = b[0];
    for(int i = 1; i < n; i++){
        if(b[i] < b[m]){
            m = i;
            gt = b[i];
        }    
    }
    return gt;
}
int SoPTChan(int n, int *b){
    int temp = 0;
    for(int i = 0; i < n; i++){
        if(b[i] % 2 == 0){
            temp++;
        }    
    }
    return temp;
}
int SoPTLe(int n, int *b){
    int temp = 0;
    for(int i = 0; i < n; i++){
        if(b[i] % 2 == 1){
            temp++;
        }    
    }
    return temp;
}
int LuuKetQua3(int n, int *b){
    FILE *f;
    f=fopen("ketqua2.out", "w");
    if(f==NULL)
        return 0;
    fprintf(f, "So lon nhat la: %d\n",max(n,b));
    fprintf(f, "So be nhat la: %d\n",min(n,b));
    fprintf(f, "So phan tu chan la: %d\n",SoPTChan(n,b));
    fprintf(f, "So phan tu le la: %d\n",SoPTLe(n,b));
    
    fclose(f);
    return 1;
}
int main(void){
    int n, *a, *b;
    InputN(&n);

    a = (int*)malloc(n*sizeof(int));
    CreateArr(n,a);

   
    //csrand((unsigned int)time(NULL));

    if(TaoFile(n,a) == 0)
        printf("Loi tao file\n");
    else
        printf("Tao file thanh cong\n");
    b = (int*)malloc(n*sizeof(int));
    if(DocFile(n,b) == 0)
        printf("Loi Doc File\n");
    else
        printf("Doc file thanh cong\n");
    SapXep(n,b);
    LuuKetQua(n,b);
    LuuKetQua3(n,b);
    return 0;
}
