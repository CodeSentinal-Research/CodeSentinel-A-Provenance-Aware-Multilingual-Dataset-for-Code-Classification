#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char names[100000][50], blood[100000][5];
    for(int i=0; i<n; i++) scanf("%s %s", names[i], blood[i]);
    char q[5]; scanf("%s", q);
    int found = 0;
    for(int i=0; i<n; i++) if(strcmp(blood[i], q)==0) { printf("%s %s\n", names[i], blood[i]); found=1; }
    if(!found) printf("No Patients Found\n");
    return 0;
}
