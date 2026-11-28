#include <stdio.h>
int main(){
    int n; scanf("%d",&n);
    int a[n],b[n],c[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    for(int i=0;i<n;i++) scanf("%d",&c[i]);
    int i=0,j=0,k=0,first=1;
    while(i<n && j<n && k<n){
        if(a[i]==b[j] && b[j]==c[k]){
            if(!first) printf(" ");
            printf("%d",a[i]);
            first=0; i++;j++;k++;
        } else if(a[i]<=b[j] && a[i]<=c[k]) i++;
        else if(b[j]<=a[i] && b[j]<=c[k]) j++;
        else k++;
    }
    printf("\n");
}
