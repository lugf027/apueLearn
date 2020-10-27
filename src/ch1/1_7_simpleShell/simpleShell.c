//
// Created by lugf027 on 2020/10/27.
//

#include "apue.h"
#include <sys/wait.h>

int main(void){
    char buf[MAXLINE];    // apue.h
    pid_t pid;
    int status;

    printf("%% ");  // it will print one '%' finally
    while (fgets(buf, MAXLINE, stdin) != NULL){
        if(buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = 0;
        if((pid = fork()) < 0){
            err_sys("fork error");
        }else if(pid == 0){
            execlp(buf, buf, (char*)0);
            err_ret("execute error: %s", buf);
            exit(127);
        }

        // parent
        if((pid = waitpid(pid, &status, 0)) < 0)
            err_sys("waitpid error");
        printf("%% ");
    }

    exit(0);
}
