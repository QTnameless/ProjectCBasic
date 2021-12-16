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
void Add(song a, char *name, char *singer, char *musician, char *year){
    a->name = strdup(name);
    a->singer = strdup(singer);
    a->musician = strdup(musician);
    a->year = strdup(year);
    a->ap = 1;
}
void PrintASong(song a){
    printf("%30s", a->name);
    printf("%30s",a->singer);
    printf("%30s",a->musician);
    printf("%30s\n",a->year);
}
void process(char *line, song a){
    char *name;
    char *singer;
    char *musician;
    char *year;
    name = strtok(line,"#*\n");
    singer = strtok(NULL,"#*\n");
    musician = strtok(NULL,"#*\n");
    year = strtok(NULL,"#*\n");
    Add(a,name,singer,musician,year);
}
void PrintSong(song *a, int count){
    int idx = 0;
    for(int i=0; i<count; i++){
        if(a[i]->ap){
            printf("%d  ",idx+1);
            PrintASong(a[i]);
            idx++;
        }
    }
}
void PrintBin(song *a, int count){
    int idx = 0;
    for(int i=0; i<count; i++){
        if(!a[i]->ap){
            printf("%d  ",idx+1);
            PrintASong(a[i]);
            idx++;
        }
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