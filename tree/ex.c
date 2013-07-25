#include <stdio.h>
#include <malloc.h>
typedef struct node
{
	char data;
	struct node *next;
	struct node *prev;
}node_t;
typedef node_t *link;
link head=NULL;
link tail=NULL;

link make_node(char c)
{
	link p=malloc(sizeof(*p));
	p->data=c;
	p->prev=NULL;
	p->next=NULL;
	return p;
}
void enqueue(char c)
{
	link p=NULL;
	p=make_node(c);
	if(head == NULL){
		head=p;
		tail=p;
	}
	else{
		p->next=head;
		head->prev=p;
		head=p;
	}
	
}
char dequeue(void)
{
	char c;
	link p=NULL;
	if(head == tail){
		c=tail->data;
		free(tail);
		head=tail=NULL;
	}
	else{
		p=tail;
		c=p->data;
		tail=tail->prev;
		free(p);
		tail->next=NULL;
	}
	return c;
}
int is_empty()
{
	return head == NULL;
}
int is_full()
{
	return 0;
}
int main()
{
	if(!is_full()){
                enqueue('a');
                enqueue('b');
                enqueue('c');
	  }
        while(!is_empty()){
                putchar(dequeue());
        }
        putchar('\n');
        return 0;

}

