#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include "filehash.h"

int main(int argc, char* argv[]){
    
    if (argc != 4){
        printf("Error args\n Usage: <file to hash> <password> <file to write a hash>\n");
        return 1;
    }
    int file_size = FileSize(argv[1]);
    printf("[ OK ]\tfile size %d bytes\n", file_size);
    char* data = ReadFromFile(argv[1], file_size);
    printf("[ OK ]\tFinish read from file %s\n", argv[1]);
    char* hash_data = HashData(data, argv[2]);
    printf("[ OK ]\tFinish hash data\n");
    WriteToFile(argv[3], hash_data, file_size);
    printf("[ OK ]\tFinish write hash data to file %s\n", argv[3]);
    
    return 0;
}









