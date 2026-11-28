#include <stdio.h>
#include <string.h>
int main() {
    int n, m; scanf("%d %d", &n, &m);
    char logs[m][100];
    for(int i=0; i<m; i++) scanf("%s", logs[i]);
    int res[101]={0}, stack[1001], top=-1, prev_time=0;
    for(int i=0; i<m; i++) {
        int id, time; char type[10];
        sscanf(logs[i], "%d:%[^:]:%d", &id, type, &time);
        if(strcmp(type, "start")==0) {
            if(top>=0) res[stack[top]] += time - prev_time;
            stack[++top]=id; prev_time=time;
        } else {
            res[id] += time - prev_time + 1;
            top--; prev_time=time+1;
        }
    }
    for(int i=0; i<n; i++) printf("%d%c", res[i], i==n-1?'\n':' ');
    return 0;
}
