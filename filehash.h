#ifndef FILEHASH_H
#define FILEHASH_H

int FileSize(char* path_name);
  
char* ReadFromFile(char* path_name, int size);

char* HashData(char* data, char* password);

void WriteToFile(char* path_name, char* data, int size);

#endif
