#include <stdio.h>
#include <string.h>

int main() {
    int n1, n2;
    scanf("%d", &n1);
    char words1[n1][101];
    for (int i = 0; i < n1; i++) scanf("%s", words1[i]);
    
    scanf("%d", &n2);
    char words2[n2][101];
    for (int i = 0; i < n2; i++) scanf("%s", words2[i]);
    
    int count1[100001] = {0}, count2[100001] = {0};
    for (int i = 0; i < n1; i++) count1[i] = 1; // simplified
    // Actually count frequencies
    int freq1[100001] = {0}, freq2[100001] = {0};
    for (int i = 0; i < n1; i++) freq1[i]++;
    for (int i = 0; i < n2; i++) freq2[i]++;
    
    int count = 0;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (strcmp(words1[i], words2[j]) == 0) {
                // check if appears exactly once in both
                int c1 = 0, c2 = 0;
                for(int k=0; k<n1; k++) if(strcmp(words1[k], words1[i])==0) c1++;
                for(int k=0; k<n2; k++) if(strcmp(words2[k], words2[j])==0) c2++;
                if(c1==1 && c2==1) count++;
                break;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
