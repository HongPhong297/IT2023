#include <stdio.h>
#include <stdlib.h>

void Input(int *n){
    char a;
    do{
        printf("Input Number: ");
        scanf("%d",n);
        a = getchar();
        if(a != '\n'){
            printf("Try again!!!\n");
            fflush(stdin);
        }
    }while(a != '\n');
    

}
int main(){
    int n;
    Input(&n);
    return 0;
}


// so hoan thien


#include <stdbool.h>

bool isPerfectNumber(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}
