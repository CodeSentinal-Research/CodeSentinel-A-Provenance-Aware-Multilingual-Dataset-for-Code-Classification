#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char emails[100000][50];
    for(int i=0; i<n; i++) scanf("%s", emails[i]);
    int count[100000] = {0};
    for(int i=0; i<n; i++) for(int j=i+1; j<n; j++) if(strcmp(emails[i], emails[j])==0) count[i]++;
    int found = 0;
    for(int i=0; i<n; i++) if(count[i] > 0) { printf("%s\n", emails[i]); found=1; }
    if(!found) printf("No Duplicates Found\n");
    return 0;
}
