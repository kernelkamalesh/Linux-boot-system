#ifndef SYSCALL_H
#define SYSCALL_H

long write(long fd, const void *buf, long count);
long read(long fd, void *buf, long count);
void exit(long status);
long getcwd(char *buf, unsigned long size);
long chdir(const char *path);

#endif  