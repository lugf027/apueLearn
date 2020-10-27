//
// Created by lugf027 on 2020/10/27.
//
#include "apue.h"

int main(void){
    printf("process Id: %ld\n", (long)getpid());
    exit(0);
}

/*
 * there are three NB functions used for process control: fork(), exec(), waitpid().
 */
