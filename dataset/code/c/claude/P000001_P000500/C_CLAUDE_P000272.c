#include<stdio.h>
#include<string.h>
int main(){int n;scanf("%d",&n);char w[n][1001];for(int i=0;i<n;i++)scanf("%s",w[i]);char pref[1001];strcpy(pref,w[0]);for(int i=1;i<n;i++){int j=0;while(pref[j]&&w[i][j]&&pref[j]==w[i][j])j++;pref[j]=0;}printf("%s\n",pref);}
