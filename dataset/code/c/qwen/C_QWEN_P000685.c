#include <stdio.h>
#include <string.h>
int pal(char *s, int l, int r) { if(l>=r) return 1; if(s[l]!=s[r]) return 0; return pal(s, l+1, r-1); }
int main() { char s[1001]; scanf("%s", s); printf("%s\n", pal(s, 0, strlen(s)-1)?"true":"false"); return 0; }
