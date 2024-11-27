#ifndef USERPROG_PROCESS_H
#define USERPROG_PROCESS_H

#include "threads/thread.h"

tid_t process_create_initd (const char *file_name);
tid_t process_fork (const char *name, struct intr_frame *if_);
//tid_t process_fork (const char *name, struct intr_frame *if_ UNUSED);
int process_exec (void *f_name);
int process_wait (tid_t);
void process_exit (void);
void process_activate (struct thread *next);

void argument_stack(char **argv, int argc, struct intr_frame *if_);
/**project2 - system call */
struct thread *get_child_process(int pid);
int process_add_file(struct file *f);
struct file *process_get_file(int fd);
int process_close_file(int fd);
//int process_insert_file(int fd, struct file *f);

/**project3 - anonymous page */
struct container
{
  struct file *file;
  off_t offset;
  size_t page_read_bytes;
};


#endif /* userprog/process.h */
