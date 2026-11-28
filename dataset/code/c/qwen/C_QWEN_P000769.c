#include <stdio.h>
#include <string.h>
int isScr(char *s1, int l1, int r1, char *s2, int l2, int r2) { if(r1-l1!=r2-l2) return 0; if(strncmp(s1+l1,s2+l2,r1-l1+1)==0) return 1; int count[256]={0}; for(int i=l1;i<=r1;i++) count[s1[i]]++; for(int i=l2;i<=r2;i++) count[s2[i]]--; for(int i=0;i<256;i++) if(count[i]!=0) return 0; for(int i=1;i<r1-l1+1;i++) { if(isScr(s1,l1,l1+i-1,s2,l2,l2+i-1) && isScr(s1,l1+i,r1,s2,l2+i,r2)) return 1; if(isScr(s1,l1,l1+i-1,s2,r2-i+1,r2) && isScr(s1,l1+i,r1,s2,l2,r2-i)) return 1; } return 0; }
int main() { char s1[31], s2[31]; scanf("%s%s",s1,s2); printf("%s\n",isScr(s1,0,strlen(s1)-1,s2,0,strlen(s2)-1)?"true":"false"); return 0; }
