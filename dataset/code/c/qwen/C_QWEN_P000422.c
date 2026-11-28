#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char names[100000][50]; double cgpa[100000]; int income[100000];
    for(int i=0; i<n; i++) scanf("%s %lf %d", names[i], &cgpa[i], &income[i]);
    double min_cgpa; int max_income; scanf("%lf %d", &min_cgpa, &max_income);
    int found = 0;
    for(int i=0; i<n; i++) if(cgpa[i] >= min_cgpa && income[i] <= max_income) { printf("%s %.2f %d\n", names[i], cgpa[i], income[i]); found=1; }
    if(!found) printf("No Eligible Students\n");
    return 0;
}
