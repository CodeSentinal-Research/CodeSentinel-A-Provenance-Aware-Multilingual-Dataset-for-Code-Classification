#include<stdio.h>
#include<string.h>
int main(){
    char s[1001];fgets(s,sizeof(s),stdin);s[strcspn(s,"\n")]=0;int n=strlen(s);
    int wn;scanf("%d\n",&wn);
    int bold[1001]={0};
    for(int k=0;k<wn;k++){char w[101];fgets(w,sizeof(w),stdin);w[strcspn(w,"\n")]=0;int wl=strlen(w);char*p=s;while((p=strstr(p,w))){int si=p-s;for(int i=si;i<si+wl;i++)bold[i]=1;p++;}}
    for(int i=0;i<n;){
        if(bold[i]&&(i==0||!bold[i-1]))printf("<b>");
        printf("%c",s[i]);
        if(bold[i]&&(i==n-1||!bold[i+1]))printf("</b>");
        i++;
    }
    printf("\n");
}
