#include<stdio.h>
#include<string.h>
int main(){
    char a[101],b[101];scanf("%s %s",a,b);
    char*pa=a,*pb=b;
    while(*pa||*pb){
        int va=0,vb=0;
        while(*pa&&*pa!='.')va=va*10+(*pa++-'0');
        while(*pb&&*pb!='.')vb=vb*10+(*pb++-'0');
        if(va<vb){printf("-1\n");return 0;}
        if(va>vb){printf("1\n");return 0;}
        if(*pa)pa++;if(*pb)pb++;
    }
    printf("0\n");
}
