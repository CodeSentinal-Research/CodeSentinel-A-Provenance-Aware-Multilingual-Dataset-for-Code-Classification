#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char users[100000][50], emails[100000][50];
    for(int i=0; i<n; i++) scanf("%s %s", users[i], emails[i]);
    char q[50]; scanf("%s", q);
    int found = 0;
    for(int i=0; i<n; i++) if(strcmp(users[i], q)==0) { printf("%s\n", emails[i]); found=1; break; }
    if(!found) printf("User Not Found\n");
    return 0;
}
