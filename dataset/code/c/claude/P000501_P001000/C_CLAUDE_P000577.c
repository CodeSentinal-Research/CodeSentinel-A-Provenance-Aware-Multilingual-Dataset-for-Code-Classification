/* P000577: Binary Tree Bottom View */
#include<stdio.h>
#include<string.h>
#define MAXN 10001
int val[MAXN],has[MAXN];
int qi[MAXN*2],ql[MAXN*2],qh_[MAXN*2],qt2=0,qh2=0;
int bval[20001],blev[20001],bhas[20001];
int main(){char tok[20];int n=0;
    while(scanf("%s",tok)==1){if(strcmp(tok,"null")==0){has[n]=0;val[n]=0;}else{has[n]=1;val[n]=atoi(tok);}n++;}
    if(n==0||!has[0])return 0;
    qi[qt2]=0;ql[qt2]=0;qh_[qt2]=10000;qt2++;
    while(qh2<qt2){int idx=qi[qh2],lev=ql[qh2],hd=qh_[qh2];qh2++;
        if(idx>=n||!has[idx])continue;
        if(!bhas[hd]||lev>=blev[hd]){bval[hd]=val[idx];blev[hd]=lev;bhas[hd]=1;}
        if(2*idx+1<n){qi[qt2]=2*idx+1;ql[qt2]=lev+1;qh_[qt2]=hd-1;qt2++;}
        if(2*idx+2<n){qi[qt2]=2*idx+2;ql[qt2]=lev+1;qh_[qt2]=hd+1;qt2++;}}
    int mn=10000,mx=10000;for(int i=0;i<20001;i++)if(bhas[i]){if(i<mn)mn=i;if(i>mx)mx=i;}
    for(int i=mn;i<=mx;i++)if(bhas[i])printf("%d ",bval[i]);printf("\n");}
