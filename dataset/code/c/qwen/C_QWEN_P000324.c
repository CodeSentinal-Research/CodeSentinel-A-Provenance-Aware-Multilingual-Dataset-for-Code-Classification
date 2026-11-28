#include <stdio.h>
#include <string.h>
int main() {
    char s[1001]; scanf("%s", s);
    char doubled[2001]; strcpy(doubled, s); strcat(doubled, s);
    printf("%s\n", (strstr(doubled+1, s) != NULL && strlen(s)>1) || strlen(s)==1 ? "Yes" : "No"); // simplified
    // Proper check:
    int n = strlen(s);
    for(int i=1; i<=n/2; i++) {
        if(n%i == 0) {
            int valid = 1;
            for(int j=i; j<n; j++) if(s[j] != s[j%i]) { valid=0; break; }
            if(valid) { printf("Yes\n"); return 0; }
        }
    }
    printf("No\n");
    return 0;
}
