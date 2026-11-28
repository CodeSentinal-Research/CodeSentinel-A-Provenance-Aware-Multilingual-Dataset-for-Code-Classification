#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char titles[100000][50], authors[100000][50], genres[100000][50];
    for(int i=0; i<n; i++) scanf("%s %s %s", titles[i], authors[i], genres[i]);
    char author[50], genre[50]; scanf("%s %s", author, genre);
    int found = 0;
    for(int i=0; i<n; i++) if(strcmp(authors[i], author)==0 && strcmp(genres[i], genre)==0) { printf("%s %s %s\n", titles[i], authors[i], genres[i]); found=1; }
    if(!found) printf("No Books Found\n");
    return 0;
}
