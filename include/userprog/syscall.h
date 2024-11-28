#ifndef USERPROG_SYSCALL_H
#define USERPROG_SYSCALL_H

/**project2 - system call */
#include <stdbool.h>

typedef int pid_t;
typedef int off_t;
//typedef int32_t off_t;

#ifndef VM
void check_address(void *addr);
#else
/**project3 - anonymous page */
struct page *check_address(void *addr);
#endif

void halt(void);
void exit(int status);
bool create(const char *file, unsigned initial_size);
bool remove(const char *file);

void syscall_init (void);

int open(const char *file);
int filesize(int fd);
int read(int fd, void *buffer, unsigned length);
int write(int fd, const void *buffer, unsigned length);
void seek(int fd, unsigned position);
int tell(int fd);
void close(int fd);

#endif /* userprog/syscall.h */
