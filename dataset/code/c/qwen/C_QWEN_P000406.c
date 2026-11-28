#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char titles[100000][50], genres[100000][50];
    for(int i=0; i<n; i++) scanf("%s %s", titles[i], genres[i]);
    char q[50]; scanf("%s", q);
    int found = 0;
    for(int i=0; i<n; i++) if(strcmp(genres[i], q)==0) { printf("%s %s\n", titles[i], genres[i]); found=1; }
    if(!found) printf("No Movies Found\n");
    return 0;
}
