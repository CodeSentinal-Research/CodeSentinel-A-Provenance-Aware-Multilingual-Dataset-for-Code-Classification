#include<stdio.h>
#include<string.h>
int isValid(char*s){int cnt=0;for(int i=0;s[i];i++){if(s[i]=='(')cnt++;else if(s[i]==')')if(--cnt<0)return 0;}return cnt==0;}
char found[10000][1001];int fc=0;
void bfs(char*start){
    char q[100000][1001];int head=0,tail=0;int vis[100000];int vc=0;
    strcpy(q[tail++],start);
    int level=1;char lq[100000][1001];int lc=0;
    while(head<tail){
        char*cur=q[head++];
        if(isValid(cur)){strcpy(found[fc++],cur);level=0;}
        if(!level)continue;
        int n=strlen(cur);
        for(int i=0;i<n;i++){
            if(cur[i]!='('&&cur[i]!=')')continue;
            char nxt[1001];strcpy(nxt,cur);memmove(nxt+i,nxt+i+1,n-i);
            int dup=0;for(int k=0;k<tail;k++)if(strcmp(q[k],nxt)==0){dup=1;break;}
            if(!dup)strcpy(q[tail++],nxt);
        }
    }
}
int main(){char s[1001];scanf("%s",s);bfs(s);if(!fc)printf("\"\"\n");else for(int i=0;i<fc;i++)printf("%s\n",found[i]);}
