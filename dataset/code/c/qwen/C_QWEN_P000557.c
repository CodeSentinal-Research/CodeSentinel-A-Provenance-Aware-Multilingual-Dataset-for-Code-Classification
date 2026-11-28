#include <stdio.h>
int main() {
    int target; scanf("%d", &target);
    int queue[100001][2], front=0, rear=0, visited[20001]={0};
    queue[rear][0]=0; queue[rear][1]=1; rear++; visited[10000]=1;
    int moves=0;
    while(front<rear) {
        int size=rear-front;
        for(int k=0; k<size; k++) {
            int pos=queue[front][0], spd=queue[front][1]; front++;
            if(pos==target) { printf("%d\n", moves); return 0; }
            int npos=pos+spd, nspd=spd*2;
            if(npos>=0 && npos<20001 && !visited[npos+10000]) { visited[npos+10000]=1; queue[rear][0]=npos; queue[rear][1]=nspd; rear++; }
            nspd=spd>0?-1:1;
            if(!visited[pos+10000]) { visited[pos+10000]=1; queue[rear][0]=pos; queue[rear][1]=nspd; rear++; }
        }
        moves++;
    }
    return 0;
}
