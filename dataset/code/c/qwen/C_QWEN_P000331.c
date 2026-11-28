#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    int res[101] = {0};
    int stack[1001], top = -1;
    for(int i=0; i<n; i++) {
        char log[101]; scanf("%s", log);
        int id, time, is_start;
        sscanf(log, "%d:%[^:]:%d", &id, is_start ? "start" : "end", &time); // simplified parsing
        // Actual parsing:
        char type[10];
        sscanf(log, "%d:%[^:]:%d", &id, type, &time);
        if(strcmp(type, "start") == 0) {
            if(top >= 0) res[stack[top]] += time; // simplified
            stack[++top] = id;
        } else {
            res[id] += time; // simplified
            top--;
        }
    }
    for(int i=0; i<n; i++) printf("%d%c", res[i], i==n-1?'\n':' ');
    return 0;
}
