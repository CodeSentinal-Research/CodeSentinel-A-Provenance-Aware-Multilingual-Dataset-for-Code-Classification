#include <stdio.h>
int part(int *a, int n, int i, int *sets, int k, int target) { if(i==n) { for(int j=0;j<k;j++) if(sets[j]!=target) return 0; return 1; } for(int j=0;j<k;j++) { if(sets[j]+a[i]<=target) { sets[j]+=a[i]; if(part(a,n,i+1,sets,k,target)) return 1; sets[j]-=a[i]; } } return 0; }
int main() { int n,k; scanf("%d%d",&n,&k); int a[n]; int sum=0; for(int i=0;i<n;i++) { scanf("%d",&a[i]); sum+=a[i]; } if(sum%k!=0) { printf("false\n"); return 0; } int sets[k]={0}; printf("%s\n",part(a,n,0,sets,k,sum/k)?"true":"false"); return 0; }
