#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];
    scanf("%s", s);
    int n_dict;
    scanf("%d", &n_dict);
    char dict[n_dict][101];
    for (int i = 0; i < n_dict; i++) scanf("%s", dict[i]);
    
    int max_len = -1;
    char ans[101] = "";
    
    for (int i = 0; i < n_dict; i++) {
        int si = 0, di = 0;
        while (s[si] && dict[i][di]) {
            if (s[si] == dict[i][di]) di++;
            si++;
        }
        if (dict[i][di] == '\0') {
            int len = strlen(dict[i]);
            if (len > max_len || (len == max_len && strcmp(dict[i], ans) < 0)) {
                max_len = len;
                strcpy(ans, dict[i]);
            }
        }
    }
    printf("%s\n", max_len == -1 ? "" : ans);
    return 0;
}
