/*
    Chương trình quản lý danh sách bài hát
*/
#include "Lib/all.h"
int main(){
    int count = 0;
    FILE *f = fopen("song.txt","r");
    char *line = NULL;
    song *list = calloc(count, sizeof(song));
    while(cgetline(&line,0,f)){
        count++;
        list = (song*)realloc(list,count*sizeof(song));
        list[count-1] = malloc(sizeof(struct song_t));
        process(line,list[count-1],1);
    }
    fclose(f);

    FILE *f_bin = fopen("bin.txt","r");
    while(cgetline(&line,0,f_bin)){
        count++;
        list = (song*)realloc(list,count*sizeof(song));
        list[count-1] = malloc(sizeof(struct song_t));
        process(line,list[count-1],0);
    }
    fclose(f_bin);

    int choice = 0, choice_1, remove, restore;
    char strr[1024], new_song[1024], new_singer[1024], new_musician[1024], new_year[1024];
    while(choice != 7){
        Menu();
        printf("Nhap vao lua chon cua ban: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            Thuoctinh();
            printf("Nhap vao lua chon cua ban: ");
            scanf("%d",&choice_1);
            if(choice_1 == 1)qsort(list,count,sizeof(song),compare_name);
            else if(choice_1 == 2) qsort(list,count,sizeof(song),compare_singer);
            else if(choice_1 == 3) qsort(list,count,sizeof(song),compare_musician);
            else if(choice_1 == 4) qsort(list,count,sizeof(song),compare_year);
            Head();
            PrintSong(list,count);
            break;


            case 2:
            Thuoctinh();
            printf("Nhap vao lua chon cua ban: ");
            scanf("%d",&choice_1);
            if(choice_1 == 1){
                printf("Nhap ten bai hat can tim: ");
                scanf("%s",strr);
                Search_name(list,strr,count);
            }
            else if(choice_1 == 2){
                printf("Nhap ten ca si can tim: ");
                scanf("%s",strr);
                Search_singer(list,strr,count);
            }
            else if(choice_1 == 3){
                printf("Nhap ten nhac si can tim: ");
                scanf("%s",strr);
                Search_musician(list,strr,count);
            }
            else if(choice_1 == 4){
                printf("Nhap nam can tim: ");
                scanf("%s",strr);
                Search_year(list,strr,count);
            }
            break;


            case 3:
            clear();
            printf("Them bai hat\n");
            printf("%s","Ten bai hat: ");
            scanf("%[^\n]s",new_song);
            clear();
            printf("%s", "Ten ca sy: ");
            scanf("%[^\n]s",new_singer);
            clear();
            printf("%s", "Ten nhac sy: ");
            scanf("%[^\n]s",new_musician);
            clear();
            printf("%s", "Nam sang tac: ");
            scanf("%[^\n]s",new_year);
            clear();
            count++;
            list = (song*)realloc(list,count*sizeof(song));
            list[count-1] = malloc(sizeof(struct song_t));
            Add(list[count-1],new_song,new_singer,new_musician,new_year,1);
            break;


            case 4:
            clear();
            qsort(list,count,sizeof(song),compare_name);
            PrintSong(list,count);
            printf("Nhap so thu tu bai ban muon xoa: ");
            scanf("%d",&remove);
            Remove(list,count,remove);
            break;


            case 5:
            PrintBin(list,count);
            break;


            case 6:
            PrintBin(list,count);
            printf("Nhap so thu tu bai ban muon khoi phuc: ");
            scanf("%d",&restore);
            Restore(list,count,restore);
            break;

        }
        Save(list,count);
    }
    return 0;
}