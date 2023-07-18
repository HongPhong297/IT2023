#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define MAX 100

typedef struct DateSV
{
    unsigned char ngay; // 0 -> 255
    unsigned char thang;
    int nam;
}Date;
typedef struct SinhVien
{
    char masv[8];
    char hoten[30];
    Date ns;
    char gioitinh; // x nu , y nam
    char lop[3];
    float diemtb;
}SV;

void NhapNgaySinh(Date &d){
    do{
        printf("Nhap ngay sinh: ");
        scanf("%2u",&d.ngay);
        printf("Nhap thang: ");
        scanf("%2u",&d.thang);
        printf("Nhap nam sinh: ");
        scanf("%4d",&d.nam);
        if(d.ngay > 31 || d.ngay < 1 || d.thang > 12 || d.thang < 1 || d.nam > 2023 || d.nam < 1)
            printf("Nhap lai ngay thang nam sinh...\n");
    }while(d.ngay > 31 || d.ngay < 1 || d.thang > 12 || d.thang < 1 || d.nam > 2023 || d.nam < 1);
    
}
void XuatNgaySinh(Date d){
    printf("%2u/%2u/%4d\t",d.ngay,d.thang,d.nam);
}
void Nhap1SV(SV &x){
    printf("Nhap ma SV: ");
    scanf("%s",&x.masv);
    printf("Nhap ho ten: ");
    fflush(stdin);
    gets(x.hoten);
    printf("Nhap ngay thang nam sinh: \n");
    NhapNgaySinh(x.ns);
    printf("Nhap ten lop: ");
    scanf("%s",&x.lop);
    do{
        printf("Nhap gioi tinh(x-nu, y-nam): ");
        x.gioitinh = getche();
        //scanf("%c",&x.gioitinh);
    }while(x.gioitinh != 'x' && x.gioitinh != 'y');

    printf("\nNhap DiemTB: ");
    scanf("%f",&x.diemtb);
}
void Xuat1SV(SV x){
    printf("%-10s\t%-30s",x.masv,x.hoten);
    if(x.gioitinh == 'x')
        printf("Nu\t");
    else
        printf("Nam\t");
    XuatNgaySinh(x.ns);
    printf("%-10s\t%.1f",x.lop,x.diemtb);
}
void NhapDSSV(SV a[], int n){
    printf("\n-------------Nhap DS Sinh Vien---------------\n");
    for(int i = 0; i< n; i++){
        printf("Nhap SV thu %d\n",i + 1);
        Nhap1SV(a[i]);
    }
}
void XuatDS(SV a[], int n){
    printf("\n-------------DS Sinh Vien---------------\n");
    for(int i = 0; i < n; i++){
        Xuat1SV(a[i]);
        printf("\n");
    }
}
void CNTT(SV a[], int n){
    printf("Danh sach SV nganh CNTT\n");
    for(int i = 0; i < n; i++){
        if(a[i].masv[3] == 'e' && a[i].masv[4] == '2')
            Xuat1SV(a[i]);
    }
    //if(a->masv[3] == 't' && a->masv[4] == 'h')
}
int main(){
    //Test();
    SV a[MAX];
    int n;
    printf("Nhap so luong SVien: ");
    scanf("%d",&n);
    NhapDSSV(a,n);
    // Xuat1SV(a[0]);
    XuatDS(a,n);
    CNTT(a,n);
    return 0;
}