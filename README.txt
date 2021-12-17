Chương trình quản lý danh sách bài hát
Chương trình được chia thành các hàm con:
    + cgetline.c để đọc 1 dòng từ dữ liệu văn bản input
    + base.c chứa các cấu trúc và hàm nền tảng của chương trình
    + search.c chứa các hàm cho mục đích tìm kiếm của chương trình
    + sort.c chứa các hàm cho mục đích sắp xếp dữ liệu
    + menu.c chứa giao diện của chương trình
    + all.c để tổng hợp các hàm con thành 1
    + main.c là phần chính của chương trình, biên dịch đoạn code này để khởi động chương trình

Biên dịch:
    + GCC: gcc -o prog main.c
           ./prog
    + Cmake + Ninja: đang lỗi