#include <stdio.h>
#include <string.h>

typedef struct str
{
	char name[20];
	float chinese;
	float  math;
	float  aver;
}str;

int main(void)
{
	int k=0;
	int i=0;
	str a[10];

//	FILE *fp=fopen("score.txt","w");
//	if(fp==NULL){
//		perror("open file score.txt");
//	}
	for(i=0; i<10; i++)
	{
/*		strcpy(a.name,"wanghai");
		a.chinese=32.0;
		a.math=34.0;*/
		printf("please input number:(wang)\n");
		scanf("%s",a[i].name);

		if(strstr(a[i].name,"$")!=NULL)
		{
			break;
		}

		getchar();
		printf("please input (12 23)\n");
		scanf("%f,%f",&a[i].chinese,&a[i].math);

		a[i].aver=(a[i].chinese+a[i].math)/2;
		printf("%2d %s %2.1f %2.1f %2.1f\n",i+1,\
		a[i].name,a[i].chinese,a[i].math,a[i].aver);
//		fprintf(fp,"%2d %s %2.1f %2.1f %2.1f\n",i+1,\
			a.name,a.chinese,a.math,a.aver);
	}
	printf("%d\n",i);

	int j=0;

	FILE *fp=fopen("score.txt","w");
	if(fp==NULL){
		perror("open file score.txt");
	}
	
	for(j=0; j<i; j++)
	{
		fprintf(fp,"%2d %s %2.1f %2.1f %2.1f\n",j+1,\
			a[j].name,a[j].chinese,a[j].math,\
			a[j].aver);	
	}

	fclose(fp);

	FILE *fp1=fopen("score.txt","r");
	if(fp1==NULL)
	{
		perror("open file score.txt");
	}

	while(fgets(a, 100, fp1) != NULL)
	{
//		for(k=0;k<i;k++){
			sscanf(a, "%s %2.1f %2.1f %2.1f\n", a[i].name, &a[i].chinese, &a[i].math, \
							&a[i].aver);	
		}
			printf("%s\n", a);
	}

	fclose(fp1);
	
	return 0;
}

