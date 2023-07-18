#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void Input(int *sd,int *sc){
	do{
		printf("Nhap so dong > 1: ");
		scanf("%d",sd);
		printf("Nhap so cot <= 100: ");
		scanf("%d",sc);
		if(*sd <= 0 || *sc > 100)
			printf("Nhap sai hay nhap lai\n");
		else 
			break;
			
	}while(1);		
}
void PhatSinh(int a[][MAX],int sd,int sc){
	srand((unsigned int)time(NULL));
	for(int i = 0; i < sd; i++){
		for(int j = 0; j < sc; j++){
			a[i][j] = rand() %50 + 1;
		}
	}
}
void XuatGT(int a[][MAX],int sd,int sc){
	for(int i = 0; i < sd; i++){
		for(int j = 0; j < sc; j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
void XuatGTDong(int a[][MAX],int d,int sd,int sc){
	for(int i = 0; i < sd; i++){
		if(i == d){
			for(int j = 0; j < sc; j++){
				printf("%d\t",a[i][j]);
			}
		}		
	}
	printf("\n");
}
void XuatCot(int a[][MAX],int c,int sd,int sc){
	for(int i = 0; i < sd; i++){
		for(int j = 0; j < sc; j++){
			if(j == c){
				printf("%d",a[i][j]);
			}
		}
		printf("\n");
	}	
}
void MTChuyenVi(int a[][MAX],int sd,int sc){
	for(int j = 0; j < sc; j++){
		for(int i = 0; i < sd; i++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
void GTLe(int a[][MAX],int sd,int sc){
	for(int i = 0; i < sd; i++){
		for(int j = 0; j < sc; j++){
			if(a[i][j] % 2 == 1)
				printf("%d ",a[i][j]);
		}
	}
}
int checksoNT(int n){
	if(n < 2)
		return 0;
	for (int i = 2; i < n; i++)
    {
        if(n % i == 0)
            return 0;
    }
    return 1;
}
void XuatSoNguyenTo(int a[][MAX], int sd, int sc){
    for(int i = 0; i < sd; i++){
        for(int j = 0; j < sc; j++){
            if(checksoNT(a[i][j]) == 1)
                printf("%d\t",a[i][j]);
        }
    }
}
void LonhonX(int a[][MAX],int sd, int sc, int x){
    for(int i = 0; i < sd; i++){
        for(int j = 0; j < sc; j++){
            if(a[i][j] > x)
                printf("%d\t",a[i][j]);
        }
    }
}
// Bài Tập 2
int PhantuMax(int a[][MAX],int sd,int sc){
    int max = a[0][0];
    for(int i = 0; i < sd; i++){
        for(int j = 0; j < sc; j++){
            if(a[i][j] > max)
                max = a[i][j];
        }
    }
    return max;
}
void VitriMax(int a[][MAX], int sd, int sc){
    int max = a[0][0];
    int dong = 0, cot = 0;
    for(int i = 0; i < sd; i++){
        for(int j = 0; j < sc; j++){
            if(a[i][j] > max){
                max = a[i][j];
                dong = i;
                cot = j;
            }   
        }
    }
    printf("Vi tri lon nhat la a[%d][%d]",dong,cot);  
     
}
void XuathienX(int a[][MAX], int sd, int sc, int x){
    int dong, cot;
    for(int i = 0; i < sd; i++){
        for(int j = 0; j < sc; j++){
            if(a[i][j] == x){
                dong = i;
                cot = j;
                break;
            }
        }
    }
    printf("\nVi tri dau tien cua X la: a[%d][%d]",dong ,cot);
}
int Hanglonnhat(int a[][MAX], int sd, int sc){
	int tong = 0;
	int max = 0;
	int dong;
	for(int i = 0; i < sd; i++)
	{
		for(int j = 0; j < sc; j++)
		{
			tong = tong + a[i][j];
			//max = tong;
		}
		if(tong > max)
		{
			max = tong;
			dong = i;
		}
		tong = 0;
	}
	return dong;
}
int Cotbenhat(int a[][MAX], int sd, int sc)
{
	int tong = 0;
	int temp = 0;
	int cot = 0;
	for(int i = 0; i < sd; i++)
	{
		temp = temp + a[i][0];
	}
 	int min = temp;
	for(int j = 0; j < sc; j++)
 	{
		for(int i = 0; i < sd; i++)
		{
			tong = tong + a[i][j];
		}
		if(tong < min)
		{
			min = tong;
			cot = j;
		}
		tong = 0;
 	}
	return cot;
}
int main(){
	int a[MAX][MAX], sd, sc,d,c,x;
	Input(&sd,&sc);
	PhatSinh(a,sd,sc);
	printf("Mang sau khi phat sinh: \n");
	XuatGT(a,sd,sc);
	do{
		printf("Nhap dong can truy xuat: ");
		scanf("%d",&d);
		if(d < 0 || d >= sd)
			printf("Nhap sai\n");
		else
			break;
	}while(1);
	XuatGTDong(a,d,sd,sc);
	do{
		printf("Nhap cot can truy xuat: ");
		scanf("%d",&c);
		if(c < 0 || c >= sc)
			printf("Nhap sai\n");
		else
			break;
	}while(1);
	XuatCot(a,c,sd,sc);
	printf("Ma tran chuyen vi la: \n");
	MTChuyenVi(a,sd,sc);
	printf("Gia tri le la: ");
	GTLe(a,sd,sc);
    printf("\nCac so nguyen to la: ");
    XuatSoNguyenTo(a,sd,sc);
    printf("\nNhap gia tri x: ");
    scanf("%d",&x);
    printf("Gia tri lon hon X: ");
    LonhonX(a,sd,sc,x);
    printf("\nPhan tu max la: %d",PhantuMax(a,sd,sc));
	printf("\n");
    VitriMax(a,sd,sc);
    XuathienX(a,sd,sc,x);
	printf("\nDong co tong lon nhat la: %d",Hanglonnhat(a,sd,sc));
	printf("\nCot co tong be nhat la: %d",Cotbenhat(a,sd,sc));
	
	
	return 0;
}

