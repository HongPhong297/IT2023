#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

void Input(int *n){
    do{
        printf("Enter the number of elements from 1 to %d =  ",MAX);
        scanf("%d",n);
        if(*n < 1 || *n > MAX)
        	printf("Wrong try again \n");
        else 
        	break; 

    }while(1);
}
//void NhapMang(int a[], int n){
//	for(int i = 0; i < n; i++){
//		printf("a[%d] = ",i);
//		scanf("%d",&a[i]);
//	}
//}
void PhatSinh(int a[], int n){
	srand((unsigned int)time(NULL));
	for(int i = 0; i < n; i++){
		a[i] = rand() %50 + 1;  // random 00 - 49 --> 1 --> 50  
	}
}
void XuatMang(int a[], int n){
	for(int i = 0; i < n; i++){
		printf("%d ",a[i]);
	}
}
int TimX(int a[], int n , int x){
	for(int i = 0; i < n; i++){
		if(x == a[i])
			return i;			
	}
	return -1;
}
int TimMax(int a[], int n){
	int max = 0;
	for(int i = 1; i < n; i++){
		if(a[i] > a[max])
			max = i;
	}
	return max;
}
int ChenXVaoDau(int a[], int *n, int x){
	if(*n == MAX)
		return 0; // Khong the them
	(*n)++;
	for(int i = *n; i > 0; i--){
		a[i] = a[i-1];
	}
	a[0] = x;
	return 1;
}
int XoaPhanTuDau(int a[], int *n){
	if(*n == 1)
		return 0; 
	(*n)--;
	for(int i = 0; i < *n; i++){ // n = 6 a[5] ; n = 5 a[4]
		a[i] = a[i+1];
	}
	return 1;	
}
int main(){
    int n , a[MAX];
    int x ;
    Input(&n);
    PhatSinh(a, n);
    XuatMang(a, n);
    // Nhap so de thuc hien yeu cau bai toan
    printf("\nEnter your number to find: ");
    scanf("%d",&x);
    if(TimX(a, n, x) != -1)
    	printf("Vi tri cua so can tim la: %d",TimX(a, n, x));
    else
    	printf("Khong tim thay vi tri cua so can tim");
    //Tim Max
    printf("\nVi tri phan tu lon nhat trong mang la: %d",TimMax(a, n));
    //Chen X
    if(ChenXVaoDau(a,&n,x) == 0)
    	printf("\nKhong the chen them duoc nua ");
    else{
    	printf("\nMang sau khi chen:");
    	XuatMang(a,n);
	}
	if(XoaPhanTuDau(a,&n) == 0)
		printf("\nKhong the xoa ");
	else{
		printf("\nMang sau khi xoa:");
		XuatMang(a,n);
	}
		
		
    	
    return 0;

}
