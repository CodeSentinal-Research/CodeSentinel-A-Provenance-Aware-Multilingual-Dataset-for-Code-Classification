#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char users[100000][50];
    for(int i=0; i<n; i++) scanf("%s", users[i]);
    char prefix[50]; scanf("%s", prefix);
    int found = 0;
    for(int i=0; i<n; i++) if(strncmp(users[i], prefix, strlen(prefix))==0) { printf("%s\n", users[i]); found=1; }
    if(!found) printf("No Users Found\n");
    return 0;
}
