#include "base.c"
int compare_name(const void *a, const void *b){
    char *p1 = (*(song*)a)->name;
    char *p2 = (*(song*)b)->name;
    return strcmp(p1,p2);
}
int compare_singer(const void *a, const void *b){
    char *p1 = (*(song*)a)->singer;
    char *p2 = (*(song*)b)->singer;
    return strcmp(p1,p2);
}
int compare_musician(const void *a, const void *b){
    char *p1 = (*(song*)a)->musician;
    char *p2 = (*(song*)b)->musician;
    return strcmp(p1,p2);
}
int compare_year(const void *a, const void *b){
    char *p1 = (*(song*)a)->year;
    char *p2 = (*(song*)b)->year;
    int t1, t2;
    sscanf(p1, "%d", &t1);
    sscanf(p2, "%d", &t2);
    return t1-t2;
}