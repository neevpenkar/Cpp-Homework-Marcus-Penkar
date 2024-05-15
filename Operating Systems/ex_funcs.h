#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int writeToFile(char* path, char* data, int len) {
//   int fdw = open(path, O_CREAT | O_WRONLY);
  
  int fdw = open(path, O_RDWR | O_CREAT);
  if (len == -1) len = strlen(data);
  if (fdw == -1) {
    printf("Failed to create file!\n");
    exit(-1);
  }
  write(fdw, data, len);
  close(fdw);
}

int readFromFile(char* path, char* buffer, unsigned int maxLen) {
  int fdw = open(path, O_RDONLY);
  if (fdw == -1) {
    printf("Failed to read from file!\n");
    exit(-1);
  }
  read(fdw, buffer, maxLen);
  close(fdw);
}

void makeFolder(char* folderName) { 
  char* args[] = {"mkdir",folderName, NULL};
  int pid = fork();
  if(pid == 0) execvp("mkdir", args);
}