#include <stdio.h>
int main() {
    int n; scanf("%d", &n);
    int arr[n], pos[n], neg[n], p=0, ng=0;
    for(int i=0; i<n; i++) { scanf("%d", &arr[i]); if(arr[i] >= 0) pos[p++] = arr[i]; else neg[ng++] = arr[i]; }
    int i=0, j=0, k=0;
    while(i<p && j<ng) { arr[k++] = pos[i++]; arr[k++] = neg[j++]; }
    while(i<p) arr[k++] = pos[i++];
    while(j<ng) arr[k++] = neg[j++];
    for(int i=0; i<n; i++) printf("%d%c", arr[i], i==n-1?'\n':' ');
    return 0;
}
