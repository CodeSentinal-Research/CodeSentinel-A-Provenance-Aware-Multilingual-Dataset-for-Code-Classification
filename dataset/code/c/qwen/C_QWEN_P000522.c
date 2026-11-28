#include <stdio.h>
#include <string.h>
int main() {
    char home[101]; scanf("%s", home);
    int q; scanf("%d", &q);
    char history[100001][101]; int curr=0, max_idx=0;
    strcpy(history[0], home);
    while(q--) {
        char op[20]; scanf("%s", op);
        if(strcmp(op, "visit")==0) {
            char url[101]; scanf("%s", url);
            curr++; strcpy(history[curr], url); max_idx=curr;
        } else if(strcmp(op, "back")==0) {
            int steps; scanf("%d", &steps);
            curr = curr-steps > 0 ? curr-steps : 0;
            printf("%s\n", history[curr]);
        } else if(strcmp(op, "forward")==0) {
            int steps; scanf("%d", &steps);
            curr = curr+steps < max_idx ? curr+steps : max_idx;
            printf("%s\n", history[curr]);
        }
    }
    return 0;
}
