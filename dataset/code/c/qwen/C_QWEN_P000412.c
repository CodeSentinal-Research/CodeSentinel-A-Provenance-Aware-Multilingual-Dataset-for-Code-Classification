#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    int n; scanf("%d", &n);
    char names[100000][50], phones[100000][20];
    for(int i=0; i<n; i++) scanf("%s %s", names[i], phones[i]);
    char q[50]; scanf("%s", q);
    int found = 0;
    for(int i=0; i<n; i++) {
        int match = 1;
        if(strlen(names[i]) != strlen(q)) match = 0;
        else {
            for(int j=0; q[j]; j++) {
                if(tolower(names[i][j]) != tolower(q[j])) { match = 0; break; }
            }
        }
        if(match) { printf("%s %s\n", names[i], phones[i]); found=1; }
    }
    if(!found) printf("No Contacts Found\n");
    return 0;
}
