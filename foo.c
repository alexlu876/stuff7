#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <errno.h>

int main(){
  struct stat buff;
  stat("bar", &buff);
  printf("sizeof file: %lu\n", buff.st_size);
  printf("permissions of file: %o\n", (buff.st_mode << 23) >> 23);
  printf("time of last access: %s", ctime(&buff.st_atime));
  return 0;
}
