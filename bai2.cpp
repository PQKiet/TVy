#include <stdio.h>

void nhapMang(int a[], int n){
	for(int i=0; i<n; i++){
		printf("Nhap phan tu thu %d: ", i+1);
		scanf("%d", &a[i]);
	}
}

void xuatMang(const int a[], int n){
	if(n<=0){
		printf("Mang khong co phan tu!\n");
		return;
	}
	for(int i=0; i<n; i++){
		printf("%6d", a[i]);
	}
	printf("\n");
}
//cau a:
int kiemTraThuTu(const int a[], int n){
	for(int i=0; i<n-1; i++){
		if(a[i]>a[i+1])
			return 0;
	}
	return 1;
}

int laSNT(int n){
	if(n<2) return 0;
	else if(n==2) return 1;
	else if(n%2==0) return 0;
	else{
		for(int i=3; i<n; i+=2){
			if(n%i==0){
				return 0;
			}
		}
		return 1;
	}
}
//cau b:
int viTriMinSNT(const int a[], int n){
	int min=99999, viTri=-1;
	for(int i=0; i<n; i++){
		if(laSNT(a[i]) && min>a[i]){
			min=a[i];
			viTri=i+1;
		}
	}
	return viTri;
}
//cau c
void copySNT(const int a[], int b[], int n, int &m){
	m=0;
	for(int i=0; i<n; i++){
		if(laSNT(a[i])){
			b[m]=a[i];
			m++;
		}
	}
}

int main(){
	int mangMotChieu[100], soLuong;
	printf("Nhap so luong phan tu: ");
	scanf("%d", &soLuong);
	while(soLuong<=0){
		printf("Nhap lai so luong: ");
		scanf("%d", &soLuong);
	}
	nhapMang(mangMotChieu, soLuong);
	printf("Mang vua nhap la: ");
	xuatMang(mangMotChieu, soLuong);
	
	if(kiemTraThuTu(mangMotChieu, soLuong)){
		printf("Mang da duoc sap xep theo thu tu\n");
	}
	else{
		printf("Mang khong co thu tu\n");
	}
	
	if(viTriMinSNT(mangMotChieu, soLuong)==-1){
		printf("Khong co so nguyen to trong mang\n");
	}
	else{
		printf("Vi tri so nguyen to nho nhat trong mang: %d\n", viTriMinSNT(mangMotChieu, soLuong));
	}
	
	int b[100], m;
	copySNT(mangMotChieu, b, soLuong, m);
	printf("Mang b sau khi copy la: ");
	xuatMang(b, m);
	return 0;
}
