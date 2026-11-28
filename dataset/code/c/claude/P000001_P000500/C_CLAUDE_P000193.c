#include <stdlib.h>
int cmpU2(const void* a, const void* b) { return *(int*)a - *(int*)b; }
int* findUnion(int* a, int m, int* b, int n, int* returnSize) {
    int* tmp = (int*)malloc((m+n)*sizeof(int));
    for (int i=0;i<m;i++) tmp[i]=a[i];
    for (int i=0;i<n;i++) tmp[m+i]=b[i];
    qsort(tmp, m+n, sizeof(int), cmpU2);
    int* res=(int*)malloc((m+n)*sizeof(int));
    int k=0;
    for (int i=0;i<m+n;i++) if(k==0||res[k-1]!=tmp[i]) res[k++]=tmp[i];
    free(tmp); *returnSize=k; return res;
}
