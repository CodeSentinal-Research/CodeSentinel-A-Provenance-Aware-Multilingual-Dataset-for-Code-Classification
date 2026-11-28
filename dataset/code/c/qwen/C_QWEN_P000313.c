#include <stdio.h>
#include <string.h>
int main() {
    char s[101]; scanf("%s", s);
    int i=0, n=strlen(s), seen_digit=0, seen_dot=0, seen_e=0;
    if(s[i]=='+' || s[i]=='-') i++;
    while(i<n && s[i]>='0' && s[i]<='9') { seen_digit=1; i++; }
    if(i<n && s[i]=='.') {
        seen_dot=1; i++;
        while(i<n && s[i]>='0' && s[i]<='9') { seen_digit=1; i++; }
    }
    if(i<n && (s[i]=='e' || s[i]=='E')) {
        seen_e=1; i++;
        if(!seen_digit) { printf("Invalid\n"); return 0; }
        seen_digit=0;
        if(i<n && (s[i]=='+' || s[i]=='-')) i++;
        while(i<n && s[i]>='0' && s[i]<='9') { seen_digit=1; i++; }
    }
    printf("%s\n", (seen_digit && i==n) ? "Valid" : "Invalid");
    return 0;
}
