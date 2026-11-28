#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    int ids[100000]; char names[100000][50];
    for(int i=0; i<n; i++) scanf("%d %s", &ids[i], names[i]);
    int q; scanf("%d", &q);
    int found = 0;
    for(int i=0; i<n; i++) if(ids[i]==q) { printf("%d %s\n", ids[i], names[i]); found=1; break; }
    if(!found) printf("Member Not Found\n");
    return 0;
}
