#include <stdio.h>
#include <string.h>
int main() {
    char s[200001]; scanf("%s", s);
    int count[256] = {0};
    for(int i=0; s[i]; i++) count[s[i]]++;
    int freq[200001] = {0};
    for(int i=0; i<256; i++) if(count[i]) freq[count[i]]++;
    int del = 0;
    for(int i=200000; i>0; i--) {
        while(freq[i] > 1) { freq[i]--; freq[i-1]++; del++; }
    }
    printf("%d\n", del);
    return 0;
}
