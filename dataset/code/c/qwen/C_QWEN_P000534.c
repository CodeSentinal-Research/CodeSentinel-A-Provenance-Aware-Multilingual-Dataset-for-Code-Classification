#include <stdio.h>
#include <string.h>
int main() {
    char s[10001]; scanf("%s", s);
    int r_queue[10001], d_queue[10001], r_front=0, r_rear=0, d_front=0, d_rear=0;
    for(int i=0; s[i]; i++) {
        if(s[i]=='R') r_queue[r_rear++]=i; else d_queue[d_rear++]=i;
    }
    while(r_front<r_rear && d_front<d_rear) {
        if(r_queue[r_front]<d_queue[d_front]) { d_front++; r_queue[r_rear++]=r_queue[r_front]+strlen(s); r_front++; }
        else { r_front++; d_queue[d_rear++]=d_queue[d_front]+strlen(s); d_front++; }
    }
    printf("%s\n", r_front<r_rear ? "Radiant" : "Dire");
    return 0;
}
