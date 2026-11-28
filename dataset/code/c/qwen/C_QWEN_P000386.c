#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    long long accs[100000]; char details[100000][50];
    for(int i=0; i<n; i++) scanf("%lld %s", &accs[i], details[i]);
    long long q; scanf("%lld", &q);
    int found = 0;
    for(int i=0; i<n; i++) if(accs[i]==q) { printf("%lld %s\n", accs[i], details[i]); found=1; break; }
    if(!found) printf("Account Not Found\n");
    return 0;
}
