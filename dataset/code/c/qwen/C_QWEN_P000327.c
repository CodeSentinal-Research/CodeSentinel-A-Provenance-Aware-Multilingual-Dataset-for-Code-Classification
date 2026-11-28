#include <stdio.h>
#include <string.h>
int main() {
    char note[1001], mag[1001]; scanf("%s %s", note, mag);
    int count[256] = {0};
    for(int i=0; mag[i]; i++) count[mag[i]]++;
    for(int i=0; note[i]; i++) {
        if(count[note[i]] > 0) count[note[i]]--;
        else { printf("No\n"); return 0; }
    }
    printf("Yes\n");
    return 0;
}
