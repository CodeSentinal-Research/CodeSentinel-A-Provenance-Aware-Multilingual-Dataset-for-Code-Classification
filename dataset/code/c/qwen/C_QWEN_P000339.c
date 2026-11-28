#include <stdio.h>
#include <string.h>
int main() {
    char s[1001]; scanf("%s", s);
    int n = strlen(s), half = n/2, v1=0, v2=0;
    for(int i=0; i<half; i++) { char c=s[i]|32; if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') v1++; }
    for(int i=half; i<n; i++) { char c=s[i]|32; if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') v2++; }
    printf("%s\n", v1==v2 ? "Yes" : "No");
    return 0;
}
