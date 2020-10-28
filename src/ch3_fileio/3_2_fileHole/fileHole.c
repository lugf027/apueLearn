//
// Created by lugf027 on 2020/10/28.
//

#include "apue.h"
#include <fcntl.h>

char    buf1[] = "abcdefghij";
char    buf2[] = "ABCDEFGHIJ";

int main(void){
    int fd;

    if((fd = creat("file.hole", FILE_MODE)) < 0)
        err_sys("create error");

    if(write(fd, buf1, 10) != 10)
        err_sys("buf1 write error");
    // offset now should be 10

    if(lseek(fd, 16384, SEEK_SET) == -1)
        err_sys("lseek error");
    // offset now should be 16384

    if(write(fd, buf2, 10) != 10)
        err_sys("buf2 write error");
    // offset now should be 16934

    exit(0);
}

/*
 $ cat file.hole
abcdefghijABCDEFGHI

 $ ls -l file.hole
-rw-r--r-- 1 sysy sysy 16394 10月 28 22:00 file.hole

 $ od -c file.hole
0000000   a   b   c   d   e   f   g   h   i   j  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0  \0
*
0040000   A   B   C   D   E   F   G   H   I   J
0040012
 $
 */
