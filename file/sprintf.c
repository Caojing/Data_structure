#include <stdio.h>

int main(void)
{
	FILE *fp= NULL;
//	fp=fopen("first.txt","w");
	int i='0';
	char *p=NULL;
	char str[20]={'\0'};

	sprintf(str,"%c\n",i);

	printf("%s\n",str);
	printf("%d\n",i);
//	fclose(fp);

	return 0;
}
