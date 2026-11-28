#include<stdio.h>
#include<string.h>
int main(){
    int n; scanf("%d\n",&n);
    char recs[1001][1001];
    for(int i=0;i<n;i++){fgets(recs[i],sizeof(recs[i]),stdin);recs[i][strcspn(recs[i],"\n")]=0;}
    char dept[101]; fgets(dept,sizeof(dept),stdin); dept[strcspn(dept,"\n")]=0;
    int found=0;
    for(int i=0;i<n;i++){
        char tmp[1001]; strcpy(tmp,recs[i]);
        strtok(tmp," "); char*f=strtok(NULL," ");
        if(f && strcmp(f,dept)==0){printf("%s\n",recs[i]);found=1;}
    }
    if(!found) printf("No Records Found\n");
}
