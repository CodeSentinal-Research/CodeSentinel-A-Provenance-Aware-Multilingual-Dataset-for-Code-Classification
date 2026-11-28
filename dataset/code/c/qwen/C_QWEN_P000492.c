#include <stdio.h>
#include <string.h>
int main() {
    char path[3001]; scanf("%s", path);
    char stack[1000][1001]; int top=-1;
    char *token = strtok(path, "/");
    while(token) {
        if(strcmp(token, "..")==0) { if(top>=0) top--; }
        else if(strcmp(token, ".")!=0) { strcpy(stack[++top], token); }
        token = strtok(NULL, "/");
    }
    if(top==-1) printf("/\n");
    else { for(int i=0; i<=top; i++) printf("/%s", stack[i]); printf("\n"); }
    return 0;
}
