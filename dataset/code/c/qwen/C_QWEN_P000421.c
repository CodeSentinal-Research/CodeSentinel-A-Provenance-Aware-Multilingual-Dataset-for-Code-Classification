#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char members[100000][50]; int expiry[100000];
    for(int i=0; i<n; i++) scanf("%s %d", members[i], &expiry[i]);
    int current_date; scanf("%d", &current_date);
    int found = 0;
    for(int i=0; i<n; i++) if(expiry[i] < current_date) { printf("%s %d\n", members[i], expiry[i]); found=1; }
    if(!found) printf("No Expired Memberships\n");
    return 0;
}
