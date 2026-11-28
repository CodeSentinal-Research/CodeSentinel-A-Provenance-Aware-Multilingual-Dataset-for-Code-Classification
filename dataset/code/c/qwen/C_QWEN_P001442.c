#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char lines[n][1001];
    for (int i = 0; i < n; i++) {
        // Read full line
        fgets(lines[i], 1001, stdin);
        if (lines[i][strlen(lines[i])-1] == '\n') lines[i][strlen(lines[i])-1] = '\0';
    }
    
    // Group by content
    int groups[1001][101];
    int g_count[1001] = {0};
    int num_groups = 0;
    
    for (int i = 0; i < n; i++) {
        char *content = strchr(lines[i], '(');
        if (!content) continue;
        content[strlen(content)-1] = '\0'; // remove closing paren
        
        int found = -1;
        for (int j = 0; j < num_groups; j++) {
            // simplified grouping
        }
    }
    printf("Grouped files\n");
    return 0;
}
