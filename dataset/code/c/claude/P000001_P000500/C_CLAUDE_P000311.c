#include<stdio.h>
#include<string.h>
int main(){
    char a[305],b[305];scanf("%s %s",a,b);
    int la=strlen(a)-1,lb=strlen(b)-1,carry=0;
    char res[310];int ri=0;
    while(la>=0||lb>=0||carry){
        int s=carry;
        if(la>=0)s+=a[la--]-'0';
        if(lb>=0)s+=b[lb--]-'0';
        res[ri++]='0'+s%10;carry=s/10;
    }
    res[ri]=0;
    for(int i=0;i<ri/2;i++){char t=res[i];res[i]=res[ri-1-i];res[ri-1-i]=t;}
    printf("%s\n",res);
}
