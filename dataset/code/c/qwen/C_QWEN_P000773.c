#include <stdio.h>
#include <string.h>
int dp[30][30];
int solve(char *s, int l, int r) { if(l>=r) return 1; if(dp[l][r]!=-1) return dp[l][r]; int max=0; for(int i=l+1;i<r;i+=2) { char op=s[i]; int left=solve(s,l,i-1), right=solve(s,i+1,r); int val=0; if(op=='+') val=left+right; else if(op=='-') val=left-right; else val=left*right; if(val>max) max=val; } return dp[l][r]=max; }
int countMax(char *s, int l, int r, int target) { if(l>=r) return s[l]-'0'==target?1:0; int total=0; for(int i=l+1;i<r;i+=2) { char op=s[i]; for(int lv=0;lv<=1000;lv++) for(int rv=0;rv<=1000;rv++) { int val=0; if(op=='+') val=lv+rv; else if(op=='-') val=lv-rv; else val=lv*rv; if(val==target) total+=countMax(s,l,i-1,lv)*countMax(s,i+1,r,rv); } } return total; }
int main() { char s[31]; scanf("%s",s); memset(dp,-1,sizeof(dp)); int max=solve(s,0,strlen(s)-1); printf("%d\n",countMax(s,0,strlen(s)-1,max)); return 0; }
