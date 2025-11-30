#include <stdio.h> //printf,fopen,getline
#include <stdlib.h>//exit malloc free
#include <string.h>//strlen strstr strcmp

#define MAX_LEN 1024

int compare(const void *line1,const void *line2){//function to be used in qsort
    //const void* means pointer to unknown variable
    char *const *a = line1;
    char * const *b = line2;
    return strcmp(*a,*b);
}



int main(int argc, char* argv[]){

    if(argc != 2){
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    char **lines = NULL;
    char buff[MAX_LEN];
    int count = 0;

    while(fgets(buff,sizeof(buff),fp)){//copying all lines in the file to lines pointer
        lines = realloc(lines,(count+1)*sizeof(char*));
        lines[count] = strdup(buff);
        count++;
    }
    fclose(fp);

    qsort(lines,count,sizeof(char*),compare);//sorting function
    int i = 0;
    while(i<count){
        int j = i+1;
        while(j<count && strcmp(lines[i],lines[j]) == 0){
            j++;
        }
        int freq = j-i;
        if(freq>1){
            printf("%d : %s",freq,lines[i]);
        }
        i = j;
    }

    for(int i = 0; i < count; i++){
        free(lines[i]);
    }
    free(lines);

    return 0;
}