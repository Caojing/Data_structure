#include <stdio.h>

struct unit
{
	char data;
	int bused;
};
typedef struct unit unit_t;
struct unit queue[512];
int head=0,tail=0;
void enqueue(char c)
{
	if(queue[tail].bused == 0){
		queue[tail].data = c;
		queue[tail].bused = 1;
		tail = (tail+1) % 512;
	}
}
char dequeue(void)
{
	char c;
	if(queue[head].bused == 1){
		c=queue[head].data;
		queue[head].bused = 0;
		head = (head+1) % 512;
		return c;
	}
}
int is_empty()
{
	return (head == tail && queue[head].bused == 0);
	
}
int is_full()
{
	return (head == tail && queue[head].bused == 1);
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
