#include<stdio.h>
#include<string.h>
int main(){
    int n; scanf("%d\n",&n);
    char keys[1001][101], recs[1001][1001];
    for(int i=0;i<n;i++){
        fgets(recs[i],sizeof(recs[i]),stdin);
        recs[i][strcspn(recs[i],"\n")]=0;
        sscanf(recs[i],"%s",keys[i]);
    }
    char q[101]; fgets(q,sizeof(q),stdin); q[strcspn(q,"\n")]=0;
    for(int i=0;i<n;i++) if(strcmp(keys[i],q)==0){printf("%s\n",recs[i]);return 0;}
    printf("Record Not Found\n");
}
