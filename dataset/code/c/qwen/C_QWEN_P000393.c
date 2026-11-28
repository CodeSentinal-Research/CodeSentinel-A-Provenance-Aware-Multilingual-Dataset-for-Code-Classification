#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char names[100000][50], phones[100000][20];
    for(int i=0; i<n; i++) scanf("%s %s", names[i], phones[i]);
    char prefix[50]; scanf("%s", prefix);
    int found = 0;
    for(int i=0; i<n; i++) if(strncmp(names[i], prefix, strlen(prefix))==0) { printf("%s %s\n", names[i], phones[i]); found=1; }
    if(!found) printf("No Contacts Found\n");
    return 0;
}
