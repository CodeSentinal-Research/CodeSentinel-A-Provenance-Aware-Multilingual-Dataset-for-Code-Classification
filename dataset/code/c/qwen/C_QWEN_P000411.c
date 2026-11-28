#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char records[100000][101];
    for(int i=0; i<n; i++) scanf("%s", records[i]);
    char keyword[50]; scanf("%s", keyword);
    int found = 0;
    for(int i=0; i<n; i++) if(strstr(records[i], keyword)) { printf("%s\n", records[i]); found=1; }
    if(!found) printf("No Records Found\n");
    return 0;
}
