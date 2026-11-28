#include <stdio.h>
int main() {
    int num; scanf("%d", &num);
    int val[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    char *sym[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    char res[100] = "";
    for(int i=0; i<13; i++) {
        while(num >= val[i]) { strcat(res, sym[i]); num -= val[i]; }
    }
    printf("%s\n", res);
    return 0;
}
