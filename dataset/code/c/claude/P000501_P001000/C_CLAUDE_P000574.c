/* P000574: Binary Tree Right Side View */
#include<stdio.h>
#include<string.h>
#define MAXN 10001
int val[MAXN],has[MAXN];
int q[MAXN*2],ql[MAXN*2],qh=0,qt=0;
int right_view[MAXN],max_lev=0;
int main(){char tok[20];int n=0;
    while(scanf("%s",tok)==1){if(strcmp(tok,"null")==0){has[n]=0;val[n]=0;}else{has[n]=1;val[n]=atoi(tok);}n++;}
    if(n==0||!has[0])return 0;
    q[qt]=0;ql[qt]=0;qt++;
    while(qh<qt){int idx=q[qh],lev=ql[qh];qh++;
        if(idx>=n||!has[idx])continue;
        right_view[lev]=val[idx];if(lev>max_lev)max_lev=lev;
        int l=2*idx+1,r=2*idx+2;
        if(l<n){q[qt]=l;ql[qt]=lev+1;qt++;}
        if(r<n){q[qt]=r;ql[qt]=lev+1;qt++;}}
    for(int i=0;i<=max_lev;i++)printf("%d%c",right_view[i],i<max_lev?' ':'\n');}
