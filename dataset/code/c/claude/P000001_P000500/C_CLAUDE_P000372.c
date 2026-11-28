#include<stdio.h>
#include<string.h>
int main(){
    int n; scanf("%d\n",&n);
    char recs[1001][1001];
    for(int i=0;i<n;i++){
        fgets(recs[i],sizeof(recs[i]),stdin);
        recs[i][strcspn(recs[i],"\n")]=0;
    }
    char roll[101]; fgets(roll,sizeof(roll),stdin); roll[strcspn(roll,"\n")]=0;
    for(int i=0;i<n;i++){
        char tmp[1001]; strcpy(tmp,recs[i]);
        char*tok=strtok(tmp," ");
        if(tok && strcmp(tok,roll)==0){printf("%s\n",recs[i]);return 0;}
    }
    printf("Record Not Found\n");
}
