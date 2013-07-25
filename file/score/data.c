#include <stdio.h>
#include "data.h"
#include <string.h>
void read_file(Chengji* a, int * p)
{
	printf("read_file()...\n");
	int i=0;
	char content[100]={'\0'};
	FILE *fp=fopen("score.txt","r");
        if(fp==NULL){
                perror("open file score.txt");
        }
        while(fgets(content,100,fp)){
			sscanf(content+3,"%s %f %f %f",a[i].name,&a[i].chinese,\
                                &a[i].math,&a[i].aver);

			i++;
        }
	*p = i;
        fclose(fp);
}
void print_info(Chengji *a,int *p)
{
	printf("print_info()...\n");
	int i = 0;
	for(i = 0;i < *p;i++){
		printf("%2d %s %2.1f %2.1f %2.1f\n",i+1,a[i].name,a[i].chinese,\
                                a[i].math,a[i].aver);

	}
	
}
void sort_info(Chengji *a,int *p)
{
	printf("sort_info()...\n");
	Chengji b;
	int i = 0,j = 0;
	for(i= 0;i < *p-1;i++){
		for(j = i;j < *p-i-1;j++){
			if(a[j].aver>a[j+1].aver){
				cp_info(&b,a+j);
				cp_info(a+j,a+j+1);
				cp_info(a+j+1,&b);
			}
		}
	}
}
void cp_info(Chengji *p,Chengji *q)
{
	strcpy(p->name,q->name);
	p->chinese=q->chinese;
	p->math=q->math;
	p->aver=q->aver;
}
void insert_info(Chengji *a,int *p)
{
	printf("insert_info()...\n");
	int i=*p;
	printf("please input new name: \n");
	scanf("%s",a[i].name);
	printf("input new chinese ,new math:\n");
	scanf("%f,%f",&a[i].chinese,&a[i].math);
	a[i].aver=(a[i].chinese+a[i].math)/2;
	printf("%2d %s %2.1f %2.1f %2.1f\n",i+1,a[i].name,a[i].chinese,\
				a[i].math,a[i].aver);
	*p = *p + 1;
}
void delete_info(Chengji *a,int * p)
{
	printf("delete_info()...\n");
	char name[20]={'\0'};
	int i=0,j=0;
	printf("please input new name :\n");
	scanf("%s",name);
	for(i=0;i<*p;i++){
		if(strcmp(name,a[i].name)==0){
			for(j=i;j<*p-1;j++){
				cp_info(a+j,a+j+1);
			}
		*p=*p-1;
		return ;
		}
	}
	printf("%s not been found \n",name);
}
void save_info(Chengji *a,int *p)
{
	printf("save_info()...\n");
	int i=0;
	FILE *fp=fopen("score.txt","w");
        if(fp==NULL){
                perror("open file score.txt");
        }
        for(i=0;i<*p;i++){
                fprintf(fp,"%2d %s %2.1f %2.1f %2.1f\n",i+1,\
                        a[i].name,a[i].chinese,a[i].math,a[i].aver);
        }
        fclose(fp);
}
