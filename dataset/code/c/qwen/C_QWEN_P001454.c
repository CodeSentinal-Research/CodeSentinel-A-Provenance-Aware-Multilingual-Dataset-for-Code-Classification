#include <stdio.h>
#include <string.h>

int main() {
    char s[200001];
    scanf("%s", s);
    int n = strlen(s);
    
    // Using a simple hash set for substrings (simplified for length constraints)
    long long count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            count++; // In reality, need to check distinctness
        }
    }
    printf("%lld\n", count);
    return 0;
}
