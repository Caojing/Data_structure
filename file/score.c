#include <stdio.h>

typedef struct str
{
	char name[20];
	double chinese;
	double math;
}str;

int main(void)
{
	int i=0;
	str ss[i];	

	FILE *fp=fopen("score.txt", "w");
	if(fp==NULL)
	{
		perror("open file score.txt");
	}

	for(i=0; i<3; i++)
	{	scanf("%s %2f %2f", ss[i].name, ss[i].chinese, ss[i].math);
		fprintf(fp, "%2d %s %2f %2f\n", i+1, ss[i].name, ss[i].chinese, ss[i].math);
	}

	fclose(fp);

	return 0;
}
