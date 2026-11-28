#include <stdio.h>
#include <string.h>
int main() {
    char s[200001]; scanf("%s", s);
    int n = strlen(s);
    int imbalance = 0, max_imbalance = 0;
    for(int i=0; i<n; i++) {
        if(s[i] == '[') imbalance++;
        else imbalance--;
        if(imbalance < 0 && -imbalance > max_imbalance) max_imbalance = -imbalance;
    }
    printf("%d\n", (max_imbalance + 1) / 2);
    return 0;
}
