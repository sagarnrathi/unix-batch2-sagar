#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char *argv[]) {

  unsigned int pid = getpid();
  printf("Parent code...\n");
  printf("[PARENT] My PID is %u\n", pid);
  unsigned int child_pid = fork();
  if (child_pid == 0) {
    /* Only Child enters here */
    printf("Child code...\n");
    unsigned int ppid = getppid();
    unsigned int pid = getpid();
    printf("[CHILD] My PID is %u\n", pid);
    printf("[CHILD] My parent is %u\n", ppid);
    execl("mycp", "mycp", argv[1], argv[2], 0);
  }

  /* Only parent executes this code */
  printf("[PARENT] My child is %u\n", child_pid);
  wait((int*) 0);
  printf("[PARENT] Copy done!\n");
  /* Discreetly exit() */
}
