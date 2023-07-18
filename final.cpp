#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>



typedef struct InforStudents
{
    char IDs[11]; //2280602357
    char Name[30];
    char Sex; // x nu , y nam
    char ClassName[8];
    float Point;
    int DayOfBirth; 
    int MonthOfBirth;
    int YearOfBirth;
}Std;

void InputInfor1Student(Std *svien){
    do{
        printf("Nhap ma SV: ");
        scanf("%s",&(svien->maSV));
        if(strlen(svien->maSV) != 10)
            printf("Sai...\n");
    }while(strlen(svien->maSV) != 10);
    printf("Nhap ma SV: ");
    scanf("%s",&svien->maSV);
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
        //scanf("%s",&x.gioitinh);
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
void CNTT(SV *svien, int n){
    printf("Danh sach SV nganh CNTT\n");
    for(int i = 0; i < n; i++){
        if(a[i].masv[3] == 'e' && a[i].masv[4] == '2')
            Xuat1SV(a[i]);
    }
    //if(a->masv[3] == 't' && a->masv[4] == 'h')
}
int main(){
    //Test();
    Std *students;
    int NumberOfStudents;
    printf("Input number of students: ");
    scanf("%d",&NumberOfStudents);
    students = (Std*)malloc(NumberOfStudents*sizeof(SV));
    NhapDSSV(a,n);
    // Xuat1SV(a[0]);
    XuatDS(a,n);
    CNTT(a,n);
    return 0;
}