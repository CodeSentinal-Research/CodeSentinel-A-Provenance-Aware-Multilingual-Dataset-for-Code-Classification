#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char mobiles[100000][20], names[100000][50];
    for(int i=0; i<n; i++) scanf("%s %s", mobiles[i], names[i]);
    char q[20]; scanf("%s", q);
    int found = 0;
    for(int i=0; i<n; i++) if(strcmp(mobiles[i], q)==0) { printf("%s %s\n", mobiles[i], names[i]); found=1; break; }
    if(!found) printf("Customer Not Found\n");
    return 0;
}
