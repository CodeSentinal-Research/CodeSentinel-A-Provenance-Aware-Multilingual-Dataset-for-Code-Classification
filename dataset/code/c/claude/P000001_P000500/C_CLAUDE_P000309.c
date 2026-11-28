#include<stdio.h>
#include<string.h>
int main(){
    char a[205],b[205];scanf("%s %s",a,b);
    int m=strlen(a),n=strlen(b),pos[410]={0};
    for(int i=m-1;i>=0;i--)for(int j=n-1;j>=0;j--){
        int mul=(a[i]-'0')*(b[j]-'0'),p1=i+j,p2=i+j+1,tot=mul+pos[p2];
        pos[p2]=tot%10;pos[p1]+=tot/10;
    }
    int start=0;while(start<m+n-1&&!pos[start])start++;
    for(int i=start;i<m+n;i++)printf("%d",pos[i]);printf("\n");
}
