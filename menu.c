#include<stdio.h>
void Menu(){
    printf("Chuong trinh quan ly danh sach bai hat\n");
    printf("1. Xem danh sach bai hat\n");
    printf("2. Loc danh sach bai hat\n");
    printf("3. Them bai hat\n");
    printf("4. Xoa bai hat\n");
    printf("5. Thung rac\n");
    printf("6. Thoat\n");
}
void Thuoctinh(){
    printf("1. Ten bai hat\n");
    printf("2. Ten ca si\n");
    printf("3. Ten nhac si\n");
    printf("4. Nam sang tac\n");
}
void Head(){
    printf(" %30s", "Ten bai hat");
    printf(" %30s","Ten ca si");
    printf(" %30s","Ten nhac si");
    printf(" %30s\n\n","Nam sang tac");
}