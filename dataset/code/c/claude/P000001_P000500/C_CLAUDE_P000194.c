#include <stdlib.h>
int cmpI3(const void* a, const void* b) { return *(int*)a - *(int*)b; }
int* findIntersection(int* a, int m, int* b, int n, int* returnSize) {
    qsort(a, m, sizeof(int), cmpI3);
    qsort(b, n, sizeof(int), cmpI3);
    int* res=(int*)malloc((m<n?m:n)*sizeof(int));
    int i=0,j=0,k=0,prev=2147483647;
    while(i<m&&j<n) {
        if(a[i]==b[j]) { if(a[i]!=prev){res[k++]=a[i];prev=a[i];}i++;j++; }
        else if(a[i]<b[j]) i++;
        else j++;
    }
    *returnSize=k; return res;  // write through pointer
}
