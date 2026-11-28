#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){int n;scanf("%d\n",&n);char*rows[]={"qwertyuiop","asdfghjkl","zxcvbnm"};char w[101];while(n--){fgets(w,sizeof(w),stdin);w[strcspn(w,"\n")]=0;int ok=0;for(int r=0;r<3&&!ok;r++){int all=1;for(int i=0;w[i]&&all;i++)if(!strchr(rows[r],(char)tolower((unsigned char)w[i])))all=0;if(all)ok=1;}if(ok)printf("%s\n",w);}};
