#include<stdio.h>
#include<string.h>
int main(){
    int n; scanf("%d\n",&n);
    char recs[1001][1001];
    for(int i=0;i<n;i++){fgets(recs[i],sizeof(recs[i]),stdin);recs[i][strcspn(recs[i],"\n")]=0;}
    char cutoff[20]; fgets(cutoff,sizeof(cutoff),stdin); cutoff[strcspn(cutoff,"\n")]=0;
    int found=0;
    for(int i=0;i<n;i++){
        char tmp[1001]; strcpy(tmp,recs[i]);
        char*tok=strtok(tmp," "); char*last=NULL;
        while(tok){last=tok;tok=strtok(NULL," ");}
        if(last && strcmp(last,cutoff)<0){printf("%s\n",recs[i]);found=1;}
    }
    if(!found) printf("No Employees Found\n");
}
