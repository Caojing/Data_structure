#include <stdio.h>
#include <malloc.h>
typedef struct node
{
        char data;
        struct node *next;
        struct node *prev;
}node_t;
typedef node_t *link;
link head1=NULL;
link head2=NULL;
link tail1=NULL;
link tail2=NULL;

link make_node1(char c)
{
        link p=malloc(sizeof(*p));
        p->data=c;
        p->prev=NULL;
        p->next=NULL;
        return p;
}
void enqueue1(char c)
{
        link p=NULL;
        p=make_node1(c);
        if(head1 == NULL){
		head1=p;
                tail1=p;
        }
        else{
                p->next=head1;
                head1->prev=p;
                head1=p;
        }

}
char dequeue1(void)
{
        char c;
        link p=NULL;
        if(head1 == tail1){
                c=tail1->data;
                free(tail1);
                head1=tail1=NULL;
        }
        else{
		p=tail1;
                c=p->data;
                tail1=tail1->prev;
                free(p);
                tail1->next=NULL;
        }
        return c;
}
int is_empty1()
{
        return head1 == NULL;
}
int is_full1()
{
        return 0;
}
                           
link make_node2(char c)
{
        link p=malloc(sizeof(*p));
        p->data=c;
        p->prev=NULL;
        p->next=NULL;
        return p;
}
void enqueue2(char c)
{
        link p=NULL;
        p=make_node2(c);
        if(head2 == NULL){
		head2=p;
                tail2=p;
        }
        else{
                p->next=head2;
                head2->prev=p;
                head2=p;
        }

}
char dequeue2(void)
{
        char c;
        link p=NULL;
        if(head2 == tail2){
                c=tail2->data;
                free(tail2);
                head2=tail2=NULL;
        }
        else{
		p=tail2;
                c=p->data;
                tail2=tail2->prev;
                free(p);
                tail2->next=NULL;
        }
        return c;
}
int is_empty2()
{
        return head2 == NULL;
}
int is_full2()
{
        return 0;
}
int is_last1()
{
	if((tail1 == head1) && (tail1!=NULL) && (head1!=NULL)){
		return 1;
	}
	else 
		return 0;
}
int is_last2()
{
	if((tail2 == head2) && (tail2!=NULL) && (head2!=NULL)){
		return 1;
	}
	else 
		return 0;
}
int main(void)
{
	if(is_empty1()){
		enqueue1 ('a');
		enqueue1 ('b');
		enqueue1 ('c');
	}
	unsigned int i=0;
	while((i=is_last1()) == 1){
		putchar(dequeue1());
		enqueue2(dequeue1());
	}

	while((i=is_last2()) == 0){
		putchar(dequeue2());
	}
	return 0;
}
