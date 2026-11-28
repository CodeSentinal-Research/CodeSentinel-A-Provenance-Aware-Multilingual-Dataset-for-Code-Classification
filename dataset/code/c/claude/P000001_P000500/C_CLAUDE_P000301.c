#include<stdio.h>
#include<string.h>
char s[20];int n;
void bt(int si,char*res,int dots){
    if(dots==4){if(si==n)printf("%s\n",res);return;}
    char tmp[20];strcpy(tmp,res);int rl=strlen(res);
    for(int l=1;l<=3&&si+l<=n;l++){
        char seg[5];strncpy(seg,s+si,l);seg[l]=0;
        if(seg[0]=='0'&&l>1)break;
        if(atoi(seg)>255)break;
        if(rl>0)res[rl]='.';
        strcpy(res+rl+(rl>0?1:0),seg);
        bt(si+l,res,dots+1);
        strcpy(res,tmp);
    }
}
int main(){scanf("%s",s);n=strlen(s);char res[30]="";bt(0,res,0);}
