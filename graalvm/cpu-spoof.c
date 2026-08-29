#define _GNU_SOURCE

#include <dlfcn.h>
#include <fcntl.h>
#include <stdarg.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

static int (*real_open)(const char *, int, ...) = NULL;
static int (*real_open64)(const char *, int, ...) = NULL;

static void init_functions(void)
{
    if (!real_open)
        real_open = dlsym(RTLD_NEXT, "open");

    if (!real_open64)
        real_open64 = dlsym(RTLD_NEXT, "open64");
}

static const char *redirect_cpuinfo(const char *path)
{
    return path && !strcmp(path, "/proc/cpuinfo")
        ? "/tmp/cpuinfo-spoof"
        : path;
}

int open(const char *path, int flags, ...)
{
    init_functions();
    path = redirect_cpuinfo(path);

    if (flags & O_CREAT) {
        va_list args;
        va_start(args, flags);
        mode_t mode = va_arg(args, mode_t);
        va_end(args);
        return real_open(path, flags, mode);
    }

    return real_open(path, flags);
}

int open64(const char *path, int flags, ...)
{
    init_functions();
    path = redirect_cpuinfo(path);

    if (flags & O_CREAT) {
        va_list args;
        va_start(args, flags);
        mode_t mode = va_arg(args, mode_t);
        va_end(args);
        return real_open64(path, flags, mode);
    }

    return real_open64(path, flags);
}