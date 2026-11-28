#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char brands[100000][50], names[100000][50];
    for(int i=0; i<n; i++) scanf("%s %s", brands[i], names[i]);
    char q[50]; scanf("%s", q);
    int found = 0;
    for(int i=0; i<n; i++) if(strcmp(brands[i], q)==0) { printf("%s %s\n", brands[i], names[i]); found=1; }
    if(!found) printf("No Products Found\n");
    return 0;
}
