#include <stdio.h>
int main(){
    int n; scanf("%d",&n);
    int A[n][n];
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&A[i][j]);
    /* Layer-by-layer clockwise rotation */
    for(int layer=0;layer<n/2;layer++){
        int first=layer,last=n-1-layer;
        for(int i=first;i<last;i++){
            int off=i-first;
            int top=A[first][i];
            A[first][i]=A[last-off][first];
            A[last-off][first]=A[last][last-off];
            A[last][last-off]=A[first+off][last];
            A[first+off][last]=top;
        }
    }
    for(int i=0;i<n;i++){for(int j=0;j<n;j++) printf("%d%c",A[i][j],j<n-1?' ':'\n');}
}
