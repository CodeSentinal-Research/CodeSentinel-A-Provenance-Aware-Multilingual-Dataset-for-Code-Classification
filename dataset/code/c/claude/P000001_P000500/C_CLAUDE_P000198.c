#include <stdbool.h>
#include <stdlib.h>
int cmpCC(const void* a, const void* b) { return *(int*)a - *(int*)b; }
bool containsContiguous(int* nums, int n) {
    if (n == 0) return true;
    int* tmp = (int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++) tmp[i]=nums[i];
    qsort(tmp,n,sizeof(int),cmpCC);
    bool ok = true;
    for (int i=1;i<n;i++) if(tmp[i]!=tmp[i-1]+1){ok=false;break;}
    free(tmp); return ok;
}
