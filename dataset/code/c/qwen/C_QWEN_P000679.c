#include <stdio.h>
void print(int n, int i) { if(i>n) return; printf("%d ", i); print(n, i+1); }
int main() { int n; scanf("%d", &n); print(n, 1); printf("\n"); return 0; }
