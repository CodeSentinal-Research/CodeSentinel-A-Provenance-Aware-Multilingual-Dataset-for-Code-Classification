#include <stdio.h>
int match(int *m, int n, int i, int *sides, int target) { if(i==n) return sides[0]==target && sides[1]==target && sides[2]==target; for(int j=0;j<4;j++) { if(sides[j]+m[i]<=target) { sides[j]+=m[i]; if(match(m,n,i+1,sides,target)) return 1; sides[j]-=m[i]; } } return 0; }
int main() { int n; scanf("%d",&n); int m[n]; int sum=0; for(int i=0;i<n;i++) { scanf("%d",&m[i]); sum+=m[i]; } if(sum%4!=0) { printf("false\n"); return 0; } int sides[4]={0}; printf("%s\n",match(m,n,0,sides,sum/4)?"true":"false"); return 0; }
