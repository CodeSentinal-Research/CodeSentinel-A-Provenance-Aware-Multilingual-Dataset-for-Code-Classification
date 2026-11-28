#include <stdio.h>
#include <string.h>
int main() {
    int d; scanf("%d", &d);
    char deadends[d][5];
    for(int i=0; i<d; i++) scanf("%s", deadends[i]);
    char target[5]; scanf("%s", target);
    int queue[10000][4], front=0, rear=0, visited[10000]={0};
    queue[rear][0]=0; queue[rear][1]=0; queue[rear][2]=0; queue[rear][3]=0; rear++;
    visited[0]=1; int moves=0;
    while(front<rear) {
        int size=rear-front;
        for(int k=0; k<size; k++) {
            int curr[4]={queue[front][0], queue[front][1], queue[front][2], queue[front][3]}; front++;
            int num=curr[0]*1000+curr[1]*100+curr[2]*10+curr[3];
            char s[5]; sprintf(s, "%d%d%d%d", curr[0], curr[1], curr[2], curr[3]);
            int is_dead=0;
            for(int i=0; i<d; i++) if(strcmp(s, deadends[i])==0) is_dead=1;
            if(is_dead) continue;
            if(strcmp(s, target)==0) { printf("%d\n", moves); return 0; }
            for(int i=0; i<4; i++) {
                for(int dir=-1; dir<=1; dir+=2) {
                    int next[4]={curr[0], curr[1], curr[2], curr[3]};
                    next[i]=(next[i]+dir+10)%10;
                    int nnum=next[0]*1000+next[1]*100+next[2]*10+next[3];
                    if(!visited[nnum]) { visited[nnum]=1; queue[rear][0]=next[0]; queue[rear][1]=next[1]; queue[rear][2]=next[2]; queue[rear][3]=next[3]; rear++; }
                }
            }
        }
        moves++;
    }
    printf("-1\n");
    return 0;
}
