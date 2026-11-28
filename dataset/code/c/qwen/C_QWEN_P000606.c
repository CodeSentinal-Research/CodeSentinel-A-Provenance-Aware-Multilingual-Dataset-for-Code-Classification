#include <stdio.h>
#include <stdlib.h>
int main() {
    int cap, q; scanf("%d %d", &cap, &q);
    int keys[3001], vals[3001], count=0;
    while(q--) {
        char op[10]; scanf("%s", op);
        if(op[0]=='p') { int k, v; scanf("%d %d", &k, &v); int found=-1; for(int i=0;i<count;i++) if(keys[i]==k) { found=i; break; } if(found!=-1) { for(int i=found;i<count-1;i++) { keys[i]=keys[i+1]; vals[i]=vals[i+1]; } count--; } if(count==cap) { for(int i=0;i<count-1;i++) { keys[i]=keys[i+1]; vals[i]=vals[i+1]; } count--; } keys[count]=k; vals[count]=v; count++; }
        else { int k; scanf("%d", &k); int found=-1; for(int i=0;i<count;i++) if(keys[i]==k) { found=i; break; } if(found!=-1) { int v=vals[found]; for(int i=found;i<count-1;i++) { keys[i]=keys[i+1]; vals[i]=vals[i+1]; } count--; keys[count]=k; vals[count]=v; count++; printf("%d\n", v); } else printf("-1\n"); }
    }
    return 0;
}
