#include<stdio.h>
#include<string.h>
int main(){int n;scanf("%d\n",&n);char w[1001];for(int i=0;i<n;i++){fgets(w,sizeof(w),stdin);w[strcspn(w,"\n")]=0;if(strlen(w)==0){printf("%d\n",i);return 0;}}printf("-1\n");}
