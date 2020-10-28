//
// Created by lugf027 on 2020/10/28.
//

#include "apue.h"
#include <errno.h>
#include <limits.h>

#ifdef OPEN_MAX
static long openMax = OPEN_MAX;
#else
static long openMax = 0;
#endif

#define OPEN_MAX_GUESS 256

long openMaxNum(void) {
    if (openMax == 0) {
        errno = 0;

        if ((openMax = sysconf(_SC_OPEN_MAX)) < 0) {
            if (errno == 0)
                openMax = OPEN_MAX_GUESS;
            else
            err_sys("sysconf error for _SC_OPEN_MAX");
        }
    }
    return (openMax);
}

int main(void){
    printf("%ld", openMaxNum());
    exit(0);
}
