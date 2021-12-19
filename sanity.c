#include "types.h"
#include "stat.h"
#include "user.h"


int main(int argc, char *argv[]) {
  int ns;
  if (fork() == 0) {
    ns = set_pid_ns(1); // i set this as a syscall
    printf(1, "namespace=%d\n", ns);
    ps();
  } else {
    wait();
    printf(1, "\nnamespace=0\n");
    ps();
  }
  exit();
}