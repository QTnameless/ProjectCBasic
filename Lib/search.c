#include "sort.c"
#include <ctype.h>
char *strlwr(char* s){ // nếu sử dụng windows thì không cần build lại hàm này
    char* tmp = s;
    for (;*tmp;++tmp){
        *tmp = tolower((unsigned char) *tmp);
    }
    return s;
}
void Search_name(song *a, char *p, int n){
    song *find = calloc(n, sizeof(song));
    int f = 0;
    char *tmp;
    for(int i=0; i<n; i++){
        tmp = strdup(a[i]->name);
        if(strstr(strlwr(tmp),strlwr(p))){
            find[f] = a[i];
            f++;
        }
    }
    PrintSong(find,f);
}
void Search_singer(song *a, char *p, int n){
    song *find = calloc(n, sizeof(song));
    int f = 0;
    char *tmp;
    for(int i=0; i<n; i++){
        tmp = strdup(a[i]->singer);
        if(strstr(strlwr(tmp),strlwr(p))){
            find[f] = a[i];
            f++;
        }
    }
    PrintSong(find,f);
}
void Search_musician(song *a, char *p, int n){
    song *find = calloc(n, sizeof(song));
    int f = 0;
    char *tmp;
    for(int i=0; i<n; i++){
        tmp = strdup(a[i]->musician);
        if(strstr(strlwr(tmp),strlwr(p))){
            find[f] = a[i];
            f++;
        }
    }
    PrintSong(find,f);
}
void Search_year(song *a, char *p, int n){
    song *find = calloc(n, sizeof(song));
    int f = 0;
    char *tmp;
    for(int i=0; i<n; i++){
        tmp = strdup(a[i]->year);
        if(strstr(strlwr(tmp),strlwr(p))){
            find[f] = a[i];
            f++;
        }
    }
    PrintSong(find,f);
}