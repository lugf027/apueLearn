//
// Created by lugf027 on 2020/10/27.
//

#include "apue.h"
#include <sys/wait.h>

static void sigInt(int);

int main(void) {
    char buf[MAXLINE];    // apue.h
    pid_t pid;
    int status;

    if (signal(SIGINT, sigInt) == SIG_ERR)
        err_sys("signal error");

    printf("%% ");  // it will print one '%' finally
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0;
        if ((pid = fork()) < 0) {
            err_sys("fork error");
        } else if (pid == 0) {     // child
            execlp(buf, buf, (char *) 0);
            err_ret("execute error: %s", buf);
            exit(127);
        }

        // parent
        if ((pid = waitpid(pid, &status, 0)) < 0)
            err_sys("waitpid error");
        printf("%% ");
    }

    exit(0);
}

void sigInt(int signo) {
    printf("interrupt\n%% ");
}
