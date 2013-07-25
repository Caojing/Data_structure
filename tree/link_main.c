#include <stdio.h>
#include <malloc.h>
typedef struct node
{
	char data;
	struct node *next;
}node_t;
typedef node_t * link;
static link head=NULL;
static link make_node(char c)
{
	link p=malloc(sizeof(*p));
	p->data=c;
	p->next=NULL;
	return p;
}
void push(char c)
{
	link p=make_node(c);
	if(head == NULL){
		head=p;
	}
	else{
		p->next=head;
		head=p;
	}
}
char pop(void)
{
	char c=0;
	link p=head;
	head=head->next;
	c=p->data;
	free(p);
	return c;
}
int is_empty(void)
{
	return head == NULL;
}
int is_full(void)
{
	return 0;
}
int main(void)
{
	push ('a');
        push ('b');
        push ('c');
        while(!is_empty())
                putchar(pop());
        putchar('\n');
	return 0;
}
