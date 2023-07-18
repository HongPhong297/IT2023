#include <stdio.h>
#include <stdlib.h>
typedef struct Point
{
    float x;
    float y;
} TD;
void Nhap1ToaDo(TD *d)
{
    printf("Nhap hoanh do = ");
    scanf("%f", &d->x);
    printf("Nhap tung do = ");
    scanf("%f", &d->y);
}
void Input(TD *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        // printf("Input Point %d\n", i + 1);
        // printf("X = ");
        // scanf("%f", &(a + i)->x);
        // printf("Y = ");
        // scanf("%f", &(a + i)->y);
        Nhap1ToaDo((a + i));
    }
}
void Output(TD *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%.2f %.2f\n", (a + i)->x, (a + i)->y);
    }
}
int TrenTrucHoanh(TD *a, int n)
{
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        if ((a + i)->y > 0)
            temp += 1;
    }
    return temp;
}
int main()
{
    TD *a;
    int n;
    printf("N = ");
    scanf("%d", &n);
    a = (TD *)malloc(n * sizeof(TD));
    Input(a, n);
    Output(a, n);
    int t = TrenTrucHoanh(a, n);
    printf("%d",t);
    return 0;
}