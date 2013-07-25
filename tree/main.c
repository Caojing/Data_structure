#include <stdio.h>
char stack[512];
int top=0;
void push(char c)
{
	stack[top]=c;
	top++;
}
char pop(void)
{
	top--;
	return stack[top];
}
int is_empty(void)
{
	return top == 0;
}
int is_full(void)
{
	return top == 512;
}
int main(void)
{
	if(!is_full)
	{
		push 'a';
		push 'b';
		push 'c';
	}
	while(!is_empty)
		putchar(pop());
	putchar('\n');
	return 0;
}
