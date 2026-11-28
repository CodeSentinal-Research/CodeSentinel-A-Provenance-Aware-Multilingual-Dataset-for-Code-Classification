#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char courses[100000][50], instructors[100000][50];
    for(int i=0; i<n; i++) scanf("%s %s", courses[i], instructors[i]);
    char q[50]; scanf("%s", q);
    int found = 0;
    for(int i=0; i<n; i++) if(strcmp(instructors[i], q)==0) { printf("%s %s\n", courses[i], instructors[i]); found=1; }
    if(!found) printf("No Courses Found\n");
    return 0;
}
