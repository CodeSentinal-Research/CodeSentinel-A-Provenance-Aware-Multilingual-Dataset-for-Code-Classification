#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b){return *(int*)a-*(int*)b;}
int main(){int r,c;scanf("%d %d",&r,&c);int a[r*c];for(int i=0;i<r*c;i++)scanf("%d",&a[i]);qsort(a,r*c,sizeof(int),cmp);printf("%d\n",a[(r*c)/2]);}
