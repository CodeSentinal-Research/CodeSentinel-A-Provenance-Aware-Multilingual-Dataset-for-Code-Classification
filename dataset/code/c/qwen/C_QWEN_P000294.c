#include <stdio.h>
#include <string.h>
int main() {
    char s[1001]; int rows; scanf("%s %d", s, &rows);
    if(rows==1) { printf("%s\n", s); return 0; }
    char res[1001] = "";
    for(int i=0; i<rows; i++) {
        int idx=i, step1=2*(rows-1-i), step2=2*i, dir=1;
        while(idx < strlen(s)) {
            res[strlen(res)] = s[idx]; res[strlen(res)+1]='\0';
            int step = dir ? step1 : step2;
            if(step==0) step = dir ? step2 : step1;
            idx += step;
            dir = !dir;
        }
    }
    printf("%s\n", res);
    return 0;
}
