#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "fstack.h"


float rpneval(char input[]) {
	fstack ftop;
	int i = -1;
	int state = 0;
	char temp[10];
	int temp_index = 0;
	float num1, num2, ans;

	init_fstack(&ftop);

	while (1) {
		switch (state) {
			case 0: //starting state
				i++;
				if ((input[i] == '+') || (input[i] == '-') || (input[i] == '*') || (input[i] == '/'))
					state = 1;
				else if (isdigit(input[i]))
					state = 2;
				else if (input[i] == ' ')
					state = 4;
				else if (input[i] == '\0')
					state = 5;
				else
					state = 6;
				break;
			case 1: //found operator
				if (!is_fempty(ftop))
					num2 = fpop(&ftop);
				else {
					printf("Error! No number available\n");
					exit(0);
				}
				if (!is_fempty(ftop))
					num1 = fpop(&ftop);
				else {
					printf("Error! No number available\n");
					exit(0);
				}
				switch (input[i]){
					case '+': ans = num1 + num2;
						break;
					case '-': ans = num1 - num2;
						break;
					case '*': ans = num1 * num2;
						break;
					case '/': if (num2 != 0)
							ans = num1 / num2;
						else {
							printf("Error! Division by Zero\n");
							exit(0);
						}
						break;
					}
					if (!is_ffull())
						fpush(&ftop, ans);
					else {
						printf("Error! Stack is full\n");
						exit(0);
					}
					state = 0;
					break;
			case 2: // found digit
				temp[temp_index] = input[i];
				temp_index++;
				i++;
				if ((input[i] == '.') || (isdigit(input[i])))
					state = 2;
				else
					state = 3;
				break;
			case 3: //found end of number
				temp[temp_index] = '\0';
				sscanf(temp, "%f", &num1);
				if (!is_ffull())
					fpush(&ftop, num1);
				else {
					printf("Error! Stack is full\n");
					exit(0);
				}
				temp_index = 0;
				i--;
				state = 0;
				break;
			case 4: //found space
				state = 0;
				break;
			case 5: //found end of input string
				if (!is_fempty(ftop))
					ans = fpop(&ftop);
				else {
					printf("Error! No number available\n");
					exit(0);
				}
				if (is_fempty(ftop))
					return ans;
				else {
					printf("Error! Invalid Input\n");
					exit(0);
				}
			case 6: //found garbage
				printf("Error! Invalid Input\n");
				exit(0);
		}
	}
}
