#include <stdio.h>
#include <stdlib.h>
typedef struct Point
{
    float x;
    float y;
} TD;
void Nhap1ToaDo(TD *a)
{
    printf("Nhap hoanh do = ");
    scanf("%f", &a->x);
    printf("Nhap tung do = ");
    scanf("%f", &a->y);
}

void Output(TD a)
{

    printf("%.2f %.2f\n", a.x, a.y);
}

int main()
{
    TD *a;
    a = (TD *)malloc(sizeof(TD));
    Nhap1ToaDo(a);
    Output(*a);
    return 0;
}