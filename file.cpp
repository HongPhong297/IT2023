#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int DocFile(int *n, int *M)
{
    FILE *f;
    f=fopen("so.txt", "r");
    if(f==NULL)
        return 0;
    fscanf(f, "%d", n);
    fscanf(f, "%d", M);
    fclose(f);
    return 1;
}
int TaoFile(int n, int M)
{
    FILE *f;
    f=fopen("so.out", "w");
    if(f==NULL)
        return 0;
    fprintf(f, "%d\n", n);
    for(int i=1; i<=n; i++)
        fprintf(f, "%d\n", rand()%M+1);
    fclose(f);
    return 1;
}
int main(void){
    srand((unsigned int)time(NULL));
    int n, M;
    if(DocFile(&n, &M)==0)
        printf("Loi doc file\n");
    else
    {
        printf("Doc thanh cong: n=%d; M=%d\n", n, M);
        if(TaoFile(n, M)==0)
            printf("\nLoi tao file\n");
        else
            printf("\nDa tao file thanh cong\n");
    }

    return 0;
}
