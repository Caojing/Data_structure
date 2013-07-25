#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int year, time, hehe;
	char *str="2013 08 23";

	FILE *fp=fopen("first.txt","w");
	
	sscanf(str, "%d\t%d\t%d", &year, &time, &hehe);
	printf("%d\t%d\t%d\n", year, time, hehe);
	fprintf(fp, "%d\t%d\t%d\n", year, time, hehe);
	
	fclose(fp);

	return 0;
}
