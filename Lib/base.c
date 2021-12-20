#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void clear(void){
    while(getchar() != '\n');
}
typedef struct song_t{
    char *name;
    char *singer;
    char *musician;
    char *year;
    int ap;
}*song;
void Add(song a, char *name, char *singer, char *musician, char *year, int q){
    a->name = strdup(name);
    a->singer = strdup(singer);
    a->musician = strdup(musician);
    a->year = strdup(year);
    a->ap = q;
}
void PrintASong(song a){
    printf("%30s", a->name);
    printf("%30s",a->singer);
    printf("%30s",a->musician);
    printf("%30s\n",a->year);
}
void process(char *line, song a, int q){
    char *name;
    char *singer;
    char *musician;
    char *year;
    name = strtok(line,"#*\n");
    singer = strtok(NULL,"#*\n");
    musician = strtok(NULL,"#*\n");
    year = strtok(NULL,"#*\n");
    Add(a,name,singer,musician,year,q);
}
void PrintSong(song *a, int count){
    int idx = 0;
    int i = 0;
    for(i=0; i<count; i++){
        if(a[i]->ap){
            printf("%d  ",idx+1);
            PrintASong(a[i]);
            idx++;
        }
    }
    if(i == 0){
        printf("Khong co tep nao\n");
    }
}
void PrintBin(song *a, int count){
    int idx = 0;
    int i = 0;
    for(i=0; i<count; i++){
        if(!a[i]->ap){
            printf("%d  ",idx+1);
            PrintASong(a[i]);
            idx++;
        }
    }
    if(i == 0){
        printf("Khong co tep nao\n");
    }
}
void Save(song *a, int count){
    FILE *out = fopen("song.txt","w+");
    FILE *bin = fopen("bin.txt","w+");
    int idx1 = 0, idx2 = 0;
    for(int i=0; i<count; i++){
        if(a[i]->ap){
            if(idx1) fprintf(out, "\n");
            fprintf(out,"%s#*#%s#*#%s#*#%s",a[i]->name, a[i]->singer,a[i]->musician, a[i]->year);
            idx1++;
        }
        else{
            if(idx2) fprintf(bin, "\n");
            fprintf(bin,"%s#*#%s#*#%s#*#%s",a[i]->name, a[i]->singer,a[i]->musician, a[i]->year);
            idx2++;
        }
    }
    fclose(bin);
    fclose(out);
}
void Remove(song *a, int count, int remove){
    int idx = 1;
    for(int i=0; i<count; i++){
        if(a[i]->ap){
            if(idx == remove){
                a[i]->ap = 0;
                break;
            }
            else idx++;
        }
    }
}
void Restore(song *a, int count, int restore){
    int idx = 1;
    for(int i=0; i<count; i++){
        if(!a[i]->ap){
            if(idx == restore){
                a[i]->ap = 1;
                break;
            }
            else idx++;
        }
    }
}