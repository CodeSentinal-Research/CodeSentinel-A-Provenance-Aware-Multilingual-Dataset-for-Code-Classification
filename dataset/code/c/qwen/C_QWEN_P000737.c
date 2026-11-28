#include <stdio.h>
#include <string.h>
void gen(char *s, int l, int r, int *res, int *idx) { if(l==r) { res[(*idx)++]=atoi(s+l); return; } for(int i=l;i<r;i++) { if(s[i]=='+' || s[i]=='-' || s[i]=='*') { int left[1000], right[1000], li=0, ri=0; char s1[21], s2[21]; strncpy(s1,s+l,i-l); s1[i-l]='\0'; strncpy(s2,s+i+1,r-i-1); s2[r-i-1]='\0'; gen(s1,0,strlen(s1),left,&li); gen(s2,0,strlen(s2),right,&ri); for(int j=0;j<li;j++) for(int k=0;k<ri;k++) { int v=0; if(s[i]=='+') v=left[j]+right[k]; else if(s[i]=='-') v=left[j]-right[k]; else v=left[j]*right[k]; res[(*idx)++]=v; } } } }
int main() { char s[21]; scanf("%s",s); int res[1000], idx=0; gen(s,0,strlen(s),res,&idx); // sort and print return 0; }
