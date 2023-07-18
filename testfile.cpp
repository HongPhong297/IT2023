#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int DocFile(int *n, int *m, int b[])
{
    FILE *f;
    f=fopen("so.out", "r");
    if(f==NULL)
        return 0;
    fscanf(f, "%d",n);
    fscanf(f, "%d",m);
    for(int i = 0; i < 4; i++ ){
        fscanf(f, "%d",&b[i]);
    }
    // fscanf(f, "%d", n);
    // fscanf(f, "%d", M);
    fclose(f);
    return 1;
}
int main(){
    int n, m;
    int b[4];
    DocFile(&n,&m,b);
    printf("%d\t",n);
    printf("%d\n",m);
    for(int i = 0; i < 4; i++){
        printf("%d\t",b[i]);
    }
    return 0;
}