#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char titles[100000][50]; int years[100000];
    for(int i=0; i<n; i++) scanf("%s %d", titles[i], &years[i]);
    int q; scanf("%d", &q);
    int found = 0;
    for(int i=0; i<n; i++) if(years[i]>q) { printf("%s %d\n", titles[i], years[i]); found=1; }
    if(!found) printf("No Books Found\n");
    return 0;
}
