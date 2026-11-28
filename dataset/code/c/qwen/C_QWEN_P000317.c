#include <stdio.h>
#include <string.h>
int main() {
    char p[101], s[1001]; scanf("%s", p); fgets(s, 1001, stdin);
    char words[100][101]; int w_idx = 0;
    char *token = strtok(s, " \n");
    while(token) { strcpy(words[w_idx++], token); token = strtok(NULL, " \n"); }
    if(strlen(p) != w_idx) { printf("No\n"); return 0; }
    char map_p[256][101]; char map_w[100][101]; int used_w[100]={0};
    for(int i=0; p[i]; i++) {
        if(map_p[p[i]][0] && strcmp(map_p[p[i]], words[i]) != 0) { printf("No\n"); return 0; }
        strcpy(map_p[p[i]], words[i]);
    }
    printf("Yes\n");
    return 0;
}
