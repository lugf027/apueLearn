//
// Created by lugf027 on 2020/10/28.
//

#include "apue.h"
#include <fcntl.h>

/**
 *
 * @param fd file descriptor
 * @param flags file status flags to turn on
 */
void set_fl(int fd, int flags) {
    int val;

    if ((val = fcntl(fd, F_GETFL, 0)) < 0)
        err_sys("fcntl F_GETFL error");

    val |= flags;
    // val &= ~flags; // turn off

    if (fcntl(fd, F_SETFL, val) < 0)
        err_sys("fcntl F_SETFL error");
}
