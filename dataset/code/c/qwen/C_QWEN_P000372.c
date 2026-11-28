#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    int rolls[100000]; char names[100000][50];
    for(int i=0; i<n; i++) scanf("%d %s", &rolls[i], names[i]);
    int q; scanf("%d", &q);
    int found = 0;
    for(int i=0; i<n; i++) if(rolls[i]==q) { printf("%d %s\n", rolls[i], names[i]); found=1; break; }
    if(!found) printf("Record Not Found\n");
    return 0;
}
