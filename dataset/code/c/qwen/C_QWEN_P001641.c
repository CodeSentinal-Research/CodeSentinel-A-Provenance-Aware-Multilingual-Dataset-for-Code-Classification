#include <stdio.h>

int isSubtree(int *main, int *sub, int i, int j, int n1, int n2) {
    if(j >= n2 || sub[j] == -1) return 1;
    if(i >= n1 || main[i] == -1) return 0;
    if(main[i] != sub[j]) return 0;
    return isSubtree(main, sub, 2*i+1, 2*j+1, n1, n2) && isSubtree(main, sub, 2*i+2, 2*j+2, n1, n2);
}

int check(int *main, int *sub, int i, int n1, int n2) {
    if(i >= n1) return 0;
    if(main[i] == sub[0] && isSubtree(main, sub, i, 0, n1, n2)) return 1;
    return check(main, sub, 2*i+1, n1, n2) || check(main, sub, 2*i+2, n1, n2);
}

int main() {
    int n1, n2; scanf("%d", &n1);
    int main[n1]; for(int i=0; i<n1; i++) scanf("%d", &main[i]);
    scanf("%d", &n2);
    int sub[n2]; for(int i=0; i<n2; i++) scanf("%d", &sub[i]);
    printf("%s\n", check(main, sub, 0, n1, n2) ? "YES" : "NO");
    return 0;
}
