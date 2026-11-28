#include <stdio.h>
#include <string.h>
int main() {
    char s[1001], t[1001]; scanf("%s %s", s, t);
    if(strlen(s) != strlen(t)) { printf("No\n"); return 0; }
    int map_s[256]={0}, map_t[256]={0};
    for(int i=0; s[i]; i++) {
        if(map_s[s[i]] && map_s[s[i]] != t[i]) { printf("No\n"); return 0; }
        if(map_t[t[i]] && map_t[t[i]] != s[i]) { printf("No\n"); return 0; }
        map_s[s[i]] = t[i]; map_t[t[i]] = s[i];
    }
    printf("Yes\n");
    return 0;
}
