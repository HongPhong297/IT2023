#include <stdio.h>

#define MAX 100
void Nhap(int a[], int n)
{
	if (n == 0)
		return;
	Nhap(a, n - 1);
	printf("\nNhap phan tu thu %d: ", n - 1);
	scanf("%d", &a[n - 1]);
}
void Xuat(int a[], int n)
{
	if (n == 0)
		return;
	Xuat(a, n - 1);
	printf("%d\t", a[n - 1]);
}
int TinhTong(int a[], int n)
{
	if (n == 1)
		return a[n - 1];
	return a[n - 1] + TinhTong(a, n - 1);
}
int TinhTongChan(int a[], int n)
{
	if (n == 0)
		return 0;
	int s = TinhTongChan(a, n - 1);
	if (a[n - 1] % 2 == 0)
	{
		s += a[n - 1];
	}

	return s;
	// 3
	// 2 4 7

	/*
	s = a , 2 =
	s = 6
	s = a, 1 =
	s = 2
	s = a, 0 = 0

	*/
	// 4
}
// int TinhTongChan(int a[], int n){
// 	if(n == 0)
// 		return 0;
// 	int s = 0;
//     TinhTongChan(a,n-1);
// 	if(a[n-1] % 2 == 0){
// 		s += a[n-1];
// 	}

// 	return s;
// }
int DemPhanTuDuong(int a[], int n)
{
	if (n == 0)
		return 0;
	int s = DemPhanTuDuong(a, n - 1);
	if (a[n - 1] > 0)
	{
		s += 1;
	}
	return s; // van chay
}
int TimMax(int a[], int n)
{
	if (n == 1)
		return a[n - 1];
	int max = TimMax(a, n - 1);
	if (a[n - 1] > max)
		max = a[n - 1];
	return max;
}
int TimMin(int a[], int n)
{
	if (n == 1)
		return a[n - 1];
	int min = TimMin(a, n - 1);
	if (a[n - 1] < min)
		min = a[n - 1];
	return min;
}

int TimPTChanCuoi(int a[], int n)
{
	if (n == 0)
		return -1;
	if (a[n - 1] % 2 == 0)
		return a[n - 1];
	return TimPTChanCuoi(a, n - 1);
}
int TimXCuoi(int a[], int n, int x)
{
	if (n == 0)
		return -1;
	// TimXCuoi(a,n,x);
	if (a[n - 1] == x)
		return a[n - 1];
	return TimXCuoi(a, n - 1, x);
}
int main()
{
	int a[MAX], n, x;
	printf("Nhap N:");
	scanf("%d", &n);
	//	printf("Nhap X:");
	//	scanf("%d",&x);
	Nhap(a, n);
	Xuat(a, n);
	printf("\nTong cua mang la: %d ", TinhTong(a, n));
	printf("\nTong chan cua mang la: %d ", TinhTongChan(a, n));
	printf("\nSo phan tu duong cua mang la: %d ", DemPhanTuDuong(a, n));
	printf("\nPhan tu Max cua mang la: %d ", TimMax(a, n));
	printf("\nPhan tu Min cua mang la: %d ", TimMin(a, n));
	if (TimPTChanCuoi(a, n) == -1)
		printf("\nKo Tim Thay PT Chan");
	else
		printf("\nPhan tu chan cuoi cung cua mang la: %d ", TimPTChanCuoi(a, n));
	printf("\nNhap X:");
	scanf("%d", &x);
	if (TimXCuoi(a, n, x) == -1)
		printf("\nKo Tim Thay X");
	else
		printf("\nPhan tu X cuoi cung cua mang la: %d ", TimXCuoi(a, n, x));
	// TinhTong(a,n);
	return 0;
}