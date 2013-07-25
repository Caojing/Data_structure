#include <stdio.h>
int a[8]={5,2,4,7,1,3,2,6};
void merge(int start,int mid,int end)
{
	int i= 0;
	int j = 0;
	int k = 0;
	int n1 = mid - start + 1 ;
	int n2 = end - start ;
	int left[n1];
	int right[n2];
	for(i= 0;i<n1;i++)
		left[i]=a[start+i];
	for(j=0;j<n2;j++)
		right[j]=a[mid + 1 + j];
	k = start;
	i = 0;
	j = 0;
	while(i < n1 && j < n2){
/*		if(left[i]>right[j]){
			a[k]= right[j];
			j++;
			k++;
		}
		else{
			a[k]=left[i];
			i++;
			k++;
		}
*/
		a[k++] = (left[i] > right[j]) ? right[j++] : left[i++];
	}
	while(i < n1){
		a[k++] = left[i++];
	}
	while(j < n2){
		a[k++] = right[j++];
	}
	
}
void sort(int start,int end)
{
	int i = 0;
	if(start < end){
		int mid = (start + end ) / 2;
		sort(start,mid);
		sort(mid+1,end);
		for(i = 0;i<8;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		merge(start,mid,end);
		for(i = 0;i<8;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
	}
}
int main(void)
{
	sort(0,7);
	return 0;
}
