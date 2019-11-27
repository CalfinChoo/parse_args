#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char ** parse_args( char * line ) {
  char ** arr = malloc(5 * sizeof(char *));
  int i = 0;
  while(line != NULL) {
    arr[i] = strsep(&line, " ");
    i++;
  }
  arr[i] = NULL;
  return arr;
}

int main() {
  char a[50] = "ls -l -a";
  char ** args = parse_args(a);
  execvp(args[0], args);
  free(args);
  return 0;
}
