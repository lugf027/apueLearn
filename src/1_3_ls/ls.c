//
// Created by lugf027 on 2020/10/27.
//
#include <stdio.h>
#include <dirent.h>
#include "apue.h"

int main(int argc, char *argv[]) {
    DIR *d_p;
    struct dirent *dir_p;

    if(argc != 2)
        err_quit("usage: ls directory_name");

    if((d_p = opendir(argv[1])) == NULL)
        err_sys("can't open %s", argv[1]);

    while((dir_p = readdir(d_p)) != NULL)
        printf("%s\n", dir_p->d_name);

    closedir(d_p);
    exit(0);
}
