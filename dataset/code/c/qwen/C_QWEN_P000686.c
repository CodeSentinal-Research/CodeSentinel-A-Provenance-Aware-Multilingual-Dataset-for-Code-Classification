#include <stdio.h>
#include <string.h>
void rev(char *s, int l, int r) { if(l>=r) return; char t=s[l]; s[l]=s[r]; s[r]=t; rev(s, l+1, r-1); }
int main() { char s[1001]; scanf("%s", s); rev(s, 0, strlen(s)-1); printf("%s\n", s); return 0; }
