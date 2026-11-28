#include <stdio.h>
int n,col[20],d1[40],d2[40],cnt=0;
void sl(int r){if(r==n){cnt++;return;}for(int c=0;c<n;c++){if(!col[c]&&!d1[r-c+n]&&!d2[r+c]){col[c]=d1[r-c+n]=d2[r+c]=1;sl(r+1);col[c]=d1[r-c+n]=d2[r+c]=0;}}}
int main(){scanf("%d",&n);sl(0);printf("%d\n",cnt);return 0;}
