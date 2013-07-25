#include <stdio.h>
#include <string.h>
#define LEN 8
int a[LEN] = {3,4,7,2,1,9,8,5};
int part_info(int start,int end)
{
	int i =0;
	int j =0;
	int n = end - start + 1;
	int k = n-1;
	int tmp[n];
	for(i = 0;i< 8;i++){
		tmp[i] = a[start + i];
	}
	for(i = 1,j = 0,k = n-1;i < n;i++){
		if(tmp[i] < tmp[0]){
			a[start + j] = tmp[i];
			j++;
		}
		else{
			a[start + k] = tmp[i];	
			k--;
		}
	}
	a[start + k ] = tmp[0];
	return start + k;
}
void quick_sort(int start, int end)
{
	int i =0;
	if(start < end ){
		int mid = part_info(start,end);
		quick_sort(start, mid-1);
		quick_sort(mid+1,end);
		for(i = 0;i < 8 ; i++){
			printf("%d ",a[i]);
		}
		putchar ('\n');
	}
	
}
int main(void)
{
	quick_sort(0,7);
	return 0;
}
