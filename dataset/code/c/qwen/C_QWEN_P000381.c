#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char names[100000][50], phones[100000][20];
    for(int i=0; i<n; i++) scanf("%s %s", names[i], phones[i]);
    char q[50]; scanf("%s", q);
    int found = 0;
    for(int i=0; i<n; i++) if(strcmp(names[i], q)==0) { printf("%s %s\n", names[i], phones[i]); found=1; break; }
    if(!found) printf("Contact Not Found\n");
    return 0;
}
