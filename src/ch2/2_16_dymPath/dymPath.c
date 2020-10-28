//
// Created by lugf027 on 2020/10/28.
//

#include "apue.h"
#include <errno.h>
#include <limits.h>

#ifdef PATH_MAX
static long pathMax = PATH_MAX;
#else
static long pathMax = 0;
#endif

static long posixVersion = 0;
static long xsiVersion = 0;

#define PATH_MAX_GUESS 1024

/**
 * dynamic alloca path's memory
 * @param sizeP allocated size
 * @return
 */
char *pathAlloc(size_t *sizeP) {
    char *ptr;
    size_t size;

    if (posixVersion == 0)
        posixVersion = sysconf(_SC_VERSION);
    if (xsiVersion == 0)
        xsiVersion = sysconf(_SC_XOPEN_VERSION);

    // PATH_MAX not defined
    if (pathMax == 0) {
        errno = 0;
        if ((pathMax = pathconf("/", _PC_PATH_MAX)) < 0) {
            // guess
            if (errno == 0)
                pathMax = PATH_MAX_GUESS;
            else
                err_sys("pathconf error for _PC_PATH_MAX");
        } else {
            // add one here?
            pathMax++;
        }
    }

    // weather end with null (\0)
    if ((posixVersion < 200112L) && (xsiVersion < 4))
        size = pathMax + 1;
    else
        size = pathMax;

    if ((ptr = malloc(size)) == NULL)
        err_sys("malloc error for pathname");

    if (sizeP != NULL)
        *sizeP = size;

    return (ptr);
}
