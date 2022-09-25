#include <stdio.h>
#include <stdlib.h>
#include "fstack.h"



//initializing the fstack
void init_fstack(fstack *s){
 (*s) = NULL;
}

//Checking to see if fstack is empty
boolean is_fempty(fstack s) {
if (s == NULL)
return TRUE;
else
return FALSE;
}

//Checking to see if fstack is full
boolean is_ffull(void) {
fstack temp;
temp = (fstack) malloc (sizeof(struct fstacknode));
if (temp == NULL)
return TRUE;
else {
free (temp);
return FALSE;
}
}

//fpushing new items on the fstack
void fpush(fstack *s, float x) {
fstack temp;
temp = (fstack) malloc(sizeof(struct fstacknode));
temp -> data = x;
temp -> next = (*s);
(*s) = temp;
}

//fpopping items off the fstack
float fpop(fstack *s){
fstack temp;
float data_fpopped;
temp = *s;
data_fpopped = temp -> data;
*s = temp -> next;
free(temp);
return data_fpopped;
}

//listing contents of the fstack
void print_fstack(fstack s) {
if (!is_fempty(s)){
printf("\n%f\n", s -> data);
print_fstack(s -> next);
}
}
