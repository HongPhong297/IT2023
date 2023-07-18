#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void Input(int *sd,int *sc){
	do{
		printf("Nhap so dong > 0: ");
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
	else 
		for(int i = 2; i < n; i++){
			if(n % i == 0)
				return 0;
			else 
				return 1;
		}
}
int main(){
	int a[MAX][MAX], sd, sc,d,c;
	int z = 7;
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
	if(checksoNT(z) == 1)
		printf("Day la so nguyen to");
	
	
	
	return 0;
}

