#include <stdio.h>
int main() {
    int a, b, c; scanf("%d%d%d", &a, &b, &c);
    char res[300001]; int idx = 0;
    int arr[3] = {a, b, c};
    char chars[3] = {'a', 'b', 'c'};
    while(idx < a+b+c) {
        int max_idx = 0;
        for(int i=1; i<3; i++) if(arr[i] > arr[max_idx]) max_idx = i;
        if(idx >= 2 && res[idx-1] == chars[max_idx] && res[idx-2] == chars[max_idx]) {
            int second = 0;
            for(int i=1; i<3; i++) if(arr[i] > arr[second] && i != max_idx) second = i;
            max_idx = second;
        }
        res[idx++] = chars[max_idx];
        arr[max_idx]--;
    }
    res[idx] = '\0';
    printf("%s\n", res);
    return 0;
}
