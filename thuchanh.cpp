#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
typedef struct ttBuuKien{
    char mabuukien[10];
    char tennguoiguu[20];
    char tennguoinhan[20];
    float trongluong;
    int ngay;
    int thang;
    int nam;
    char noidung[100];
    float dongia;

}BuuKien;
void NhapTTBuuKien(BuuKien *a, int n){
    for(int i = 0; i < n; i++){
        printf("Nhap ma buu kien %d = ",i);
        scanf("%s",(a+i)->mabuukien);
        printf("Nhap ten nguoi guu: %d =",i);
        scanf("%s",(a+i)->tennguoiguu);
        printf("Nhap ten nguoi nhan: %d =",i);
        scanf("%s",(a+i)->tennguoinhan);
        printf("Nhap trong luong: %d =",i);
        scanf("%f",(a+i)->trongluong);
        printf("Nhap ngay: %d =",i);
        scanf("%d",(a+i)->ngay);
        printf("Nhap thang: %d =",i);
        scanf("%d",(a+i)->thang);
        printf("Nhap nam: %d =",i);
        scanf("%d",(a+i)->nam);
        printf("Nhap noi dung: %d =",i);
        scanf("%s",(a+i)->noidung);
        printf("Nhap don gia: %d =",i);
        scanf("%f",(a+i)->dongia);
    }
    
}
int main(){
    BuuKien *a;
    int n = 2;
    a = (BuuKien*)malloc(n*sizeof(BuuKien));
    NhapTTBuuKien(a,n);
    return 0;
}