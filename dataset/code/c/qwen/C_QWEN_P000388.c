#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char passports[100000][20], details[100000][50];
    for(int i=0; i<n; i++) scanf("%s %s", passports[i], details[i]);
    char q[20]; scanf("%s", q);
    int found = 0;
    for(int i=0; i<n; i++) if(strcmp(passports[i], q)==0) { printf("%s %s\n", passports[i], details[i]); found=1; break; }
    if(!found) printf("Passport Not Found\n");
    return 0;
}
