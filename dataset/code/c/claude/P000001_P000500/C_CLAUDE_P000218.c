#include <stdio.h>
int main(){
    int n; scanf("%d",&n);
    int a[n]; for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int c1=0,c2=0,e1=0,e2=1;
    for(int i=0;i<n;i++){
        if(a[i]==e1) c1++;
        else if(a[i]==e2) c2++;
        else if(!c1){e1=a[i];c1=1;}
        else if(!c2){e2=a[i];c2=1;}
        else{c1--;c2--;}
    }
    c1=c2=0;
    for(int i=0;i<n;i++){if(a[i]==e1)c1++;else if(a[i]==e2)c2++;}
    int thresh=n/3,first=1;
    if(c1>thresh){printf("%d",e1);first=0;}
    if(c2>thresh){if(!first)printf(" ");printf("%d",e2);}
    printf("\n");
}
