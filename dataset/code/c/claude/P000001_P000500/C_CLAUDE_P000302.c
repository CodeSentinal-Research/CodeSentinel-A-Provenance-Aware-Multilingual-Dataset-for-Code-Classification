#include<stdio.h>
#include<string.h>
int main(){
    char s[1001],line[10001];
    scanf("%s\n",s);fgets(line,sizeof(line),stdin);
    int n=strlen(s),dp[n+1];for(int i=0;i<=n;i++)dp[i]=0;dp[0]=1;
    // tokenize words
    char*words[1001];int wn=0;char*p=strtok(line," \n");
    while(p){words[wn++]=p;p=strtok(NULL," \n");}
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            if(!dp[j])continue;
            for(int k=0;k<wn;k++){
                int wl=strlen(words[k]);
                if(i-j==wl&&strncmp(s+j,words[k],wl)==0){dp[i]=1;break;}
            }
            if(dp[i])break;
        }
    }
    printf("%s\n",dp[n]?"Yes":"No");
}
