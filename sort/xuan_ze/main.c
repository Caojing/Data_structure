#include <stdio.h>
/*
int main(void)
{
	int i=0;
	int j=0;
	int ss[10]={1,3,6,4,7,8,5,9,10,2};
	int tmp = 0;
	for(i=0;i<10;i++){
	int m=0;
		for(j=0;j<10-i;j++){
			if(ss[m]<ss[j]){
				m = j;
			}
			if(m != (j - 1)){
				tmp = ss[m];
				ss[m] = ss[j-1];
				ss[j-1] = tmp;
			}
		}
	}
	i = 0;
	for(i=0;i<10;i++){
		printf("%d\n",ss[i]);
	}
	return 0;
}
*/
int main(void)
{
	int a[10]={2,1,4,7,5,6,3,10,8,9};
	int i = 0;
	int j = 0;
	int tmp = 0;
	for(i=0;i<10;i++){
		for(j=0;j<9;j++){
			if(a[j]<a[j+1]){
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}	
		}
	}
	for(i=0;i<10;i++){
		printf("%d\n",a[i]);
	}
	return 0;
}
