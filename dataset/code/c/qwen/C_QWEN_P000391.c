#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char names[100000][50]; double gpas[100000];
    for(int i=0; i<n; i++) scanf("%s %lf", names[i], &gpas[i]);
    double min_gpa; scanf("%lf", &min_gpa);
    int found = 0;
    for(int i=0; i<n; i++) if(gpas[i]>=min_gpa) { printf("%s %.2f\n", names[i], gpas[i]); found=1; }
    if(!found) printf("No Students Found\n");
    return 0;
}
