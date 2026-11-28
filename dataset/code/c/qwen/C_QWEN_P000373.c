#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    int codes[100000]; char names[100000][50];
    for(int i=0; i<n; i++) scanf("%d %s", &codes[i], names[i]);
    int q; scanf("%d", &q);
    int found = 0;
    for(int i=0; i<n; i++) if(codes[i]==q) { printf("%d %s\n", codes[i], names[i]); found=1; break; }
    if(!found) printf("Product Not Found\n");
    return 0;
}
