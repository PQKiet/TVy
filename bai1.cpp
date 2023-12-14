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
int kiemTraLoaiSo(const int a[], int n){
	int soDuong=0, soAm=0, so0=0; 
	for(int i=0; i<n; i++){
		if(a[i]<0){
			soAm++;
		}
		else if(a[i]==0){
			so0++;
		}
		else{
			soDuong++;
		}
		if(soAm && soDuong && so0){
			return 1;
		}
	}
	return 0;
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
//cau b: cach 1
void inViTriSNT(const int a[], int n){
	int dem=0;
	for(int i=0; i<n; i++){
		if(laSNT(a[i])){
			printf("%6d", i+1);
			dem++;
		}
	}
	if(dem==0){
		printf("Khong co so nguyen to!");
	}
	printf("\n");
}
//cah 2 : da hoc con tro
/*
int* viTriSoNguyenTo(int a[], int n, int *dem){
	int mangSNT[100];
	(*dem)=0;
	for(int i=0; i<n; i++){
		if(laSNT(a[i])){
			mangSNT[*dem]=i+1;
			*dem=*dem+1;
		}
	}
	return mangSNT;
}
*/
//cau c
void xoaSoNguyenTo(int a[], int &n){
	for(int i=0; i<n; i++){
		if(laSNT(a[i])){
			//di chuyen cac phan tu sang trai
			for(int j=i; j<n-1; j++){
				a[j]=a[j+1];
			}
			n--;
			i--;
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
	
	if(kiemTraLoaiSo(mangMotChieu, soLuong)){
		printf("Mang co du so duong, so am va so 0\n");
	}
	else{
		printf("Mang khong co du loai so\n");
	}
	
	printf("Vi tri cac so nguyen to co trong mang: ");
	inViTriSNT(mangMotChieu, soLuong);
//cau b (da hoc con tro)	
/*	
	int *mangSNT, soSNT;
	mangSNT=viTriSoNguyenTo(mangMotChieu, soLuong, &soSNT);
	printf("Vi tri cac so nguyen to co trong mang: ");
	for(int i=0; i<soSNT; i++){
		printf("%6d", *(mangSNT+i));
	}
	printf("\n");
*/	
	xoaSoNguyenTo(mangMotChieu, soLuong);
	printf("Mang sau khi xoa cac so nguyen to: ");
	xuatMang(mangMotChieu, soLuong);
	return 0;
}
