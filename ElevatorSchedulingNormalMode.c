#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int compare (const void*x,const void *y){
	return (*(int*)x>*(int*)y)-(*(int*)y>*(int*)x);
}
int index(int b[],int n){
	int i=0;
	for(i=0;b[i]!=n;i++);
	return i;
}
void distance(int p[],int k,int l){
	int i,t=0;
	t=2*((p[k]-p[0]>0)?(p[k]-p[0]):p[0]-p[k])+((p[l-1]-p[0]>0)?(p[l-1]-p[0]):(p[0]-p[l-1]));
		printf("\nTotal distance = %d\n\n",t);
}
void scheduler(int a[],int l,int n){
	int b[l],p[l],i,j,k,c,key,m=n,t=0;
	for(i=0;i<l;i++){
		b[i]=a[i];
	}
	qsort(b,l,sizeof(int),compare);
	key=index(b,m);
	for(i=0;i<l;i++){
		if(i<=l-key-1)
			p[i]=b[i+key];
		if(i>l-key-1)
			p[i]=b[l-i-1];
		printf("%d ",p[i]);
	}
			distance(p,l-key-1,l);
	for(i=0;i<l;i++){
		if(i<=key)
			p[i]=b[key-i];
		if(i>key)
			p[i]=b[i];
		printf("%d ",p[i]);
	}
			distance(p,key,l);
}
int main(){
	int n,a[100],i=0,j=0,x;
	char t;
	printf("Enter the initial floor number\n");
	scanf("%d",&n);
	printf("Enter the sequence of floor request\n");
	do{
		scanf("%d%c",&a[i],&t);
		i++;
	}
	while(t!='\n');
	int b[i+1];
	b[0]=n;
	for(j=0;j<i;j++)
	b[j+1]=a[j];
	scheduler(b,i+1,n);
	}
