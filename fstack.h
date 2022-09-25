#ifndef FSTACK_H
#define FSTACK_H

#include "boolean.h"

//defining types
typedef struct fstacknode {
float data;
struct fstacknode *next;
} *fstack;

//initializing fstack
void init_fstack(fstack *);

//checking to see if fstack is empty
boolean is_fempty(fstack);

//checking if fstack is full
boolean is_ffull(void);

//fpushing new items on the fstack
void fpush(fstack *, float);

//fpopping items off the fstack
float fpop(fstack *);

//listing contents of the fstack (without dumping them)
void print_fstack(fstack);

#endif
