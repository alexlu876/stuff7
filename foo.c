#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>

void error_check(int k){
  if(!k){
    printf("%s\n", strerror(errno));
    exit(1);
  }
}

int main(){
  struct stat buff;
  int fd;
  fd = open("bar", O_WRONLY | O_TRUNC, 0777);
  int arr[5];
  int i;
  for(i = 0; i < 5; i++){
    arr[i] = i;
  }
  error_check(write(fd, arr, 20));
  close(fd);
  stat("bar", &buff);
  printf("sizeof file: %lu\n", buff.st_size);
  printf("permissions of file: %o\n", (buff.st_mode << 23) >> 23);
  printf("time of last access: %s", ctime(&buff.st_atime));
  return 0;
}
