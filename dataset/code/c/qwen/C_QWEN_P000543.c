#include <stdio.h>
#include <string.h>
int main() {
    int q; scanf("%d", &q);
    int intervals[100001][2], count=0;
    while(q--) {
        char op[20]; scanf("%s", op);
        if(strcmp(op, "addNum")==0) {
            int val; scanf("%d", &val);
            intervals[count][0]=val; intervals[count][1]=val; count++;
        } else {
            for(int i=0; i<count; i++) printf("[%d,%d] ", intervals[i][0], intervals[i][1]);
            printf("\n");
        }
    }
    return 0;
}
