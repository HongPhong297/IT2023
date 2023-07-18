#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Nhap(int *a, int n){
    srand((unsigned int)time(NULL));
    for(int i = 0; i < n; i++){
            *(a+i) = rand()%50 + 1;
    }
}
void XuatMang(int *a, int n){
	for(int i = 0; i < n; i++){
		printf("%d ",*(a + i));
	}
}
int SoLe(int n){
	if(n % 2 == 0)
		return 0;
	return 1;
}
int* Chuyen(int *a, int n, int *m){
	*m = 0;
	int *b;
	b = (int*)malloc(n*sizeof(int));
	for(int i = 0; i < n; i++){
		if(*(a + i) % 2 == 1){
			*(b+*m) = *(a+i);
			(*m)++;	
		}		
	}
	b = (int*)realloc(b,*m*sizeof(int));
	return b;		
}
void Sapxep(int *a, int n){
	for(int i = 0; i < n;i++){
		int min = i;
		for(int j = i+1; j < n; j++){
			if(*(a + j) < *(a + min ))
				min = j;
		}
		int temp = *(a + i);
		*(a + i) = *(a + min);		
		*(a + min) = temp;
	}
}
int TimMax(int *a, int n, int x){
	int vtri = 0;
	for(int i = 0; i < n; i++){
		if(*(a + i) < x)
			vtri = i;
	}
	return vtri;
}

void ThemPhanTuX1(int *arr, int n, int x){
	// a la 1 mang ;  n va x la 1 so nguyen.
	arr = (int*)realloc(arr,(n + 1)*sizeof(int));
	if(TimMax(arr,n,x) == 0){
		for(int i = n + 1; i > 0 ; i--)
			*(arr + i) = *(arr + i - 1);
		*(arr + 0) = x;
		(n)++;
	}
	else{
		for(int i = n + 1; i > TimMax(arr,n,x) + 1; i--){
		*(arr + i) = *(arr + i - 1);
	}
	*(arr + TimMax(arr,n,x) + 1) = x;
	(n)++;
	}
	
	
}
void insert(int arr[], int n, int x) {
    int i, j;

    // Tìm vị trí cần chèn của phần tử mới
    for (i = 0; i < n && arr[i] < x; i++);

    // Dời các phần tử từ vị trí cần chèn đến cuối mảng sang phải một vị trí
    for (j = n - 1; j >= i; j--) {
        arr[j+1] = arr[j];
    }

    // Chèn phần tử mới vào vị trí cần chèn
    arr[i] = x;
}
void ThemPhanTuX(int *arr, int *size, int x){
	//arr = (int*)realloc(arr,(*size + 1)*sizeof(int));
	int i,j;
	for(i = 0; i < *size && arr[i] < x;i++);
	if(i == *size){
		arr[i] = x;
		(*size)++;
	}
	else{
		for(j = *size -1; j >= i; j--){
			arr[j+1] = arr[j];
		}
		arr[i] = x;
		(*size)++;
	}

}

void NhapB(int *b, int m){
	for(int i = 0; i < m; i++){
		printf("b[%d] = ",i);
		scanf("%d",(b + i));
	}
}
void NhapA(int *a, int n){
	for(int i = 0; i < n; i++){
		printf("a[%d] = ",i);
		scanf("%d",(a + i));
	}
}
void MangC(int *a, int *b, int *c, int *n, int m){
	//c = (int*)malloc((n + m)*sizeof(int));
	// int k = *n + m;
    // c = (int*)malloc(k * sizeof(int));
	for(int j = 0; j < m; j++){
		a = (int*)realloc(a,(*n + 1)*sizeof(int));
		ThemPhanTuX(a,&(*n),*(b + j));
	}
	
	//a = (int*)realloc(a,*n*sizeof(int));
	// ? mat mang A
	printf("\n N luc nay = %d\n",*n);
	for(int i = 0; i < *n; i++){
		c[i] = a[i];
	}
	for(int k = 0; k < *n; k++){
		printf("%d\t",*(c + k));
	}
	
}
void MangC1(int *a, int *b, int *c, int *n, int m){
    // Kiểm tra tính hợp lệ của tham số đầu vào
    if (n == NULL || m < 0) {
        printf("Tham so dau vao khong hop le\n");
        return;
    }
    
    // Cấp phát bộ nhớ cho mảng c
    int k = *n + m;
    c = (int*) malloc(k * sizeof(int));

    // Thêm các phần tử trong mảng a vào mảng c
    for (int i = 0; i < *n; i++) {
        ThemPhanTuX(c, &k, a[i]);
    }

    // Thêm các phần tử trong mảng b vào mảng c
    for (int j = 0; j < m; j++) {
        ThemPhanTuX(c, &k, b[j]);
    }
}

void XuatMangC(int *c, int n){
	//printf("\nN trong xuat mang C = %d\n",n);
	for(int i = 0; i < n; i++){
		printf("%d\t",*(c + i));
	}
	//printf("\nN trong xuat mang C = %d\n",n);
	

}
void Test(void){
	int *a, *b, n, m, x;
	printf("Nhap N: ");
	scanf("%d",&n);
	a = (int*)malloc(n*sizeof(int));
	Nhap(a,n);
	printf("Mang A: ");
	XuatMang(a,n);
	b = Chuyen(a,n,&m);
	Chuyen(a,n,&m);
	printf("\nMang B: ");
	XuatMang(b,m);
	Sapxep(a,n);
	printf("\nMang sau khi sap xep : ");
	XuatMang(a,n);
	printf("\nNhap phan tu X: ");
	scanf("%d",&x);
	//a = (int*)realloc(a,(n + 1)*sizeof(int));
	ThemPhanTuX(a,&n,x);
	printf("Mang sau khi them X: ");
	XuatMang(a,n);
}
void Test2(void){
	int *a, *b, *c, n, m;
	printf("Nhap N: ");
	scanf("%d",&n);
	printf("Nhap M: ");
	scanf("%d",&m);
	//printf("\nZ = %d",z);
	a = (int*)malloc(n*sizeof(int));
	b = (int*)malloc(m*sizeof(int));
	c = (int*)malloc((n + m)*sizeof(int));
	NhapA(a,n);
	printf("\n");
	NhapB(b,m);
	Sapxep(a,n);
	Sapxep(b,m);
	printf("Mang A da xap xep: ");
	XuatMang(a,n);
	printf("\nMang B da xap xep: ");
	XuatMang(b,m);
	printf("\n");
	//printf("Z luc nay : %d",z);
	//c = (int*)malloc(z*sizeof(int));
	//a = (int*)realloc(a,(n + 1)*sizeof(int));
	// ThemPhanTuX(a,&n,5);
	
	
	MangC(a,b,c,&n,m);
	//XuatMang(c,n);
	
}

int main(){
	Test2();
	return 0;
}
