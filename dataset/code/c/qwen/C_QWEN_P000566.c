#include <stdio.h>
#include <string.h>
int main() {
    char start[9], end[9]; scanf("%s %s", start, end);
    int n; scanf("%d", &n);
    char bank[n][9];
    for(int i=0; i<n; i++) scanf("%s", bank[i]);
    int queue[1001][2], front=0, rear=0, visited[1001]={0};
    queue[rear][0]=-1; queue[rear][1]=0; rear++;
    while(front<rear) {
        int curr=queue[front][0], steps=queue[front][1]; front++;
        char *word = curr==-1 ? start : bank[curr];
        if(strcmp(word, end)==0) { printf("%d\n", steps); return 0; }
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                int diff=0;
                for(int j=0; j<8; j++) if(word[j]!=bank[i][j]) diff++;
                if(diff==1) { visited[i]=1; queue[rear][0]=i; queue[rear][1]=steps+1; rear++; }
            }
        }
    }
    printf("-1\n");
    return 0;
}
