#include<stdio.h>
#define MAX 100
int main() {
	int i,j,arr[MAX],n,k;
	scanf("%d %d",&n,&arr[0]);
	for(i=1;i<n;++i) {
		scanf("%d",&arr[i]);
		k=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>k) {
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=k;
	}
	for(i=0;i<n;++i)
		printf("%d ",arr[i]);
	printf("\n");
}
