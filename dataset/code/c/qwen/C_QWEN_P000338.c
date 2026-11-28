#include <stdio.h>
#include <string.h>
int main() {
    int n1, n2; scanf("%d", &n1);
    char w1[101][201], w2[101][201];
    for(int i=0; i<n1; i++) scanf("%s", w1[i]);
    scanf("%d", &n2);
    for(int i=0; i<n2; i++) scanf("%s", w2[i]);
    char s1[20001]="", s2[20001]="";
    for(int i=0; i<n1; i++) strcat(s1, w1[i]);
    for(int i=0; i<n2; i++) strcat(s2, w2[i]);
    printf("%s\n", strcmp(s1, s2)==0 ? "Yes" : "No");
    return 0;
}
