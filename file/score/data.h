#ifndef DATA_H_
#define DATA_H_

#include <stdio.h>
typedef struct stu
{
	char name[20];
	float chinese;
	float math;
	float aver;
} Chengji;
void read_file(Chengji *a,int * p);
void print_info(Chengji *a,int *p);
void sort_info(Chengji *a,int *p);
void insert_info(Chengji* a,int *p);
void delete_info(Chengji* a,int *p);
void save_info(Chengji* a,int *p);
void cp_info(Chengji *p,Chengji *q);
#endif //DATA_H
