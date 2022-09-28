#include <stdio.h>
#include <stdlib.h>
#include "fstack.c"

float rpneval(char input[]);

int main() {
char input [10];
char result;
printf("Enter an equation: \n");
fgets(input,10,stdin);
result = rpneval(input);
printf("result = %s", &result);
return 0;
}
