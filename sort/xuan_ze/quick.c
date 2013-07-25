#include <stdio.h>

int a[8]={10,0,30,15,23,9,16,34};
int partition(int start,int end)
{
	int n = end - start +1;
	int i= 0;
	int tmp[n];
	int k=0;
	int j = 0;
	for(i<0;i<n;i++){
		tmp[i]=a[start+i];
	}
	for(i=1,j=0,k=n-1;i<n;i++) {
		if(tmp[i]<tmp[0]){
			a[start+j]=tmp[i];
			j++;
		}	
		else{
			a[start+k]=tmp[i];
			k--;
		}
	}
	a[start+k]=tmp[0];
	return start+k;
}	
void quicksort(int start, int end)
{
	int i=0;
	int mid;
	if (end > start) {
		mid = partition(start, end);
		quicksort(start, mid-1);
		quicksort(mid+1, end);
		for(i=0;i<8;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
}

int main(void)
{
	quicksort(0,7);
	return 0;
}
