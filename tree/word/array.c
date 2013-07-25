#include <stdio.h>
char stacka [512];
int topa=0;
int topb=0;
void pusha(char c)
{
        stacka[topa]=c;
        topa++;
}
char popa(void)
{
        topa--;
        return stacka[topa];
}
int is_emptya(void)
{
        return topa == 0;
}
int is_fulla(void)
{
        if(topa>=sizeof(stacka)/sizeof(stacka[0]))
		return 1;
	else
		return 0;
}
char stackb [512];
void pushb(char c)
{
        stackb[topb]=c;
        topb++;
}
char popb(void)
{
        topb--;
        return stackb[topb];
}
int is_emptyb(void)
{
        return topb == 0;
}
int is_fullb(void)
{
	return topb == 512;
//        if(topb>=sizeof(stackb)/sizeof(stackb[0]))
//		return 1;
//	else
//		return 0;
}
/*void enqueue(char c)
{
	if(!is_emptyb){
		pusha(popb());
	}
	else{
		pusha(c);
	}
}
char dequeue(void)
{
	if(!is_emptya()){
		 pushb(popa());
	}
	else{
		return popb();
	}
}*/
int main(void)
{
	if(is_emptya()){
		pusha ('a');
		pusha ('b');
		pusha ('c');
	}
	while(!is_emptya()){
		pushb(popa());
	}
	while(!is_emptyb()){
		putchar (popb());
	}
	putchar('\n');
	return 0;
}



