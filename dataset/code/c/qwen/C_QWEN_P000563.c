#include <stdio.h>
#include <string.h>
int main() {
    char begin[11], end[11]; scanf("%s %s", begin, end);
    int n; scanf("%d", &n);
    char dict[n][11];
    for(int i=0; i<n; i++) scanf("%s", dict[i]);
    int queue[5001][2], front=0, rear=0, visited[5001]={0};
    strcpy(dict[n], begin); queue[rear][0]=n; queue[rear][1]=1; rear++; visited[n]=1;
    while(front<rear) {
        int curr=queue[front][0], steps=queue[front][1]; front++;
        char *word=dict[curr];
        if(strcmp(word, end)==0) { printf("%d\n", steps); return 0; }
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                int diff=0;
                for(int j=0; j<strlen(word); j++) if(word[j]!=dict[i][j]) diff++;
                if(diff==1) { visited[i]=1; queue[rear][0]=i; queue[rear][1]=steps+1; rear++; }
            }
        }
    }
    printf("0\n");
    return 0;
}
