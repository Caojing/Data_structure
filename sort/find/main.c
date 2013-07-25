#include <stdio.h>
#include <malloc.h>
typedef struct node
{
	int data;
	struct node *next;	
}node_t;
typedef node_t* link;
link head =NULL;
link make_node(int c)
{
	link p=malloc(sizeof(*p));
	p->data=c;
	p->next=NULL;
}
void insert(int c)
{
	link p =make_node(c);
	link q = head;
	link r = NULL;
	if(head == NULL){
		head=p;
		return ;
	}

	for(q=head;q!=NULL;q=q->next){
		if(c > q->data){
			if(q->next && q->next->data >= c){
				p->next=q->next;
				q->next=p;
				break;
			}
			else{
				if(q->next==NULL){
					q->next=p;
					break;
				}
			}
		}
		else{
			if(q==head){
				p->next=head;
				break;
			}		
		}
	}

}
/*
	while(q){
		if(p->data <= head->data){
			p->next = head;
			break;
		}
		else{
			r=q;
			q=q->next;
			p=q;
			if(q->data > r->data && q->data <= r->next->data){
				p->next = r->next;
				r->next = p;
				break;
			}
			if(q == NULL){
				q->next = p;
				break;
			}
		}
	}

}
*/
void print_items()
{
	link p =head;
	while(p){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
int main(void)
{
	int i=0;
	while(1){
		scanf("%d",&i);
		if(i==0){
			break;
		}
		insert(i);
		print_items();
//		break;
	}
	return 0;
	
}
