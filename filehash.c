#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include "filehash.h"

int FileSize(char* path_name){
        
    struct stat st;
    stat(path_name, &st);
    int size = st.st_size;
    return size;
}

char* ReadFromFile(char* path_name, int size){
        
    FILE* fin;
    if (NULL == (fin = fopen(path_name, "r"))){
        perror("fopen() failed\n");
        exit(EXIT_FAILURE);
    }
    char* data = (char*)malloc(size);
    size_t ret;
    if (size != (ret = fread(data, sizeof(char), size, fin))){
        fprintf(stderr, "fread() failed: %zu\n", ret);
        exit(EXIT_FAILURE);
    }
    return data;
}

char* HashData(char* data, char* password){
 
    int l_data = strlen(data);
    int l_password = strlen(password);
    char* hashdata = (char*)malloc(l_data);
    int i = 0;
    for(int x = 0; x != l_data; x++){
        hashdata[x] = data[x] ^ password[i];
        if (0 != i){
            if (1 == l_password / i){
                i = 0;
            } else {
                i++;
            }
        } else {
            i++;
        }
    }
    return hashdata;
}

void WriteToFile(char* path_name, char* data, int size){
 
    FILE* fout;
    if (NULL == (fout = fopen(path_name, "w"))){
        perror("fopen() failed\n");
        exit(EXIT_FAILURE);
    }
    size_t ret;
    if (size != (ret = fwrite(data, sizeof(char), size, fout))){
        fprintf(stderr, "fwrite() failed: %zu\n", ret);
        exit(EXIT_FAILURE);
    }
}
