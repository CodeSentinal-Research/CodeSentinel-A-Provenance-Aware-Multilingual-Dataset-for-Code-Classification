#include<stdio.h>
#include<string.h>
int main(){
    char pat[101],line[10001];scanf("%s\n",pat);fgets(line,sizeof(line),stdin);
    char*words[101];int wn=0;char*p=strtok(line," \n");while(p){words[wn++]=p;p=strtok(NULL," \n");}
    if(strlen(pat)!=wn){printf("No\n");return 0;}
    char*mp[256]={NULL};char mw_key[101][101];char mw_val[101];int mwn=0;
    for(int i=0;pat[i];i++){
        int c=(unsigned char)pat[i];
        if(!mp[c])mp[c]=words[i];
        if(strcmp(mp[c],words[i])!=0){printf("No\n");return 0;}
        // check reverse
        char found=0;for(int k=0;k<mwn;k++)if(strcmp(mw_key[k],words[i])==0){if(mw_val[k]!=pat[i]){printf("No\n");return 0;}found=1;break;}
        if(!found){strcpy(mw_key[mwn],words[i]);mw_val[mwn++]=pat[i];}
    }
    printf("Yes\n");
}
