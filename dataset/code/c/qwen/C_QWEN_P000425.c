#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char accs[100000][20]; int last_txn[100000];
    for(int i=0; i<n; i++) scanf("%s %d", accs[i], &last_txn[i]);
    int months; scanf("%d", &months);
    int found = 0;
    for(int i=0; i<n; i++) if(last_txn[i] < months) { printf("%s %d\n", accs[i], last_txn[i]); found=1; }
    if(!found) printf("No Inactive Accounts\n");
    return 0;
}
