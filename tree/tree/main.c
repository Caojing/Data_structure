#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int item;
	struct node *left;
	struct node *right;
}node_t;
typedef node_t * link;
link make_node(unsigned char item)
{
	link p = malloc(sizeof(*p));
	p->item = item;
	p->left = NULL;
	p->right = NULL;
	return p;
}
link init(unsigned char VLR[],unsigned char LVR[],int n )
{
	link t;
	if(n<=0){
		return NULL;
	}
	int k;
	t =make_node(VLR[0]);
	for(k=0;VLR[0] != LVR[k];k++);
	t->left = init(VLR+1,LVR,k);
	t->right = init(VLR+k+1,LVR+k+1,n-k-1);
	return t;
}
/*
link init2(unsigned char LVR[],unsigned char LRV[],int n)
{
	if(n<=0)
		return NULL;
	int k=0;
	link t =make_node(LRV[n-1]);
	for(k=0;LRV[n-1]!= LVR[k];k++);
	t->left = init2(LVR,LRV,k);
	t->right= init2(LVR+k+1,LRV+k,n-k-1);
	return t;
}
*/
link search(link t,unsigned char key)
{
	if(t == NULL)
		return NULL;
	if(t->item == key)
		return t;
	if(t->item < key)
		return search(t->right,key);
	if(t->item > key)
		return search(t->left,key);
}

link insert(link t,unsigned char key)
{
	if(t == NULL){
		link p =make_node(key);
//		printf("%d",p->item);
		return p;
	}
	if(t->item > key){
		t->left = insert(t->left,key);
	}
	
	if(t->item < key){
		t->right = insert(t->right,key);
	}
	return t;
}
void print_tree(link t)
{
	if(t){
		print_tree(t->left);
		printf("%d ",t->item);
		print_tree(t->right);
	}
//	else{
//		printf("()");
//	}
}
link delete_node(link root,unsigned char key)
{
	link s =NULL;
	link p = search(root,key);
	link q =NULL;
	if(p == NULL){
		printf("not found \n");
		return root;
	}
	if(p->left){
		q=p->left;
		if(!(q->right)){
			p->item=q->item;
			p->left = delete_node(q,q->item);
		}
		else{
			while(q->right){
				s=q;
				q=q->right;
			}
			p->item=q->item;
			s->right = delete_node(q,q->item);
		}
		return root;
	}
	else if(p->right){
		q=p->right;
		if(!(q->left)){
			p->item=q->item;
			p->right = delete_node(q,q->item);
		}
		else{
			while(q->left){
				s=q;
				q=q->left;
			}
			p->item=q->item;
			s->left = delete_node(q,q->item);
		}
		return root;
	}
	else{
		free(p);
		return NULL;
	}
}
int main(void)
{
	unsigned char prev_seq[] = {4,2,1,3,6,5,7};
	unsigned char in_seq[] = {1,2,3,4,5,6,7};
//	unsigned char post_seq[]={1,3,2,5,7,6,4};
	link root = init(prev_seq,in_seq,7);
//	link root = init2(in_seq,post_seq,7);
//	printf("root: %d",root->item);
//	putchar('\n');
//	root = insert(root,12);
//	link p = search(root,12);
//	if(p == NULL){
//		printf("not found \n");
//	}
//	else{
//		printf("find: %d",p->item);
//	}
//	putchar('\n');
//	print_tree(root);
//	putchar('\n');
	root=delete_node(root,7);
	print_tree(root);
//	putchar('\n');
	return 0;
}
