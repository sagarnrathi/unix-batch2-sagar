#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

char buffer[2048];
int version = 1;

void copy(int old, int new) {
  int num_bytes_read;
  /*
   * copy = read + write
   *
   * copy = read from old and write in new!
   *
   *
   * read(old file descriptor, where to store, how much to read)
   *
   * num_bytes_read = read(old, buffer, 2048)
   *
   * while "number of bytes read" are greater than 0
   *
   * keep writing "these many bytes" into the new file
   *
   * */
  while ((num_bytes_read = read(old, buffer, sizeof(buffer))) > 0) {
    write(new, buffer, num_bytes_read);
  }
}

int main(int argc, char* argv[]) {

  int fdold, fdnew; /* fd: file descriptor */
  
  /*
   * x = 5 // assignment 
   * x = 5 is always true for "conditional statement"
   * if (5 = x) { // 
   * ....
   * }
   *
   *
   * int a;
   *
   * 6 = x; // l value required 
   *
   *
   * 
   * n = n + 1;
   *
   * = assignment operator, right to left
   * n + 1 compute, then copy that in the same memory as "n"
   *
   *
   * a = b // a should have l value, b should have r value
   *
   * */
  if (3 != argc) {

    /* mycopy old_file new_file */
    printf("Need 2 arguments for copy program\n");
    return 1;
  }

  /**
   *  argv
   *
   *     0        1         2
   *  [mycopy,  old_file, new_file]
   *
   *
   *  argv[0] = "mycopy"
   *  argv[1] = "old_file"
   *  argv[2] = "new_file"
   *
   *
   * */
  fdold = open(argv[1], O_RDONLY);
  if (-1 == fdold) {
    printf("Cannot open file %s\n", argv[1]);
    return 1;
  }

  /* 010 = 8 (Octal)
   * 0666 is an octal number
   *
   *
   * 0x10 = 16 
   * 0x is a prefix to define hexadecimal numbers
   *
   *
   * 1 execute
   * 2 read
   * 4 write
   *
   * */
  fdnew = creat(argv[2], 0666);
  if ( -1 == fdnew) {
    printf("Cannot create file %s\n", argv[2]);
    return 1;
  }

  /* Call copy function with two parameters*/
  copy(fdold, fdnew);
  return 0;
}

