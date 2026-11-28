#include<stdio.h>
#include<string.h>
char s[1001];char*words[1001];int wn;
void bt(int si,char*path){
    int n=strlen(s);
    if(si==n){printf("%s\n",path);return;}
    char tmp[5000];strcpy(tmp,path);int pl=strlen(path);
    for(int k=0;k<wn;k++){
        int wl=strlen(words[k]);
        if(si+wl>n||strncmp(s+si,words[k],wl)!=0)continue;
        if(pl>0){strcpy(path+pl," ");strcpy(path+pl+1,words[k]);}
        else strcpy(path,words[k]);
        bt(si+wl,path);
        strcpy(path,tmp);
    }
}
int main(){
    char line[10001];
    scanf("%s\n",s);fgets(line,sizeof(line),stdin);
    char*p=strtok(line," \n");while(p){words[wn++]=p;p=strtok(NULL," \n");}
    char path[5000]="";bt(0,path);
}
