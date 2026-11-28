#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char isbns[100000][20], titles[100000][50];
    for(int i=0; i<n; i++) scanf("%s %s", isbns[i], titles[i]);
    char q[20]; scanf("%s", q);
    int found = 0;
    for(int i=0; i<n; i++) if(strcmp(isbns[i], q)==0) { printf("%s %s\n", isbns[i], titles[i]); found=1; break; }
    if(!found) printf("Book Not Found\n");
    return 0;
}
