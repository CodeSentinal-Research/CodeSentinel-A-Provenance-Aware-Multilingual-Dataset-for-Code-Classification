#include <stdio.h>
#include <string.h>
int main() {
    char s[100001]; int min_j, max_j; scanf("%s %d %d", s, &min_j, &max_j);
    int n=strlen(s);
    int queue[100001], front=0, rear=0, visited[100001]={0};
    queue[rear++]=0; visited[0]=1;
    int reach_max=0;
    while(front<rear) {
        int curr=queue[front++];
        if(curr==n-1) { printf("true\n"); return 0; }
        int start=curr+min_j > reach_max+1 ? curr+min_j : reach_max+1;
        int end=curr+max_j < n-1 ? curr+max_j : n-1;
        for(int i=start; i<=end; i++) {
            if(s[i]=='0' && !visited[i]) { visited[i]=1; queue[rear++]=i; }
        }
        if(end>reach_max) reach_max=end;
    }
    printf("false\n");
    return 0;
}
