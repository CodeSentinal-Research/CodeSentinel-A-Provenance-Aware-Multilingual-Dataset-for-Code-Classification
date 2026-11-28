#include<stdio.h>
#include<string.h>
int q1[10001],q2[10001],h1=0,t1=0,h2=0,t2=0;
void push(int x){while(h1<t1)q2[t2++]=q1[h1++];q2[t2++]=x;while(h2<t2)q1[t1++]=q2[h2++];h1=h1;h2=t2=0;}
int pop(){return q1[h1++];}
int top(){return q1[h1];}
int empty(){return h1==t1;}
int main(){int n;scanf("%d",&n);while(n--){char cmd[10];scanf("%s",cmd);if(!strcmp(cmd,"push")){int x;scanf("%d",&x);push(x);}else if(!strcmp(cmd,"pop"))printf("%d\n",pop());else if(!strcmp(cmd,"top"))printf("%d\n",top());else printf("%d\n",empty());}}
