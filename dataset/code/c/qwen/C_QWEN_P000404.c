#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char names[100000][50], specs[100000][50];
    for(int i=0; i<n; i++) scanf("%s %s", names[i], specs[i]);
    char q[50]; scanf("%s", q);
    int found = 0;
    for(int i=0; i<n; i++) if(strcmp(specs[i], q)==0) { printf("%s %s\n", names[i], specs[i]); found=1; }
    if(!found) printf("No Doctors Found\n");
    return 0;
}
