#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char ** parse_args( char * line );

int main() {
  char * test = "ls -a -l";
  char ** p = parse_args(test);
  execvp("bin/ls", p);
  return 0;
}

char ** parse_args(char * line) {
  char * temp = strsep(line, " ");
  char * arr[5];
  int i = 0;
  while(temp != NULL) {
    arr[i] = temp;
    temp = strsep(line, " ");
    i++;
  }
  return arr;
}
