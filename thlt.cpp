#include <stdio.h>
#include <math.h>

void NhapN(int *n)
{
	do{
		printf("Nhap so phan tu mang a: ");
		scanf("%d",n);
		if(*n < 0)
			printf("Nhap sai nhap lai\n");
		else 
			break;
	}while(1);
}
int KTtrungnhau(int a[], int n){
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(a[i] == a[j])
				return 0;
		}
	}
	return 1;
}
void NhapMang(int a[], int n)
{	
	for(int i = 0; i < n; i++){
		printf("a[%d] = ",i);
		scanf("%d",&a[i]);
	}
	do{
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				if(a[i] == a[j]){
					printf("Nhap trung a[%d] hay nhap lai\n",i);
					printf("a[%d] = ",i);
					scanf("%d",&a[i]);
				}	
			}	
		}
	}while(KTtrungnhau(a,n) == 0);
}
void XuatMang(int a[], int n){
	printf("Mang cua ban la: \n");
	for(int i = 0; i < n; i++){
		printf("a[%d] = %d \n",i,a[i]);
	}
}
int Sochinhphuong(int a){
	if(a < 1)
		return 0;
	int i = sqrt(a);
	if(i * i == a)
		return 1;
	return 0;
}
void SCPLe(int a[], int n){
	int z = 0;
	printf("SCP o vi tri le = ");
	for(int i = 0; i < n; i++){
		if(Sochinhphuong(a[i]) == 1 && i % 2 == 1){
			printf("%d ",a[i]);
			z = 1;
		}
	}
	if(z == 0)
		printf("Khong tim thay");
}
int Max(int a[], int n){
	int max = a[0];
	int temp = 0;
	for(int i = 1 ; i < n; i++){
		if(a[i] > max){
			max = a[i];
			temp = i;
		}
			
	}
	return temp;
}
int KTSoAm(int a[], int n){
	// kiem tra xem co full so duong hay khong ?
	int temp = 0;
	for(int i = 0; i < n; i++){
		if(a[i] > 0)
			temp += 1;
	}
	if(temp != n)
		return 0;
	return 1;
}


int MaxAm(int a[], int n){
	if(KTSoAm(a,n) == 1)
		return 0;
	int max = 0;
	int temp;
	for(int i = 0; i < n; i++){
		if(a[i] < 0){
			max = a[i];
			temp = i;
			break;
		}	
	}
	for(int i = temp + 1; i < n; i++){
		if(a[i] < 0){
			if(a[i] > max)
			max = a[i];
		}	
	}
	return max;
}
int KTSoDuong(int a[], int n){
	// kiem tra xem co full so am hay khong ?
	int temp = 0;
	for(int i = 0; i < n; i++){
		if(a[i] < 0)
			temp += 1;
	}
	if(temp != n)
		return 0;
	return 1;
}
int MinDuong(int a[], int n){
	if(KTSoDuong(a,n) == 1)
		return 0;
	int min = 1;
	for(int i = 0; i < n; i++){
		if(a[i] > 0){
			min = a[i];
			break;
		}	
	}
	for(int i = 0; i < n; i++){
		if(a[i] > 0){
			if(a[i] < min)
			min = a[i];
		}	
	}
	return min;
}
int Tongchan(int a[], int n){
	int s = 0;
	for(int i = 1; i < n; i++){
		if(i % 2 == 0 )
			s = s + a[i];
	}
	return s;
}
void Sapxep(int a[], int n){
	int min;
	int temp;
	for(int i = 0; i < n; i++){
		min = i;
		for(int j = i + 1 ; j < n; j++){
			if(a[j] < a[min])
				min = j;
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;	
	}
}



int main(){
	int n;
	int a[100];
	NhapN(&n);
	NhapMang(a,n);
	XuatMang(a,n);
	SCPLe(a,n);
	printf("\nVi tri phan tu lon nhat la: %d ",Max(a,n));
	if(MaxAm(a,n) == 0)
		printf("\nKhong tim thay so am trong mang cua ban");
	else
		printf("\nPhan tu am lon nhat la: %d ",MaxAm(a,n));
	if(MinDuong(a,n) == 0)
		printf("\nKhong tim thay so duong trong mang cua ban");
	else
		printf("\nPhan tu duong be nhat la: %d ",MinDuong(a,n));
	//printf("\nPhan tu duong nho nhat la: %d ",MinDuong(a,n));
	printf("\nTong cac phan tu chan trong mang la: %d ",Tongchan(a,n));
	Sapxep(a,n);
	printf("\nMang sau khi sap xep: ");
	XuatMang(a,n);
	return 0;
}

